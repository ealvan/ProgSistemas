#include<iostream>
#include<fstream>
using namespace std;
struct Student {
    char name[50];
    int age;
    float gpa;
};
int main(){ 
    const int SIZE = 3;
    Student old[SIZE] = {
        {"Tom",22,3.23},
        {"Hank",23,0.01},
        {"Matt",24,0.04},
    };
    fstream f;
    f.open("myrecords.dat", ios::out | ios::binary);
    if(f.is_open()){
        f.write(reinterpret_cast<char*>(old), SIZE*sizeof(Student));
        f.close();
    }else{
        cout << "ERRRO\n";
    }
    Student news[SIZE];
    f.open("myrecords.dat", ios::in | ios::binary);
    if(f.is_open()){
        f.read(reinterpret_cast<char*>(news), SIZE*sizeof(Student));
        f.close();
    }else{
        cout << "ERRRO\n";
    }
    for(Student&m : news){
        cout << m.name << endl;
        cout << m.gpa << endl;
        cout << m.age << endl;
    }

    return 0;
}