#include <tuple>

using namespace std;

int main(){
    tuple<int,char>t;
    get<0>(t) = 12;
    get<1>(t) = '=';

    
}