#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

int main()
{


    Package packageobj("John","405 Branch LN","Austin","TX" ,45625,98754,64,.73);

    TwoDayPackage twodaypackage("Amy","303 Cork Ave","Dallas", "TX", 65483,12642,80,.50,2);

    OvernightPackage overnightojb("Greg","508 Porkbelly Ln","Houston", "TX", 54789,12549,32,.23,.4);

    std::cout << packageobj.getname() << std::endl <<
                    packageobj.getaddress() << std::endl <<
                     packageobj.getstate() << std::endl <<
                         "$" << packageobj.getCostPerOunce() << std::endl
                             <<packageobj.getweight()<<" oz"<<std::endl <<
                                 "$"<<packageobj.calculateCost()<<std::endl<<std::endl;


    std::cout << twodaypackage.getname() << std::endl <<
        twodaypackage.getaddress() << std::endl <<
            twodaypackage.getstate() << std::endl <<
                "$"<<twodaypackage.getCostPerOunce() << std::endl <<
                    twodaypackage.getweight()<<" oz"<<std::endl <<
                        "$"<<twodaypackage.gettwodayfee() << std::endl <<
                        "$"<<twodaypackage.calculateCost() << std::endl <<std::endl;

    std::cout << overnightojb.getname() << std::endl <<
        overnightojb.getaddress() << std::endl <<
            overnightojb.getstate() << std::endl <<
                "$"<<overnightojb.getCostPerOunce() << std::endl <<
                    overnightojb.getweight()<<" oz"<<std::endl <<
                        "$"<<overnightojb.calculateCost();




};
