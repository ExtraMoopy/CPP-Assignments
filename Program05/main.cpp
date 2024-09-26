#include <iostream>
#include "Package.h"
int main()
{


    Package packageobj("John","405 Branch LN","Austin","TX"
        ,45625,98754,64,.73);

    std::cout << packageobj.getname() << std::endl <<
                    packageobj.getaddress() << std::endl <<
                     packageobj.getstate() << std::endl <<
                         "$" << packageobj.getCostPerOunce() << std::endl;

};
