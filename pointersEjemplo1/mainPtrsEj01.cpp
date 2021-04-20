#include <iostream>

using namespace std;

int a=5,b=8,c=2;   //a: 05 00 00 00, b: 08 00 00 00, c = 02 00 00 00

int *myPtr1,*myPtr2;

int main()
{
    myPtr1=&a;

    *myPtr1=13;

    myPtr2=&b;

    c=*myPtr1+*myPtr2;

    cout << "c = " << c << endl;
    return 0;
}
