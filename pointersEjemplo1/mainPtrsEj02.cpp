#include <iostream>

using namespace std;

int a=5,b=8,c=2;

int *myPtr;

int main()
{
    myPtr=&a;

    *myPtr=13;

    c=*myPtr+*(myPtr+1);

    cout << "c = " << c << endl;
    return 0;
}
