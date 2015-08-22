#include "libreria.h"

void mostrar_registros(unsigned long int regs[12])
{
    int i;
    for(i=0;i<12;i++)
    {
        printf(" r%d: %10x", i,regs[i]);
        if((i==2)||(i==5)||(i==8)||(i==11))
        {
            printf("\n");
        }
    }
}
