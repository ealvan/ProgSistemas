#include <iostream>
#include <csignal>
 
using namespace std;

sig_atomic_t signalled = 0;

void handler(int sig)
{
    signalled = 1;
}

int main()
{
    signal(SIGINT, handler);
    
    raise(SIGINT);
    if (signalled)
        cout << "Signal is handled";
    else
        cout << "Signal is not handled";

    return 0;
}