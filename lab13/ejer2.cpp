#include <iostream>
#include <thread>
 using namespace std;

void func(int n, double m){}


int main(){
        thread th(func, 1, 5.7);
	return 0;
}
