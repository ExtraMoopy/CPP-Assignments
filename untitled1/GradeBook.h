#include <iostream>
#include <array>
#include <iomanip>
#include <string>


class GradeBook {
    public:
    static const size_t students{10};

    //constructor to initialize course name and grades
    GradeBook(const std::string& name,
        const std::array<int, students>& gradesArray)
        : courseName{name}, grades{gradesArray} {
    }

    //function to set the course name
    void setCourseName(const std::string& name) {
        courseName = name;
    }

    //func to get course name
    const std::string& getCourseName() const {
        return courseName;
    }

    //display welcome msg to user

    void DisplayWelcomeMessage() const {
        //call getcourseName to get the name if this gradebook;s course
        std::cout<<"Welcome to the grade book for\n"<<getCourseName()<< "!"<<std::endl;
    }

    void processGrades() const {
        outputGrades();

        //call function to get average and calculate the average grade
        std::cout << std::setprecision(2) << std::fixed;
        std::cout<< "\nClass average is " << getAverage() << std::endl;

        //call functions to get max and min

        std::cout << "Lowest grade is " << getMinimum() << std::endl;
        std::cout << "Highest grade is " << getMaximum() << std::endl;

        outputBarChar(); //display grade chart
    }

    int getMinimum() const {
        int lowGrade{100};

        for (int grade : grades) {
            //if current grade lower than lowGrade, assign it to lowGrade
            if(grade < lowGrade) {
                lowGrade = grade;
            }
        }
        return lowGrade; // return lowest grade
    }

    int getMaximum() const {
        int highGrade{0};

        for(int grade : grades) {
            if(grade > highGrade) {
                highGrade = grade;
            }
        }
        return highGrade;
    }

    double getAverage() const {
        int total{0};

        //sum the grades in the array
        for (int grade : grades) {
            total += grade;
        }
        //return average
        return static_cast<double>(total) / grades.size();
    }

    void outputBarChar() const {
        std::cout<< "\nGrade distrobution:"<<std::endl;

        //stores frequency of grades in each range of 100
        const size_t frequencySize{11};
        std::array<unsigned int, frequencySize> frequency{}; //initialize to 0's

        //for each grade, increment the appropriate frequency
        for(int grade : grades) {
            ++frequency[grade/10];
        }

        //for each grade frequency, print bar in chart
        for(size_t count{0}; count < frequencySize; ++count) {
            //output bar labels ("0-9:", ..., "90-99", "100":)
            if (0 == count){
                std::cout <<"0-9 :";
            }
            else if(10 == count) {
                std::cout <<"100 :";
            }
            else {
                std::cout << count * 10 << "-" << (count * 10) + 9 << ": ";
            }

            //print bar of asterisks
            for(unsigned int stars{0}; stars < frequency[count]; ++stars) {
                std::cout<<'*';
            }

            std::cout<<std::endl;
        }
    }

    void outputGrades() const {
        std::cout<<"\nGrade distrobution:"<<std::endl;

        //output each student's grade
        for(size_t student{0}; student < grades.size(); ++student) {
            std::cout<<"Student "<<std::setw(2)<<student +1 <<": "
              <<std::setw(3) << grades[student] << std::endl;
        }
    }

    private:
    std::string courseName;
    std::array<int, students> grades;
    };


