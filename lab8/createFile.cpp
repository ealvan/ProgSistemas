#include <iostream>
#include <fstream>
using namespace std;
int main() {
	fstream my_file;
	my_file.open("flex.l", ios::out);
	if (!my_file) {
		cout << "File not created!\n";
	}
	else {
		cout << "File created successfully!\n";
		my_file.close(); 
	}
	return 0;
}