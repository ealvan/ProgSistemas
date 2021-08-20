#include <iostream>
#include <map>
using namespace std;
//find number of ocurrences of string
int main(){
    string test = "qqqqqq6eee3rrr3ttttttt7oooooo6";
    map<char,int> freq;
    for(int i =0; i< test.length(); i++){
        char current = test[i];

        if(freq.find(current) == freq.end()){
            freq[current] = 0;
        }

        freq[current]++;
    }
    for(map<char,int>::iterator itr = freq.begin(); itr != freq.end(); itr++){
        cout << "Key "<<itr->first<<"- Value: "<<itr->second<<endl;
    }

    return 0;
}