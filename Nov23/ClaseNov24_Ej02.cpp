#include <iostream>

using namespace std;

int x[4] = {28,41,7,15};
int y[3] = {5,10,9};
int *p1 = x;
int *p2 = y;

int a;
int i=1;
int j=2;

int main()
{
    a=p1[i] ;
    if (p1[j]>5)
    {
        a=a+p2[i];
    }
    else
    {
        a=a+p1[i+2];
    }
    a=a+y[i+1];

    cout<< a <<endl;
    cout << "Hello world!" << endl;
    return 0;
}
