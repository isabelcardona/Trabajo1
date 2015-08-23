#include "libreria.h"

<<<<<<< HEAD
void mostrar_registros(long int regs[13])
=======
void mostrar_registros(unsigned long int regs[12])
>>>>>>> 30b42e4f09246222cba5759d5daa0e83e1ce138e
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
