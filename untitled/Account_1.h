//
// Created by Owner on 8/24/2024.
//

#ifndef ACCOUNT_1_H
#define ACCOUNT_1_H
#include <string>


class Account_1 {

    public:
        void setName(std::string account_name) {
            name = account_name;
        }
        void setBalance(double account_balance) {
            balance = account_balance;
        }
    std::string getName() const {
            return name;
        }

    double getBalance() const {
            return balance;
        }
    private:
    std::string name;
    double balance;
};



#endif //ACCOUNT_1_H
