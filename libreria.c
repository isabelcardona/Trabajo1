#include "libreria.h"

void mostrar_registros(long int regs[13])
{
    int i;
    for(i=0;i<13;i++)
    {
        printf(" r%d: %10x", i,regs[i]);
        if((i==2)||(i==5)||(i==8)||(i==11))
        {
            printf("\n");
        }
    }
}
