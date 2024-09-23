//
// Created by Owner on 9/11/2024.
//
#include <string>
#include <vector>
#include <iomanip>
#include "Customer.h"

#include <iostream>
#include <vector>

//Class customer
unsigned int Customer::customerCount{0};


Customer::Customer() {
    setCustomerCreationTime(customerHour, customerMinute,customerMonth, customerDay,customerYear);
}

Customer::~Customer() {
}

void Customer::incrementCustCount() {
    customerCount++;
}

void Customer::printOrders() {
    for(unsigned int x : orderNums) {
        std::cout << x << " ";
    }
}
void Customer::addOrdernum(unsigned int newinputnumber) {
    orderNums.push_back(newinputnumber);
};

//Setters
void Customer::setcustID(unsigned int custIdInput) {//Setter for custID
    if(custIdInput < 1000 || custIdInput > 9999) {
        throw std::invalid_argument("Customer ID must consist of only 4 digits");
    }
    else {
        custID = custIdInput;
    }
}
void Customer::setcustName(std::string nameInput) {//Setter for name
    name = nameInput;
}
void Customer::setaddress(std::string addressInput) {//Setter for address
    address = addressInput;
}



void Customer::setOrderNums(std::vector<unsigned int> inputVector) {//Setter for OrderNums
    for(int i = 0; i < inputVector.size(); i++) {
        orderNums.push_back(inputVector[i]);
    }
}

void Customer::setCustomerCount(unsigned int input) {//Setter for CustomerCount
    customerCount = input;
}

void Customer::setCustomerCreationTime(unsigned int& hourInput, unsigned int& minuteInput
    ,unsigned int& monthInput, unsigned int& dayInput, unsigned int& yearInput) {//Setter for customerCreationTime
    time_t epochSeconds = time(nullptr);

    tm* tm_ptr = localtime(&epochSeconds);

    hourInput = tm_ptr->tm_hour;
    minuteInput = tm_ptr->tm_min;
    monthInput = tm_ptr->tm_mon +1;
    dayInput = tm_ptr->tm_mday;
    yearInput = tm_ptr->tm_year + 1900;

    int twelveHour = (customerHour % 12 == 0) ? 12 : customerHour % 12;
    std::ostringstream output;
    output << customerMonth << "/" << customerDay << "/" << customerYear << " | " <<
        twelveHour << ":" << customerMinute << " " << (customerHour >= 12 ? "PM" : "AM");
    customerCreationTime = output.str();
}
//Getters
std::string Customer::getcustName() {//Getter for name
    return name;
}
std::string Customer::getcustAddress() {//Getter for address
    return address;
}
unsigned int Customer::getcustID() {//Getter for custID
    return custID;
}
std::vector<unsigned int> Customer::getOrderNums() {//Getter for OrderNums
    return orderNums;
}

std::string Customer::getCustomerCreationTime() {//Getter for CustomerCreationTime
    return customerCreationTime;
}

unsigned int Customer::getCustomerCount() { //Getter for CustomerCount
    return customerCount;
}





