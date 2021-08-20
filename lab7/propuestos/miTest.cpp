#include<iostream>
#include<vector>
using namespace std;
int main() {
   int x;
   char str[80];
   cout << "Enter a number and a string:\n";
   cin >> x;
   cin.getline(str,80); //take a string
   cout << "You have entered:\n";
   cout << x << endl;
   cout << str << endl;
}