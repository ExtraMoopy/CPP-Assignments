//
// Created by Owner on 9/12/2024.
//
#include <string>
#include <vector>

#include "Product.h"
#ifndef ORDER_H
#define ORDER_H

#endif //ORDER_H

class Order {
    public:
    Order(unsigned int,unsigned int);
    ~Order();

    static void incrementOrdCount();

    //Setters
    void setorderNum(unsigned int);
    void setcustID(unsigned int);
    void setOrderCreationTime(unsigned int&, unsigned int&,
        unsigned int&, unsigned int&,unsigned int&);
    void setProductNums(std::vector<unsigned int>);
    static void setOrderCount(unsigned int);


    //static getter
    static unsigned int getorderCount();

    unsigned int getorderNum();
    unsigned int getcustID();
    std::vector<unsigned int> getproductNums();
    std::string getorderCreationTime();

    private:
    unsigned int orderNum;
    unsigned int custID;
    std::vector<unsigned int> productNums;
    static unsigned int orderCount;
    std::string orderCreationTime;
    unsigned int orderHour;
    unsigned int orderMinute;
    unsigned int orderMonth;
    unsigned int orderDay;
    unsigned int orderYear;
};
