#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cin >> ws; // stream out any whitespace
    for(int i = 0; i < n; i++)
    {
        string local;
        getline(cin, local);
        std::cout << "> " << local << std::endl;
    }

    //............................
    return 0;
}