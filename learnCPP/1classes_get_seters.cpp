#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Student{

    private:
        string name;
        string major;
        double gpa;
    public:
        
        Student(string n, string m , double _gpa){
            name = n;
            major = major;
            gpa = _gpa;
        }
        void setGpa(double _gpa){
            gpa = _gpa;
        }
        void setName(string name_){
            name = name_;
        }
        void setMajor(string major_){
            major = major_;
        }
        string getName(){
            return name;
        }
        string getMajor(){
            return major;
        }
        double getGpa(){
            return gpa;
        }
        bool haveHonor(){
            if(gpa >= 3.5){
                return true;
            }
            return false;
        }
};

int main(){
    Student stud1("Carlos" , "Ing Sistemas", 3.5);
    Student stud2("Mellow" , "Chemistry", 3.4);
    Student stud3("Near River" , "Physics", 3.8);

    
    cout << "GPA: " << stud1.getGpa() << " DoYouHaveHonor? " << stud1.haveHonor() << endl;
    cout << "GPA: " << stud2.getGpa() << " DoYouHaveHonor? " << stud2.haveHonor() << endl;
    cout << "GPA: " << stud3.getGpa() << " DoYouHaveHonor? " << stud3.haveHonor() << endl;


    cout << stud2.getName() << endl;
    stud2.setName("Mellow Kheel");
    cout << stud2.getName() << endl;
    

    return 0;
}