#include <iostream>

using namespace std;

int main(void){

  int blanks, tabs, newlines;
  int c;


  blanks = 0;
  tabs = 0;
  newlines = 0;

  do {
      c = getchar();
      if(c == ' ') {
          ++blanks;
      }
      else if(c == '\t') {
         ++tabs;
      }
      else if(c == '\n') {
         ++newlines;
      }
  }
  while(c != EOF);

cout << "newlines: "<<newlines<<" tabs: "<<tabs << " blanks: "<<blanks << endl;
    return 0;
}