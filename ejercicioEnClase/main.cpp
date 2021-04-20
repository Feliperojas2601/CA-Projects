#include <iostream>

using namespace std;

int x[] = {1,2,3,4,5};
int y[] = {6,7,8,9};

int *p1 = x;
int *p2 = y;

int a;
int b;
int c;
int i;

int main()
{
    a = p1[1];
    b = x[3];
    c = a + b;

    i = 2;

    c = c + p2[i];

    cout << c << endl;
    return 0;
}
