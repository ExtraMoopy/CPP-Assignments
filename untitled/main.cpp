#include <iostream>
#include <string>
#include "Account_1.h"
using namespace std;


int main() {
    Account_1 user;
    cout <<"Enter your account name: ";
    string accname;
    getline(cin, accname);
    user.setName(accname);

    cout <<"You have set your account name to: "<<user.getName()<<endl;
    cout <<"Enter your account balance: ";
    double balance;
    cin >> balance;
    user.setBalance(balance);


    cout<<"Input finished " << endl << "Your account name is: "<<user.getName()<<endl<<
        "and your account balance is : " << user.getBalance();



}
