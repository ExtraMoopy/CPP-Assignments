//
// Created by Owner on 9/26/2024.
//
#include "TwoDayPackage.h"
#include <string>
#include <iostream>

TwoDayPackage::TwoDayPackage(const std::string& Ownername, const std::string& Owneraddress, const std::string& Ownercity, const std::string& Ownerstate
        ,int zipSender,int zipReceiver,double weight,double costPerOunce, double twodayfee)
//explicitly call package constructor to input TwoDayPackage Constructor arguments
    : Package (Ownername, Owneraddress, Ownercity, Ownerstate, zipSender, zipReceiver, weight, costPerOunce) {
    //use new member function to set new member data in TwoDayPackage
    settwodayfee(twodayfee);
};

void TwoDayPackage::settwodayfee(double fee) {
    this->twodayfee = fee;
}

double TwoDayPackage::gettwodayfee() {
    return this->twodayfee;
}

double TwoDayPackage::calculateCost() {
    return twodayfee + (getweight()* getCostPerOunce());
}
