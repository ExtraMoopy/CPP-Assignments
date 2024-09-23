//
// Created by Owner on 9/11/2024.
//
#include <string>
#include <vector>
#ifndef CUSTOMER_H
#define CUSTOMER_H

#endif //CUSTOMER_H
//Customer .h file for Customer.cpp
class Customer {
    public:
    //constructor
    Customer();
    //destructor
    ~Customer();

    static void incrementCustCount();
    void printOrders();
    void addOrdernum(unsigned int);

    //Setters
    void setcustID(unsigned int);//setter for custID
    void setcustName(std::string);//setter for name
    void setaddress(std::string);// setter for address
    void setCustomerCreationTime(unsigned int&, unsigned int&,
        unsigned int&, unsigned int& , unsigned int&); //setter for customerCreationTime
    void setOrderNums(std::vector<unsigned int>);//setter for ordernums
    static void setCustomerCount(unsigned int); // setter for customercount

    //Getters
    unsigned int getcustID();//getter for custID
    std::string getcustName();//getter for name
    std::string getcustAddress();//getter for address
    std::vector<unsigned int> getOrderNums();//getter for orderNums vector
    std::string getCustomerCreationTime();//getter for CustomerCreationTime
    //static variable
    static unsigned int getCustomerCount();//getter for

    private:
    unsigned int custID;
    std::string name;
    std::string address;
    std::vector<unsigned int> orderNums;
    std::string customerCreationTime;
    static unsigned int customerCount;
    unsigned int customerHour;
    unsigned int customerMinute;
    unsigned int customerMonth;
    unsigned int customerDay;
    unsigned int customerYear;

};