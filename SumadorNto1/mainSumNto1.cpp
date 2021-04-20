#include <iostream>

using namespace std;

int n=5;
int sum=0;

int main()
{
    while (n!=0)
    {
        sum=sum+n;
        n=n-1;
    }

    cout << "sum = " << sum<<endl;
    return 0;
}
