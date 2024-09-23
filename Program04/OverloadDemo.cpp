//
// Created by Owner on 9/17/2024.
//
#include "OverloadDemo.h"
#include <iomanip>
#include <iostream>
#include <string>

OverloadDemo::OverloadDemo() {
}

OverloadDemo::~OverloadDemo() {
}


void OverloadDemo::setIntOne(int i) {
    intOne = i;
}
void OverloadDemo::setDoubleOne(double d) {
    doubleOne = d;
}
void OverloadDemo::setStringOne(std::string s) {
    stringOne = s;
}


int OverloadDemo::getIntOne() {
    return intOne;
}
double OverloadDemo::getDoubleOne() {
    return doubleOne;
}
std::string OverloadDemo::getStringOne() {
    return stringOne;
}

OverloadDemo OverloadDemo::operator+(const OverloadDemo &ainput) {
    OverloadDemo binput;
    binput.intOne = this->intOne + ainput.intOne;
    binput.doubleOne = this->doubleOne + ainput.doubleOne;
    binput.stringOne = this->stringOne + "+"+ ainput.stringOne;
    return binput;
}

OverloadDemo OverloadDemo::operator*(const OverloadDemo &ainput) {
    OverloadDemo binput;
    std::ostringstream output;
    binput.intOne = this->intOne * ainput.intOne;
    binput.doubleOne = this->doubleOne * ainput.doubleOne;
    binput.stringOne = this->stringOne + "*"+ ainput.stringOne;
    return binput;

}

OverloadDemo OverloadDemo::operator-(const OverloadDemo &ainput) {
    OverloadDemo binput;
    std::ostringstream output;
    binput.intOne = this->intOne - ainput.intOne;
    binput.doubleOne = this->doubleOne - ainput.doubleOne;
    binput.stringOne = this->stringOne + "-"+ainput.stringOne;

    return binput;
}

OverloadDemo OverloadDemo::operator/(const OverloadDemo &ainput) {
    if (ainput.intOne == 0) {
        throw std::invalid_argument("Division by 0 is not possible |or| intOne data member has not been set");
    }
    if (ainput.doubleOne == 0.0) {
        throw std::invalid_argument("Division by 0 is not possible |or| doubleOne data member has not been set");
    }

    OverloadDemo binput;
    binput.intOne = this->intOne / ainput.intOne;
    binput.doubleOne = this->doubleOne / ainput.doubleOne;
    binput.stringOne = this->stringOne + "/"+ainput.stringOne;

    return binput;
}

//postfix Increment
OverloadDemo OverloadDemo::operator++(int) {
    OverloadDemo temp = *this;
    ++intOne;
    ++doubleOne;
    this->stringOne =this->stringOne+"++";
    return temp;
}
//postfixDecrement
OverloadDemo OverloadDemo::operator--(int) {
    OverloadDemo temp = *this;
    --intOne;
    --doubleOne;
    this->stringOne = this->stringOne+"--";
    return temp;
}
//prefix Increment
OverloadDemo OverloadDemo::operator++() {
    ++intOne;
    ++doubleOne;
    this->stringOne ="++"+this->stringOne;
    return *this;
}
//prefix Decrement
OverloadDemo OverloadDemo::operator--() {
    this->stringOne = "--"+this->stringOne;
    --intOne;
    --doubleOne;
    return *this;
}

std::string OverloadDemo::printResults() {
    std::ostringstream output;
    output <<std::endl << std::setprecision(2) << std::fixed
           <<"intOne: "   << intOne   <<std::endl
           <<"doubleOne: "<<doubleOne <<std::endl
           <<"stringOne: "<<stringOne <<std::endl;
    return output.str();
}
