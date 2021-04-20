#include <iostream>

using namespace std;

int a[3]={5,7,2};
int i;
int result=0;

int main()
{

    for(i=0;i<3;i++)
    {
        result=result+a[i];
    }

    cout << result <<endl;
    cout << "Hello world" <<endl;
    return 0;
}
