#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <iostream>
using namespace std;

bool isFileExist(char fileName[]) {
    FILE *fp = fopen(fileName, "r");
    if (fp) {
        fclose(fp);
        return true;
    }
    return errno != ENOENT;
}
int main(){
    char f[] ="recordss.dat";
    bool e = isFileExist(f);
    cout << e << endl;
}