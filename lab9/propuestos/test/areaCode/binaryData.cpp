#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Person{
    char age[25];
    char first[25];
    char last[25];
    char phone[25];
};

class BinaryData{
    private:
        char age[25];
        char first[25];
        char last[25];
        char phone[25];
    public:
        BinaryData(){}
        //destrucutro
        void setData(int age, string strF, string strLas, string phone){
            sprintf(this->age,"%d",age);
            sprintf(this->first,"%s",strF.c_str());
            sprintf(this->last,"%s",strLas.c_str());
            sprintf(this->phone,"%s",phone.c_str());   
        }
        void Save(ofstream& of){
            of.write((char*)&age, sizeof(age));
            of.write((char*)&first, sizeof(first));
            of.write((char*)&last, sizeof(last));
            of.write((char*)&phone, sizeof(phone));
        }
        void writeBinaryFile(string filename){
            ofstream fs;
            fs.open(filename, ios::out | ios::binary);
            if(!fs.is_open()){
                cout << "Cannot open file"<<filename << endl;
            }else{
                this ->Save(fs);
            }
            fs.close();
        }
        void readBinaryFile(string filename){
            Person p;
            ifstream binaryFile;
            int size = 0;
            
            binaryFile.open(filename, ios::in | ios::binary);
            binaryFile.seekg(0, ios::end);
            size = (int)binaryFile.tellg();
            binaryFile.seekg(0, ios::beg);

            while(binaryFile.tellg() < size){
                binaryFile.read((char*)p.age, sizeof(p.age));
                binaryFile.read((char*)p.first, sizeof(p.first));
                binaryFile.read((char*)p.last, sizeof(p.last));
                binaryFile.read((char*)p.phone, sizeof(p.phone));
                cout << p.age << "\t" << p.first << "\t" << p.last << "\t"<<p.phone<< endl;
            }
                
            binaryFile.close();
        }


};

int main(){
    string first,last,phone;
    int age;
    BinaryData *ptr = new BinaryData();
    cout << "enter age: ";
    cin >> age;
    cout << "enter first name: ";
    cin >> first;
    cout << "Enter last name: ";
    cin >> last;
    cout << "Enter phone number: ";
    cin >> phone;
    ptr->setData(age, first, last, phone);
    ptr->writeBinaryFile("records.dat");
    ptr->readBinaryFile("records.dat");

}




