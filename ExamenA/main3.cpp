#include <iostream>

using namespace std;

int array1[5] = {3, 1, 5, 7, 9};
int array2[4] = {3, 1, 5, 9};
int i;
int result;

int main()
{
    //proceso para hallar el numero que falta en el array2 con respecto al array1

    for (i=0; i<5; i++)
    {
        result = result^array1[i];
    }
    for (i=0; i<4; i++)
    {
        result = result^array2[i];
    }

    cout <<"Numero faltante: " << result << endl;
    cout << "Hello world" <<endl;
    return 0;
}
