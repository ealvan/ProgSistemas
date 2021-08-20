#include <iostream>
#include <string>
#include <cmath>

using namespace std;
class AbstractEmployee{
    virtual void AskForPromotion()=0;
};

class Employee: AbstractEmployee{
    protected:
        string name;
        string company;
        int age;
    public:
        Employee(string n, string c, int a){
            name = n;
            company = c;
            age = a;
        }
        void setName(string na){
            name = na;
        }
        string getName(){
            return name;
        }
        void setCompany(string company){
            company = name;
        }
        string getCompany(){
            return company;
        }
        void setAge(int ag){
            age = ag;
        }
        int getAge(){
            return age;
        }
        void introduceYourself(){
            cout << "Hello ." << "I am "<<name<< endl; 
            cout << "I am " << age << " years old"<< endl;
            cout << "I am working in " << company << " company"<<endl;
            cout << "Nice to meet you." << endl; 

        }
        void AskForPromotion(){
            if(age >= 30){
                cout << "Congratulations " << name << " , you have a promotion"<<endl;

            }else{
                cout << "Sorry "<< name << " , you don't have a promotion"<<endl;
            }
        }
};
class Developer:  Employee{
    public: 
        string favProgrammingLanguage;
        Developer(string n,string c, int age, string favLanguage): Employee(n,c,age){
            favProgrammingLanguage = favLanguage;
        }
        void fixBug(){
            cout << getName() << " fixed bug, with " << favProgrammingLanguage <<" language" <<endl;
        }
};
int main(){
    // Employee e1 = Employee("Carlos" , "BeautyCode", 23);
    // Employee e2 = Employee("Juan", "Youtube-Team", 33);
    // e1.introduceYourself();
    // cout << endl;
    // e2.introduceYourself();
    // e1.AskForPromotion();
    // e2.AskForPromotion();

    Developer dev = Developer("Saldina", "BeautyCode" , 25, "C++");
    dev.AskForPromotion();
    //solo se puede acceder a AskForPromotion
    //por medio de la declaracion ": public Employee"
    
    dev.fixBug();

    return 0;
}