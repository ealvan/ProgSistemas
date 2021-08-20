#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main (){
    int limitGuesses = 3;
    bool outOfGuess = false;
    int countGuesses = 0;
    int numberMagic = 8;
    int guess;
    do{
        if(countGuesses < limitGuesses){
            cout << "Guess my number: "  ;
            cin >> guess;
            if(cin.fail()){
                cout << "There are few problems in your input !" << endl;
                return 0;
            }
            countGuesses++;
        }else{
            outOfGuess = true;
        }
        

    }while(numberMagic != guess && !outOfGuess);

    if (outOfGuess){
        cout << "You are Lose " << endl;
    }else{
        cout << "You are winner " << endl;
    }
    cout << "Your tries are: " << countGuesses << endl;
    return 0;

}
