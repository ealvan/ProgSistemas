#include<iostream>
#include<fstream>
using namespace std;
struct Student {
    char name[50];
    int age;
    float gpa;
};
int main(){ 
    Student stu = {"Tom", 12, 3.45};
    fstream f;
    f.open("recods.dat", ios::out | ios::binary);
    if(f.is_open()){
        f.write(reinterpret_cast<char*>(&stu), sizeof(Student));
        f.close();
    }else{
        cout << "ERROR\n";
    }

    Student new_stu;
    f.open("recods.dat", ios::in | ios::binary);
    if(f.is_open()){
        f.read(reinterpret_cast<char*>(&new_stu), sizeof(Student));
        f.close();
    }else{
        cout << "ERROR\n";
    }   

    cout << new_stu.name << endl;
    cout << new_stu.age << endl;
    cout << new_stu.gpa << endl;

    return 0;
}