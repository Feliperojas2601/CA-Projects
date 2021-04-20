#include <iostream>

using namespace std;

int a[3]={5,7,2};
int i;
int mayor=0;

int main()
{

    for(i=0;i<3;i++)
    {
        if (a[i]>mayor)
        {
            mayor=a[i];
        }
    }

    cout << mayor <<endl;
    cout << "Hello world" <<endl;
    return 0;
}
