//
// Created by Owner on 9/26/2024.
//

#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>

#endif //PACKAGE_H

class Package{

    public:
    Package(const std::string&, const std::string&, const std::string&, const std::string&
        ,int,int,double,double);
    ~Package();
    //Setters/Getters
    void setname(const std::string&);
    std::string getname();

    void setaddress(const std::string&);
    std::string getaddress();

    void setcity(const std::string&);
    std::string getcity();

    void setstate(const std::string&);
    std::string getstate();

    void setzipSender(int);
    int getzipSender();

    void setzipReceiver(int);
    int getzipReceiver();

    void setweight(double);
    double getweight();

    void setCostPerOunce(double);
    double getCostPerOunce();

    double calculateCost();


    private:
    std::string name;
    std::string address;
    std::string city;
    std::string state;
    int zipSender{};
    int zipReceiver{};
    double weight{};
    double costPerOunce{};


};