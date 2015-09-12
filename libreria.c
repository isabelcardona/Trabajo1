#include "instrucciones.h"
#include <stdio.h>
#include <math.h>
#include <stdint.h>


void mostrar_registros(unsigned long int regs[12]) // funcion que muestra los registros
                                                   //en la interfaz.
{
    int i;
    for(i=0;i<12;i++)  //el numero de registros totales en este caso 13
    {
        printf(" r%d: %10x", i,regs[i]);
        if((i==2)||(i==5)||(i==8)||(i==11))  //condicion de registros organizados en columnas
        {
            printf("\n");
        }
    }
}
