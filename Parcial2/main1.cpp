#include <iostream>

using namespace std;

int x[4] = {28,41,7,15};
int y[4] = {37,23,6,11};
int *p1 = x;
int *p2 = y;

int a;
int b;
int i=1;
int j=1;

int main()
{
    a=p1[i] ;
    b=y[j+1];

    if (p2[j]<15)
    {
        a=a+p2[i];
        a=a-p1[2];

    }
    else
    {
        a=a+p2[j+2];
        a=a-b;
    }

    a=a+y[0];

    cout<< a <<endl;
    cout << "Hello world!" << endl;
    return 0;
}
