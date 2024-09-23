//
// Created by Owner on 9/17/2024.
//

#ifndef OVERLOADDEMO_H
#define OVERLOADDEMO_H
#include <string>

#endif //OVERLOADDEMO_H

class OverloadDemo {
    public:
    OverloadDemo();
    ~OverloadDemo();

    void setIntOne(int i);
    void setDoubleOne(double d);
    void setStringOne(std::string s);

    int getIntOne();
    double getDoubleOne();
    std::string getStringOne();

    OverloadDemo operator+(const OverloadDemo& rhs);
    OverloadDemo operator*(const OverloadDemo& rhs);
    OverloadDemo operator/(const OverloadDemo& rhs);
    OverloadDemo operator-(const OverloadDemo& rhs);
    OverloadDemo operator++();
    OverloadDemo operator++(int);
    OverloadDemo operator--();
    OverloadDemo operator--(int);

    std::string printResults();


private:
        int intOne;
        double doubleOne;
        std::string stringOne;

};