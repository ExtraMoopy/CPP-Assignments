//
// Created by Owner on 9/26/2024.
//

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include "Package.h"
class OvernightPackage: public Package {
    public:
    OvernightPackage(const std::string&, const std::string&, const std::string&, const std::string&
        ,int,int,double,double,double);

    void setovernightRate(double);
    double getovernightRate();

    double calculateCost();


private:
    double overnightRate;



};
#endif //OVERNIGHTPACKAGE_H