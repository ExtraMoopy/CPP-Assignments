#include <algorithm>
#include <iostream>
#include <string>
#include <array>

void calculateDiscount(const double listPrice, const double discountPercentage, double& discountedPrice) {
    discountedPrice = listPrice - (listPrice * (discountPercentage / 100));
}

void determineLarger(int intOne, int intTwo, int* largerNum, bool& isEqual) {
    isEqual = false;
    if (intOne == intTwo){
        isEqual = true;
    } else if(intOne > intTwo) {
        *largerNum = intOne;
    } else if (intOne < intTwo) {
        *largerNum = intTwo;
    }

}

bool compareArrays(std::string arr1[] ,std::string arr2[], const int SIZE1, const int SIZE2) {
    if(SIZE1 != SIZE2) {
        return false;
    }
        for(int i = 0 ; i < SIZE1 ; i++) {
                if(arr1[i] != arr2[i]) {
                    return false;
                }
        }
    return true;
}

void sortArrays(std::string arr1[],const int SIZE1, std::array<std::string,5>& arr2) {

    std::sort(arr1,arr1 + SIZE1);
    std::sort(arr2.begin(),arr2.end());

}

void demoPtrTechniques(int* counterPtr, const int* counterPtr2,int* const counterPtr3,const int* const counterPtr4) {
    int regularNum = 100;
    int anotherNum = 200;
        std::cout << "\nThe first argument in this function is " << *counterPtr << std::endl;
        std::cout << "It is a Nonconstant Pointer to Nonconstant data" << std::endl <<
        "meaning that the data it points to can be modified directly and the pointer" << std::endl <<
            "can be reassigned to point elsewhere" << std::endl;
        *counterPtr +=10;
        std::cout << "The first argument passed is now ten more: " << *counterPtr << std::endl;
        counterPtr = &regularNum;
        std::cout << "The pointer now points to a different number: " << *counterPtr << std::endl;

        std::cout << std::endl;

        std::cout << "The second argument in this function is " << *counterPtr2 << std::endl;
        std::cout << "It is a Nonconstant pointer to constant data, meaning that" << std::endl <<
            "the pointer can be modified to point to any data of the appropriate type, but "<< std::endl <<
                "the data to which it points cannot be modified through the pointer" << std::endl;
        std::cout<< "The second argument in the function is " << *counterPtr2 << std::endl;
        std::cout<< "The data is constant so it cannot be modifed: " << *counterPtr2 << std::endl;
        counterPtr2 = &anotherNum;
        std::cout << "The pointer for argument 2 now points elsewhere: " << *counterPtr2 << std::endl;

        std::cout << std::endl;

        std::cout<<"The third argument in this function is " << *counterPtr3 << std::endl;
        std::cout << "It is a Constant pointer to non constant data, meaining that" << std::endl <<
            "it always points to the same location, but" << std::endl <<
                "the data at that location can be modified." << std::endl;
        std::cout << "The third argument in this funciton is " << *counterPtr3 << std::endl;
        *counterPtr3 += 10;
        std::cout << "The third argument is now ten more: " << *counterPtr3 << std::endl;
        std::cout << "The pointer is constant and cannot be changed: " << *counterPtr3 << std::endl;

        std::cout << std::endl;

        std::cout << "The fourth argument in this function is " << *counterPtr4 << std::endl;
        std::cout << "It is a constant point er to constant data, meaning that " << std::endl <<
            "it always points to the same location and "<< std::endl << "the data at that location cannot be modified." << std::endl;
        std::cout << "The fourth argument is " << *counterPtr4 << std::endl;
        std::cout<< "The data is constant so it cannot be modifed: " << *counterPtr4 << std::endl;
        std::cout << "The pointer is constant and cannot be changed: " << *counterPtr4 << std::endl;
}
int main() {
    double price;
    int discountPercent;
    double discountedPrice;
    std::cout <<"Please enter the price of an item at a store: $";
    std::cin >> price;
    while(price < 0) {
        std::cout<< "Please enter a non-negative integer: ";
        std::cin >> price;
    }
    std::cout << "Please enter the discount percentage: %";
    std::cin >> discountPercent;
    while(discountPercent < 0) {
        std::cout<< "Please enter a non-negative discount:";
        std::cin >> discountPercent;
    }

    calculateDiscount(price, discountPercent, discountedPrice);

    std::cout << "The discounted price is $" << discountedPrice << std::endl << std::endl;



    int intOne;
    int intTwo;
    int LargerNum;
    bool isEqual=false;

    std::cout<<"Please enter 2 integers: " <<std::endl;
    std::cout << "Int one:";
    std::cin >> intOne;
    std::cout << "Int two:";
    std::cin >> intTwo;
    determineLarger(intOne,intTwo,&LargerNum,isEqual);

    if(isEqual == true) {
        std::cout << "Both integers are equal to one another!"<< std::endl<< std::endl;
    }else{
        std::cout << "The larger integer is: " << LargerNum << std::endl<< std::endl;
    }

    const int MAXSIZE1 = 3;
    const int MAXSIZE2 = 3;
    std::string strArray1[MAXSIZE1];
    std::string strArray2[MAXSIZE2];

    std::cout << "We will now compare 2 arrays for equality..." << std::endl;
    std::cout << "Please enter "<<MAXSIZE1<< " fruits: " <<std::endl;
        for(int i = 0 ; i <MAXSIZE1 ; i++) {
            std::cin >> strArray1[i];
        }
    std::cout << std::endl;
    std::cout << "Please enter "<<MAXSIZE2<<" more fruits: " <<std::endl;
        for(int i = 0 ; i <MAXSIZE2 ; i++) {
            std::cin >> strArray2[i];
        }
    if(compareArrays(strArray1,strArray2,MAXSIZE1,MAXSIZE2)) {
        std::cout<<"The arrays are exactly the same!" << std::endl<< std::endl;
    }
    else {
        std::cout<<"The arrays are different!" << std::endl<< std::endl;
    }





    std::string arr1[5];
    std::array <std::string,5> arr2;

    std::cout << "We will now sort arrays based on your entries..." << std::endl;
    std::cout << "Please only enter lowercase words to ensure proper sorting" << std::endl;
    std::cout <<"Please enter five lowercase words of your choice: " << std::endl;
    const int size1 = sizeof(arr1)/sizeof(arr1[0]);
    const int size2 = sizeof(arr2)/sizeof(arr2[0]);

    for(int i = 0 ; i < size1  ; i++) {
        std::cin >> arr1[i];
    }
    std::cout <<"Please enter another five words of your choice:" << std::endl;

    for(int i = 0 ; i < size2  ; i++) {
        std::cin >> arr2[i];
    }
    sortArrays(arr1,size1,arr2);

    std::cout << "Built in array1 (sorted): " << std::endl;
    for(std::string x : arr1) {
        std::cout << x << " ";
    }
    std::cout << "\nTemplate array2: (sorted)" << std::endl;
    for(std::string y : arr2) {
        std::cout << y << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout <<"This last output is based on the arguments in demoPtrTechniques."<< std::endl;
    int x = 4;
    int y = 5;
    int z = 3;
    int a = 9;
    demoPtrTechniques(&x,&y,&z,&a);
}
