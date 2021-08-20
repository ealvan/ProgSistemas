#include<iostream>
#include<fstream>
using namespace std;
ostream& operator<<(ostream& os, const Telephone& telephone){
        const size_t nameSize = telephone.name.size();
        os << nameSize;
        os.write(telephone.name.data(), nameSize);
        os << telephone.phno;
        return os;
}

istream& operator>>(istream& is, Telephone& telephone){
        size_t nameSize = 0;
        is >> nameSize;
        telephone.name.resize(nameSize);
        is.read(&telephone.name[0], nameSize);
        is >> telephone.phno;
        return is;
} 
class Telephone{   
    public:
        string name="a";
        int phno=123;
        void getTelephoneData(){    
            cout<<"Enter Name:";
            cin>>name;
            cout<<"Enter Phone Number:";
            cin>>phno;
            cin.ignore();
        }
        void displayData(){
            cout<<"Name\t\tPhone no"<<endl;
            cout<<name<<"\t\t"<<phno<<endl;
        }

        void getData() {
            Telephone temp;
            ifstream ifs("Sample.txt",ios::in|ios::binary);
            ifs >> temp;
            temp.displayData();
        } 

        void storeData(const Telephone& telephone) {
            ofstream ofs("Sample.txt",ios::out|ios::binary);
            ofs << telephone;
        } 
};
     
int main()
{
    Telephone t1;
    t1.getTelephoneData();
    cout<<"----Writing Data to file------"<<endl;
    t1.storeData(t1);
    t1.getData();
}