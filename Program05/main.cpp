#include <iostream>
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

void InputBuffer() {
    std::string buffer;
    std::getline(std::cin, buffer);
}

int main()
{
    std::cout << "We will now demonstrate the Package class\n"
                  "and classes that have inherited from the \n"
                  "package class (TwoDayPackage and OvernightPackage)" << std::endl;

    std::cout << "Enter a name for the owner of the package: " << std::endl;
    std::string Packagename;
    std::getline(std::cin, Packagename);
    std::cout << "Enter an address for the package: " << std::endl;
    std::string Packageaddress;
    std::getline(std::cin, Packageaddress);
    std::cout << "Enter a city for the package: " << std::endl;
    std::string Packagecity;
    std::getline(std::cin, Packagecity);
    std::cout<<"Enter a state for the package: "<<std::endl;
    std::string Packagestate;
    std::getline(std::cin, Packagestate);
    std::cout<<"Enter a Zipcode for the sender of the package: "<<std::endl;
    int PackagesenderZipcode;
    std::cin >> PackagesenderZipcode;
    std::cout<<"Enter a Zipcode for the receiver of the package: "<<std::endl;
    int PackagereceiverZipcode;
    std::cin >> PackagereceiverZipcode;
    std::cout<<"Enter how many ounces the package weighs (1lb = 16 oz): "<<std::endl;
    double PackageWeight;
    std::cin >> PackageWeight;
    std::cout<<"Enter the cost per ounce for the package: "<<std::endl;
    double PackageCostPerOunce;
    std::cin >> PackageCostPerOunce;
    Package package(Packagename,Packageaddress,Packagecity,
        Packagestate,PackagesenderZipcode,PackagereceiverZipcode,PackageWeight,PackageCostPerOunce);

    InputBuffer();

    std::cout <<std::endl<< "We will now demonstrate the TwoDayPackage class\n"
                 "Which inherits data members and function members\n"
                 "from the Package class." << std::endl;
    std::cout<<"Enter a name for the owner of the TwoDayPackage: "<< std::endl;
    std::string TwoDayPackageName;
    std::getline(std::cin, TwoDayPackageName);
    std::cout<<"Enter an address for the TwoDayPackage: " << std::endl;
    std::string TwoDayPackageAddress;
    std::getline(std::cin, TwoDayPackageAddress);
    std::cout<<"Enter a city for the TwoDayPackage: " << std::endl;
    std::string TwoDayPackageCity;
    std::getline(std::cin, TwoDayPackageCity);
    std::cout<<"Enter a state for the TwoDayPackage: " << std::endl;
    std::string TwoDayPackageState;
    std::getline(std::cin, TwoDayPackageState);
    std::cout<<"Enter a Zipcode for the sender of the TwoDayPackage: " << std::endl;
    int TwoDayPackageSenderZipcode;
    std::cin >> TwoDayPackageSenderZipcode;
    std::cout<<"Enter a Zipcode for the reciever of the TwoDayPackage: " << std::endl;
    int TwoDayPackageRecieverZipcode;
    std::cin >> TwoDayPackageRecieverZipcode;
    std::cout << "Enter how many ounces the TwoDayPackage weighs (1lb = 16oz): " << std::endl;
    double TwoDayPackageWeight;
    std::cin >> TwoDayPackageWeight;
    std::cout<<"Enter the cost per ounce for the TwoDayPackage: " << std::endl;
    double TwoDayPackageCostPerOunce;
    std::cin >> TwoDayPackageCostPerOunce;
    std::cout<<"Enter the flat two-day shipping fee for the TwoDayPackage: " << std::endl;
    double TwoDayPackageTwoDayFee;
    std::cin >> TwoDayPackageTwoDayFee;
    TwoDayPackage twodaypackage(TwoDayPackageName,TwoDayPackageAddress,TwoDayPackageCity,TwoDayPackageState
        ,TwoDayPackageSenderZipcode,TwoDayPackageRecieverZipcode,TwoDayPackageWeight,TwoDayPackageCostPerOunce,
        TwoDayPackageTwoDayFee);

    InputBuffer();

    std::cout <<std::endl<< "We will now demonstrate the OvernightPackage class\n"
             "Which inherits data members and function members\n"
             "from the Package class." << std::endl;
    std::cout<<"Enter a name for the owner of the OverNightPackage: "<< std::endl;
    std::string OverNightPackageName;
    std::getline(std::cin, OverNightPackageName);
    std::cout<<"Enter an address for the OverNightPackage: " << std::endl;
    std::string OverNightPackageAddress;
    std::getline(std::cin, OverNightPackageAddress);
    std::cout<<"Enter a city for the OverNightPackage: " << std::endl;
    std::string OverNightPackageCity;
    std::getline(std::cin, OverNightPackageCity);
    std::cout<<"Enter a state for the OverNightPackage: " << std::endl;
    std::string OverNightPackageState;
    std::getline(std::cin, OverNightPackageState);
    std::cout<<"Enter a Zipcode for the sender of the OverNightPackage: " << std::endl;
    int OverNightPackageSenderZipcode;
    std::cin >> OverNightPackageSenderZipcode;
    std::cout<<"Enter a Zipcode for the receiver of the OverNightPackage: " << std::endl;
    int OverNightPackageRecieverZipcode;
    std::cin >> OverNightPackageRecieverZipcode;
    std::cout << "Enter how many ounces the OverNightPackage weighs (1lb = 16oz): " << std::endl;
    double OverNightPackageWeight;
    std::cin >> OverNightPackageWeight;
    std::cout<<"Enter the cost per ounce for the OverNightPackage: " << std::endl;
    double OverNightPackageCostPerOunce;
    std::cin >> OverNightPackageCostPerOunce;
    std::cout<<"Enter the additional rate for overnight shipping for the OverNightPackage: " << std::endl;
    double OverNightPackageOvernightRate;
    std::cin >> OverNightPackageOvernightRate;
    OvernightPackage overnightpackage(OverNightPackageName,OverNightPackageAddress,OverNightPackageCity,OverNightPackageState
        ,OverNightPackageSenderZipcode,OverNightPackageRecieverZipcode,OverNightPackageWeight,OverNightPackageCostPerOunce,
        OverNightPackageOvernightRate);

    std::cout<< std::endl<<"Data members for the Package class";
    std::cout<<std::endl<<"Name:" << package.getname()<< std::endl <<
                     "Address:" << package.getaddress() << std::endl <<
                     "City:" <<package.getcity() << std::endl <<
                     "State:"<<package.getstate() << std::endl <<
                     "Sender ZIPcode:"<<package.getzipSender() << std::endl <<
                     "Receiver ZIPcode:"<<package.getzipReceiver() << std::endl <<
                     "Weight in oz: "<<package.getweight() << std::endl <<
                     "Cost Per ounce: "<<package.getCostPerOunce() << std::endl <<
                     "Cost of shipping: " << package.calculateCost() <<std::endl;

    std::cout<< std::endl<<"Data members for TwoDayPackage class";
    std::cout<<std::endl<<"Name:" << twodaypackage.getname()<< std::endl <<
                     "Address:" << twodaypackage.getaddress() << std::endl <<
                     "City:" <<twodaypackage.getcity() << std::endl <<
                     "State:"<<twodaypackage.getstate() << std::endl <<
                     "Sender ZIPcode:"<<twodaypackage.getzipSender() << std::endl <<
                     "Receiver ZIPcode:"<<twodaypackage.getzipReceiver() << std::endl <<
                     "Weight in oz: "<<twodaypackage.getweight() << std::endl <<
                     "Cost Per ounce: "<<twodaypackage.getCostPerOunce() << std::endl <<
                     "Cost of shipping: " << twodaypackage.calculateCost() <<std::endl;

    std::cout<< std::endl<<"Data members for Overnight class";
    std::cout<<std::endl<<"Name:" << overnightpackage.getname()<< std::endl <<
                     "Address:" << overnightpackage.getaddress() << std::endl <<
                     "City:" <<overnightpackage.getcity() << std::endl <<
                     "State:"<<overnightpackage.getstate() << std::endl <<
                     "Sender ZIPcode:"<<overnightpackage.getzipSender() << std::endl <<
                     "Receiver ZIPcode:"<<overnightpackage.getzipReceiver() << std::endl <<
                     "Weight in oz: "<<overnightpackage.getweight() << std::endl <<
                     "Cost Per ounce: "<<overnightpackage.getCostPerOunce() << std::endl <<
                     "Cost of shipping: " << overnightpackage.calculateCost() <<std::endl;






};
