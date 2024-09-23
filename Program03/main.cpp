#include <iostream>
#include <iomanip>
#include <vector>
#include "Customer.h"
#include "Order.h"

void InputBuffer() {
    std::string buffer;
    std::getline(std::cin, buffer);
}

void getTime(int &month, int &day, int &year, int &hour, int &minute) {//A getter for the current date and time

    time_t epochSeconds = time(nullptr);

    tm* tm_ptr = localtime(&epochSeconds);

    month = tm_ptr->tm_mon +1;
    day = tm_ptr->tm_mday;
    year = tm_ptr->tm_year + 1900;
    hour = tm_ptr->tm_hour;
    minute = tm_ptr->tm_min;


    int twelveHour = (hour % 12 == 0) ? 12 : hour % 12;
    std::ostringstream time;
    time << twelveHour << ":" << minute << " " << (hour >= 12 ? "PM" : "AM");

    std::cout << "It is currently " << month << "/" << day << "/" << year;
    std::cout << " At " << time.str() << std::endl;
}


void outputReport(std::vector<Customer> customersVector, //A function that outputs
                                                        //and lists, customers, orders and products with member data
    std::vector<Order> ordersVector, std:: vector<Product> productsVector) {
    for(Customer x : customersVector) {
        std::cout<<"Customer ID:"<<x.getcustID()<<"\n";
        std::cout<<"Customer name:"<<x.getcustName()<<"\n";
        std::cout <<"Customer Address:"<<x.getcustAddress()<<"\n";
        std::cout <<x.getcustName()<< "'s order(s):";

        x.printOrders();

        std::cout <<"\n" << x.getcustName() << " was created at (" << x.getCustomerCreationTime() << ")\n";
        std::cout << std::endl;

        for(int y =0; y < ordersVector.size(); ++y) {
            if(ordersVector[y].getcustID() == x.getcustID()) {
                std::cout << "Order Number: " << ordersVector[y].getorderNum()<< " For CustomerID:" << ordersVector[y].getcustID()<<"\n";
                std::cout << "Product IDs in this order:";

                bool hasProducts = false;
                for(int o = 0; o < productsVector.size(); o++) {
                    if(productsVector[o].getOrderNumber() == ordersVector[y].getorderNum()) {
                        std::cout << productsVector[o].getProductNum() << " ";
                        hasProducts = true;
                    }
                }
                if(!hasProducts) {
                    std::cout << "None";
                }

                std::cout << "\nThis order was created at ("<< ordersVector[y].getorderCreationTime() << ")" << std::endl;

                for(int z = 0; z < productsVector.size(); ++z) {
                    if(productsVector[z].getOrderNumber() == ordersVector[y].getorderNum()) {
                        std::cout << "\nProduct Number:" << productsVector[z].getProductNum() << "\n";
                        std::cout << "Product Name:" << productsVector[z].getProductName() << "\n";
                        std::cout << "Product Description:" << productsVector[z].getProductDescription() << "\n";
                        std::cout << "This Product was ordered at (" << productsVector[z].getproductCreationTime() << ")\n";
                    }
                }
            }
        }
    }
};

int main() {
    std::string userresponce;
    std::vector<Customer> customersvector;
    std::vector<unsigned int>ordernumsvector;

    std::vector<Order> ordersvector;
    std::vector<unsigned int> productnumsvector;

    std::vector<Product> productsvector;
    int currentMonth, currentDay, currentYear, currentHour, currentMinute;


    std::cout << "Would you like to create a new customer? (Y/N):" << std::endl;
    std::cin >> userresponce;
    InputBuffer();
    while(userresponce != "Y" && userresponce != "y" && userresponce != "N" && userresponce != "n") {
        std::cout << "Please enter either Y or N:"<< std::endl;
        std::cin>>userresponce;
        InputBuffer();
    }
    while (userresponce == "Y" || userresponce == "y") {
        std::string nameresponse;
        int idresponse;
        std::string addressresponse;
        int amountoforders;


        Customer customer;

        std::cout << "Enter the customer name:"<< std::endl;
        std::getline(std::cin, nameresponse);
        customer.setcustName(nameresponse);


        std::cout <<"Enter the customer ID number:"<< std::endl;
        std::cin >> idresponse;
        customer.setcustID(idresponse);
        InputBuffer();

        std::cout <<"Enter the customer address:"<< std::endl;
        std::getline(std::cin, addressresponse);
        customer.setaddress(addressresponse);


        std::cout << "How many orders does this customer have:"<< std::endl;
        std::cin >> amountoforders;
        InputBuffer();


        for(int i = 0; i < amountoforders; i++) {
            int orderIDnumber;
            std::cout <<"Enter the 4 digit order number for order #"<< i+1 << std::endl;
            std::cin >> orderIDnumber;
            while(orderIDnumber < 1000 || orderIDnumber > 9999) {
                std::cout << "Invalid order number entered. Please try again with only 4 digits"<< std::endl;
                std::cin >> orderIDnumber;
                InputBuffer();
            };
            Order newOrder(orderIDnumber,customer.getcustID());
            customer.addOrdernum(orderIDnumber);

            int amountofproducts;
            std::cout << "How many products are in this order"<< std::endl;
            std::cin >> amountofproducts;
            InputBuffer();


            for(int j = 0; j < amountofproducts; j++) {
                int productIDnumber;
                std::cout<<"Enter the 3 digit product number for Product #"<< j + 1 <<
                    ", in Order #"<< newOrder.getorderNum() <<
                        ", for customerID "<< newOrder.getcustID() << std::endl;
                std::cin >> productIDnumber;
                InputBuffer();

                while(productIDnumber < 100 || productIDnumber > 999) {
                    std::cout << "Invalid product number entered. Please try again with only 3 digits"<< std::endl;
                    std::cin >> productIDnumber;
                    InputBuffer();
                }
                productnumsvector.push_back(productIDnumber);

                Product newproduct(productIDnumber,newOrder.getorderNum());
                std::string productname;
                std::string productDesc;

                std::cout<<"What is the name of this product:"<< std::endl;
                std::getline(std::cin,productname);
                newproduct.setProductName(productname);


                std::cout << "Please provide a brief description of the product:"<< std::endl;
                std::getline(std::cin, productDesc);
                newproduct.setProductDescription(productDesc);

                productsvector.push_back(newproduct);
                Product::incrementProdCount();
            }
            newOrder.setProductNums(productnumsvector);
            ordersvector.push_back(newOrder);
            Order::incrementOrdCount();
        }
        customer.setOrderNums(ordernumsvector);
        customersvector.push_back(customer);
        Customer::incrementCustCount();

        std::cout << "Would you like to enter another customer?: (Y/N):"<< std::endl;
        std::getline(std::cin,userresponce);
        while(userresponce != "Y" && userresponce != "y" && userresponce != "N" && userresponce != "n") {
            std::cout << "Please enter either Y or N:"<< std::endl;
            std::getline(std::cin, userresponce);
        }
    }

    getTime(currentMonth, currentDay, currentYear, currentHour, currentMinute);
    outputReport(customersvector, ordersvector, productsvector);

    std::cout<< "\nOverall there is a total of:"<< std::endl << Customer::getCustomerCount() << " customer(s)." << std::endl
    << Order::getorderCount() << " order(s)" << std::endl
    << Product::getproductCount() << " product(s)" << std::endl;

    std::cout << "Would you like to reset this counted data? (Y/N)";
    std::string newresponse;
    std::cin >> newresponse;
    while(newresponse != "Y" && newresponse != "y" && newresponse != "N" && newresponse != "n") {
        std::cout << "Please enter either Y or N:"<< std::endl;
        std::cin>>newresponse;
    }
    if(newresponse == "Y" || newresponse == "y") {
        Customer::setCustomerCount(0);
        Order::setOrderCount(0);
        Product::setProductCount(0);
        std::cout << "Very well, the data counts have been reset" << std::endl
        << "There is now a total of:" << std::endl
        << Customer::getCustomerCount() << " customer(s)." << std::endl
        << Order::getorderCount() << " order(s)" << std::endl
        << Product::getproductCount() << " product(s)" << std::endl;;
    } else {
        std::cout << "Very well, the data will remain as is.";
    }
};
