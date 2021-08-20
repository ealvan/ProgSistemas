#include <iostream>
#include <map>

using namespace std;
int main(){
    map<char,int> mp = {
        {'a',1},
        {'b',2},
        {'c',3},
        {'d',4},
        {'e',5},
        {'f',6},
    };
    //insert pair of element
    //first way:
    mp['g'] = 7;
    //first two:
    pair<char,int>p1('h',8);
    mp.insert(p1);

    cout << mp['g'] << endl;
    cout << mp['h'] << endl;
    
    //erase one item of map
    char key = 'g';
    mp.erase(key);
    mp.erase(p1.first);

    cout << mp['g'] << endl;
    cout << mp['h'] << endl;
    //show one how many items are there?
    cout << "Length: " << mp.size() << endl;
    //clear map
    mp.clear();
    
    cout << "Length: " << mp.size() << endl;
    //is empty???
    cout << "Is empty" << (mp.empty() ? "Si":"No") << endl;

    //For loop in maps
    mp = {
        {'a',1},
        {'b',2},
        {'c',3},
        {'d',4},
        {'e',5},
        {'f',6},        
    };
    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        //"itr" is a pointer!
        cout << "KEY: " << (*itr).first << " Value: " << itr->second << endl;
    }

    for(map<char,int>::iterator itr = mp.begin(); itr != mp.end(); itr++){
        //short form for referencing to properties of object value of address as a value in pointer
        cout << itr->first << " - " << itr->second << endl;
    }
    
    return 0;
}