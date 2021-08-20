#include <iostream>
#include <string>
using namespace std;
class Atlet{
    private:
        string name;
        int number;
        string nacionality;
        double time;
    public:
        Atlet(string n, int num, string nacio, double t){
            name = n;
            number = num;
            nacionality = nacio;
            time = t;                
        }
        string getName(){
            return name;
        }
};

class Race{
    private:
        double distance;
        Atlet runners[3];
    public:
        //how to initalize arrays of objects here .
        Race( Atlet arr[3], double dist){
            runners = arr;
            distance = dist;          
        } 
};