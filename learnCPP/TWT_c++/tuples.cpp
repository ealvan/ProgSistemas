#include <iostream>
#include <tuple>

using namespace std;
int main(){
    tuple<char,int,string> person = make_tuple('1',20192190,"Edsel");
    tuple<char,int,string> officeWorker('2',20211502,"Tim");

    //swap tuples
    person.swap(officeWorker);
    //access to data
    cout<<get<0>(person) <<endl;
    cout<<get<1>(person) <<endl;
    cout<<get<2>(person) <<endl;
    cout <<endl;
    cout<<get<0>(officeWorker) <<endl;
    cout<<get<1>(officeWorker) <<endl;
    cout<<get<2>(officeWorker) <<endl;

    //decompose!!
    tuple<int,char> tpl(1,'C');
    int uno;
    char dos;
    tie(uno,dos) = tpl;
    cout << uno << endl;
    cout << dos << endl;

    //concatenation tuples
    tuple<int,char,string> p1= make_tuple(12,'C',"Ghola");
    tuple<char,string,double> p2('V',"GHOLA",12.32);
    //two ways for concat tuples
    auto p3 = tuple_cat(p1,p2);//autodetermine type
    tuple<int,char,string,char,string,double>p4=tuple_cat(p1,p2);//pass type explicity
    cout<<get<0>(p4) <<endl;
    cout<<get<1>(p4) <<endl;
    cout<<get<2>(p4) <<endl;  
    cout<<get<3>(p4) <<endl;
    cout<<get<4>(p4) <<endl;
    cout<<get<5>(p4) <<endl;  





    return 0;    
}