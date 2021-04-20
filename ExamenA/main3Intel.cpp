#include <iostream>

using namespace std;

int array1[5] = {3, 1, 5, 7, 9};
int array2[4] = {3, 1, 5, 9};
int i;
int result;

int main()
{
    //proceso para hallar el numero que falta en el array2 con respecto al array1
    asm("mov dword ptr [_i], 0");
    asm("initfor1:");
    asm("cmp dword ptr [_i],5");
    asm("jnl endfor1");
    //for (i=0; i<5; i++)
    //{
        //result = result^array1[i];
        asm("mov edx, [_i]");
        asm("mov edx, [_array1+edx*4]");
        asm("xor [_result],edx");
        asm("add dword ptr [_i],1");
        asm("jmp initfor1");
    //}
    asm("endfor1:");
    asm("mov dword ptr [_i], 0");
    asm("initfor2:");
    asm("cmp dword ptr [_i],4");
    asm("jnl endfor2");

    //for (i=0; i<4; i++)
    //{
        //result = result^array2[i];
        asm("mov edx, [_i]");
        asm("mov edx, [_array2+edx*4]");
        asm("xor [_result],edx");
        asm("add dword ptr [_i],1");
        asm("jmp initfor2");
    //}
    asm("endfor2:");

    cout <<"Numero faltante: " << result << endl;
    cout << "Hello world" <<endl;
    return 0;
}
