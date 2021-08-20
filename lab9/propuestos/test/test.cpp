#include <iostream>
#include <fstream>
using namespace std;

struct Person
{
  char name[50];
  int age;
  char phone[24];
};

int main(){

  Person me = {"Robert", 28, "364-2534"};
  fstream file;

  file.open("data.dat", ios::out |ios::binary | ios:: in);

  if(file.is_open()){
      file.write(me.name, sizeof(me.name));
      file.write((char*) &me.age, sizeof(me.age));
      file.write(me.phone, sizeof(me.phone));

      Person m;
      file.read((char*)&m, sizeof(m));
      cout << m.name << m.age << m.phone;
  }
}