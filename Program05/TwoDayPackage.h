//
// Created by Owner on 9/26/2024.
//

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#endif //TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package {
    public:
    TwoDayPackage(const std::string&, const std::string&, const std::string&, const std::string&
        ,int,int,double,double,double);

    void settwodayfee(double);
    double gettwodayfee();

    double calculateCost();


    private:
    double twodayfee;

};