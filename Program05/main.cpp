#include <iostream>
#include "TwoDayPackage.h"

int main()
{


    Package packageobj("John","405 Branch LN","Austin","TX" ,45625,98754,64,.73);

    TwoDayPackage twodaypackage("Amy","303 Cork Ave","Dallas", "TX", 65483,12642,80,.50,2);

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
                        "$"<<twodaypackage.calculateCost();




};
