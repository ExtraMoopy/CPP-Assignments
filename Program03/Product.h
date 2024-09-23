//
// Created by Owner on 9/12/2024.
//

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

#endif //PRODUCT_H
//Member data: productNum, productName, productDescription, productCreationTime, productCount - static
class Product {
    public:
    Product(unsigned int,unsigned int);
    ~Product();

    static void incrementProdCount();

    void setProductNum(unsigned int);
    void setProductName(std::string);
    void setProductDescription(std::string);
    void setProductCreationTime(unsigned int&, unsigned int&, unsigned int&, unsigned int&, unsigned int&);
    static void setProductCount(unsigned int);
    void setOrderNumber(unsigned int);


    unsigned int getProductNum();
    std::string getProductName();
    std::string getProductDescription();
    unsigned int getOrderNumber();
    static unsigned int getproductCount();
    std::string getproductCreationTime();

    private:
    unsigned int productNum;
    std::string productName;
    std::string productDescription;
    static unsigned int productCount;
    unsigned int orderNumber;
    std::string productCreationTime;
    unsigned int productHour;
    unsigned int productMinute;
    unsigned int productMonth;
    unsigned int productDay;
    unsigned int productYear;

};