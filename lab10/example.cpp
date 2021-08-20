 #include <iostream>
 using namespace std;

 struct StructA
 {
 StructA() {cout << "StructA constructor" << endl; }
 ~StructA() {cout << "StructA destructor" << endl; }
 };

 struct StructB
 {
 StructB() {cout << "StructB constructor" << endl; }
 ~StructB() {cout << "StructB destructor" << endl; }
 };

 void FuncB() // throws
 {
    cout << "In Func B" << endl;
    StructA objA;
    StructB objB;
    cout << "About to throw up!" << endl;
    throw "Throwing for the heck of it";
 }

 void FuncA()
 {
    try
    {
        cout << "In Func A" << endl;
        //mueren estas estructuras
        // cuando se ejecute el catch
        //
        StructA objA;
        StructB objB;
        FuncB();
        cout << "Fun returning to caller" << endl;//no ejecuta
    }
    catch(const char* exp)
    {
        cout << "Fun Caught excepti " << exp << endl;
        cout << "Handled it, will not throw to caller" << endl;
        // throw; // uncomment this line to throw to main()
    }
 }

 int main()
 {
    cout << "main Started execution" << endl;
    try
    {
        FuncA();
    }
    catch(const char* exp)
    {
        cout << "Excepti " << exp << endl;
    }
    cout << "main exiting gracefully" << endl;
    return 0;
 }

/*
main(): Started execution
In Func A
StructA constructor
StructB constructor
In Func B
StructA constructor
StructB constructor
About to throw up! ----
StructB destructor 2do en ser created
StructA destructor 1ro en ser creado
StructB destructor 2do en ser created
StructA destructor 1ro en ser created
FuncA: Caught exception: Throwing for the heck of it
Handled it, will not throw to caller
main(): exiting gracefully
*/