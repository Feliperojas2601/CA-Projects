#include <iostream>

using namespace std;

int array1[5] = {3, 1, 5, 7, 9};
int array2[4] = {3, 1, 5, 9};
int i;
int result;

int main()
{
    //proceso para hallar el numero que falta en el array2 con respecto al array1
    asm("movl $0, _i");
    asm("initfor1:");
    asm("cmpl $5, _i");
    asm("jnl endfor1");
    //for (i=0; i<5; i++)
    //{
        //result = result^array1[i];
        asm("mov _i, %edx");
        asm("mov _array1(,%edx,4),%edx");
        asm("xor %edx, _result");
        asm("addl $1, _i");
        asm("jmp initfor1");
    //}
    asm("endfor1:");
    asm("movl $0, _i");
    asm("initfor2:");
    asm("cmpl $4, _i");
    asm("jnl endfor2");


    //for (i=0; i<4; i++)
    //{
        //result = result^array2[i];
        asm("mov _i, %edx");
        asm("mov _array2(,%edx,4),%edx");
        asm("xor %edx, _result");
        asm("addl $1, _i");
        asm("jmp initfor2");
    //}
    asm("endfor2:");

    cout <<"Numero faltante: " << result << endl;
    cout << "Hello world" <<endl;
    return 0;
}
