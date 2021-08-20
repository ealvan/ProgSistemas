#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Book{
    public:
        string title;
        string author;
        int pages;

        Book(){
            title = "No title";
            author = "No author";
            pages = 0;
        }

        Book(string aTitle, string aAuthor, int aPages){
            title = aTitle;
            author = aAuthor;
            pages = aPages;
        }
};


int main(){

    Book b1("Harry Potter", "JK Rowling", 700);
    Book b2("Hunger Games", "Teikson", 500);
    Book b3;

    cout << b1.author << " - " << b1.title << " Pages: " << b1.pages << endl; 
    cout << b2.author << " - " << b2.title << " Pages: " << b2.pages << endl; 
    cout << b3.author << " - " << b3.title << " Pages: " << b3.pages << endl; 

    return 0;
}