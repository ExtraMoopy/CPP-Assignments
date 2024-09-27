//
// Created by Owner on 9/26/2024.
//
#include "OvernightPackage.h"

#include "Package.h"
#include <string>
#include <iostream>

OvernightPackage::OvernightPackage(const std::string& Ownername, const std::string& Owneraddress, const std::string& Ownercity, const std::string& Ownerstate
        ,int zipSender,int zipReceiver,double weight,double costPerOunce, double overnightRate)
:  Package(Ownername, Owneraddress, Ownercity, Ownerstate, zipSender, zipReceiver, weight, costPerOunce) {
    setovernightRate(overnightRate);
} ;

void OvernightPackage::setovernightRate(double overnightRate) {
    this->overnightRate = overnightRate;
}

double OvernightPackage::getovernightRate() {
    return this->overnightRate;
}

double OvernightPackage::calculateCost() {
    return getweight() * (getCostPerOunce() + overnightRate);
}