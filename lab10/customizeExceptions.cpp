#include <exception>
#include <iostream>
#include <string>
using namespace std;

class CustomException:public exception{
    private:
        string reason;
    public:
        CustomException(const char* why):reason(why){

        }
        virtual const char* what() const throw(){
            return reason.c_str();
        }
};
double divide(int dividend, int divisor){
    if(divisor == 0){
        throw CustomException("Divide by 0 is a crime");
    }
    return dividend/divisor;
}
int main(){
    try{
        cout << "Result is: " << divide(12,0);
    }catch(exception &exp){
        cout << exp.what() << endl;
        cout << "Sorry!, Can't continue ..." << endl;
    }
}