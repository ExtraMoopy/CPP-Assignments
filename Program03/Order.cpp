//
// Created by Owner on 9/12/2024.
//
#include <string>
#include <vector>
#include <iomanip>
#include "Order.h"


unsigned int Order::orderCount{0};

Order::Order(unsigned int orderNum,unsigned int customerID) {
    setOrderCreationTime(orderHour,orderMinute,orderMonth,orderDay,orderYear);
    setcustID(customerID);
    setorderNum(orderNum);
}

Order::~Order() {
}

void Order::incrementOrdCount() {
    orderCount++;
}

//Setters
void Order::setorderNum(unsigned int orderNumInput) {//Setter for orderNum
    orderNum = orderNumInput;
}
void Order::setcustID(unsigned int custIDInput) {//Setter for custID in order object
    custID = custIDInput;
}



void Order::setProductNums(std::vector<unsigned int> inputvector) {//Setter for Productnums
    for (unsigned int i = 0; i < inputvector.size(); i++) {
        productNums.push_back(inputvector[i]);
    }
}

void Order::setOrderCount(unsigned int input) {//Setter for ordercount
    orderCount = input;
}

void Order::setOrderCreationTime(unsigned int& hourInput, unsigned int& minuteInput
    ,unsigned int& monthInput, unsigned int& dayInput, unsigned int& yearInput) {
    time_t epochSeconds = time(nullptr);//Setter for order creation time

    tm* tm_ptr = localtime(&epochSeconds);

    hourInput = tm_ptr->tm_hour;
    minuteInput = tm_ptr->tm_min;
    monthInput = tm_ptr->tm_mon +1;
    dayInput = tm_ptr->tm_mday;
    yearInput = tm_ptr->tm_year + 1900;

    int twelveHour = (orderHour % 12 == 0) ? 12 : orderHour % 12;
    std::ostringstream output;
    output << orderMonth << "/" << orderDay << "/" << orderYear << " | " <<
        twelveHour << ":" << orderMinute << " " << (orderHour >= 12 ? "PM" : "AM");
    orderCreationTime = output.str();
}

//Getters

unsigned int Order::getorderNum() {//Getter for orderNum
    return orderNum;
}

unsigned int Order::getcustID() {//Getter for custID inside of orderobject
    return custID;
}

std::vector<unsigned int> Order::getproductNums() {//Getter for productNums
    return productNums;
}


std::string Order::getorderCreationTime() {//Getter for orderCreationtime
    return orderCreationTime;
}

unsigned int Order::getorderCount() {//Getter for orderCount
    return orderCount;
}


