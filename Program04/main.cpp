#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>

#include "OverloadDemo.h"
void InputBuffer() {
    std::string buffer;
    std::getline(std::cin, buffer);
}


int main()
{
    int intinput1, intinput2;
    double doubleinput1, doubleinput2;
    std::string stringinput1, stringinput2;
    OverloadDemo object1, object2, result;;

    std::cout <<"We will now demonstrate overloaded operators working" << std::endl<<
                "with class objects based on your entries..." << std::endl;
    std::cout<<"Please enter an integer for object1: "<<std::endl;
    std::cin>>intinput1;
    object1.setIntOne(intinput1);
    std::cout<<"Please enter an integer for object2: "<<std::endl;
    std::cin>>intinput2;
    object2.setIntOne(intinput2);

    std::cout<<"Please enter a double for object1: "<<std::endl;
    std::cin>>doubleinput1;
    object1.setDoubleOne(doubleinput1);
    std::cout<<"Please enter a double for object2: "<<std::endl;
    std::cin>>doubleinput2;
    object2.setDoubleOne(doubleinput2);

    InputBuffer();

    std::cout<<"Please enter a string for object1: "<<std::endl;
    std::getline(std::cin,stringinput1);
    object1.setStringOne(stringinput1);
    std::cout<<"Please enter a string for object2: "<<std::endl;
    std::getline(std::cin,stringinput2);
    object2.setStringOne(stringinput2);


    result = object1 + object2;
    std::cout << "object1 + object2| Overloaded output :" <<
    result.printResults()<< std::endl;

    result = object1 * object2;
    std::cout << "object1 * object2| Overloaded output :" <<
    result.printResults() << std::endl;

    result = object1 / object2;
    std::cout << "object1 / object2| Overloaded output :" <<
    result.printResults()<< std::endl;

    result = object1 - object2;
    std::cout << "object1 - object2| Overloaded output :" <<
    result.printResults()<< std::endl;

    result = object1++;
    std::cout <<"NOTE FOR USER! This is a postfix overload,"<<std::endl <<
        "which means it will perform its operations internally "<<std::endl <<
        "but not immediately show them..."<<std::endl <<
        "For this example the overload will increment each data member by 1"<<std::endl<<
        "and add a \"++\" or \"--\" (depending on increment or decrement call)" <<std::endl<<
        "to the end of the object's string, you will see this action" <<std::endl<<
        "the next time this object is called without postfix."<<std::endl <<
        "object1++| Overloaded output :" <<
    result.printResults()<< std::endl;

    result = object2++;
    std::cout <<"Postfix"<<std::endl;
    std::cout << "object2++| Overloaded output :" <<
    result.printResults()<< std::endl;

    result = ++object1;
    std::cout <<"Prefix (Notice the postfix operations are showing now!)"<<std::endl;
    std::cout << "++object1| Overloaded output :" <<
    result.printResults()<< std::endl;

    result = ++object2;
    std::cout <<"Prefix"<<std::endl;
    std::cout << "++object2| Overloaded output :" <<
    result.printResults()<< std::endl;

    result = object1--;
    std::cout <<"Postfix"<<std::endl;
    std::cout << "object1--| Overloaded output :" <<
    result.printResults()<< std::endl;

    result = object2--;
    std::cout <<"Postfix"<<std::endl;
    std::cout << "object2--| Overloaded output :" <<
    result.printResults()<< std::endl;

    result = --object1;
    std::cout <<"Prefix (The postfix decrement operations are showing!)"<<std::endl;
    std::cout << "--object1| Overloaded output:" <<
    result.printResults() << std::endl;

    result = --object2;
    std::cout <<"Prefix"<<std::endl;
    std::cout << "--object2| Overloaded output:" <<
    result.printResults() << std::endl;

}

