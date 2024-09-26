//
// Created by Owner on 9/26/2024.
//
#include <string>
#include <iostream>
#include "Package.h"

Package::Package(const std::string& Ownername, const std::string& Owneraddress, const std::string& Ownercity, const std::string& Ownerstate
        ,int zipSender,int zipReceiver,double weight,double costPerOunce) {
        name = Ownername;
        address = Owneraddress;
        city = Ownercity;
        state = Ownerstate;
        setzipReceiver(zipReceiver);
        setzipSender(zipSender);
        setweight(weight);
        setCostPerOunce(costPerOunce);
};

Package::~Package() {
}


void Package::setname(const std::string& inputname) {
        name = inputname;
}
std::string Package::getname() {
        return this->name;
}


void Package::setaddress(const std::string& inputaddress) {
        this->address = inputaddress;
}
std::string Package::getaddress() {
        return this->address;
}


void Package::setcity(const std::string& inputcity) {
        this->city = inputcity;
}
std::string Package::getcity() {
        return this->city;
}

void Package::setstate(const std::string& inputstate) {
        this->state = inputstate;
}
std::string Package::getstate() {
        return this->state;
}

void Package::setzipSender(const int senderZipinput) {
        this->zipSender = senderZipinput;
}
int Package::getzipSender() {
        return this->zipSender;
}

void Package::setzipReceiver(const int zipReceiverinput) {
        this->zipReceiver = zipReceiverinput;
}
int Package::getzipReceiver() {
        return this->zipReceiver;
}

void Package::setweight(const double weightinput) {
if(weightinput < 0) {
        throw std::invalid_argument("Weight cannot be negative");
}
        this->weight = weightinput;
}

double Package::getweight() {
        return this->weight;
}

void Package::setCostPerOunce(const double CPOInput) {
        if(CPOInput < 0) {
                throw std::invalid_argument("CostPerOunce cannot be negative");
        }
        this->costPerOunce = CPOInput;
}

double Package::getCostPerOunce() {
        return this->costPerOunce;
}




double Package::calculateCost() {
        return weight * costPerOunce;
}





