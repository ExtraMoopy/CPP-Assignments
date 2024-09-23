//
// Created by Owner on 9/12/2024.
//

#include <string>
#include <iostream>
#include <vector>
#include "Product.h"
#include <sstream>

unsigned int Product::productCount{0};



Product::Product(unsigned int productNum, unsigned int orderNumber) {
    setProductNum(productNum);
    setOrderNumber(orderNumber);
    setProductCreationTime(productHour,productMinute,productMonth,productDay,productYear);
}

Product::~Product() {
}
void Product::incrementProdCount() {
    productCount++;
}


//Setters
void Product::setProductName(std::string ProductNameInput) {//Setter for name
    productName = ProductNameInput;
}

void Product::setProductNum(unsigned int ProductNumInput) {//Setter for product num
    productNum = ProductNumInput;
}

void Product::setProductDescription(std::string ProductDescriptionInput) {//Setter for product description
    productDescription = ProductDescriptionInput;
}

void Product::setProductCount(unsigned int input) {//Setter for product count
    productCount = input;
}

void Product::setProductCreationTime(unsigned int& hourInput, unsigned int& minuteInput,
    unsigned int& monthInput, unsigned int& dayInput, unsigned int& yearInput) {//Setter for product creation time
    time_t epochSeconds = time(nullptr);

    tm* tm_ptr = localtime(&epochSeconds);

    hourInput = tm_ptr->tm_hour;
    minuteInput = tm_ptr->tm_min;
    monthInput = tm_ptr->tm_mon +1;
    dayInput = tm_ptr->tm_mday;
    yearInput = tm_ptr->tm_year + 1900;

    int twelveHour = (productHour % 12 == 0) ? 12 : productHour % 12;
    std::ostringstream output;
    output << productMonth << "/" << productDay << "/" << productYear << " | " <<
        twelveHour << ":" << productMinute << " " << (productHour >= 12 ? "PM" : "AM");
    productCreationTime = output.str();
}
void Product::setOrderNumber(unsigned int ordernuminput) {
    orderNumber = ordernuminput;
}

//Getters
std::string Product::getProductName() {//Getter for product name
    return productName;
}
unsigned int Product::getProductNum() {//Getter for product num
    return productNum;
}
std::string Product::getProductDescription() {//Getter for description
    return productDescription;
}

std::string Product::getproductCreationTime() {//Getter for product creation time
    return productCreationTime;
}
unsigned int Product::getproductCount() {//Getter for product count
    return productCount;
}
unsigned int Product::getOrderNumber() {
    return orderNumber;
}

