#include <stdio.h>
#include <stdlib.h>
#include "instrucciones.h"
#include "libreria.h"
#include <math.h>
#include <stdint.h>
int main()
{
///<<<<<<< HEAD
uint32_t regs[12];
uint32_t rd,rm,imm,r;
mostrar_registros(regs);
rd=10;
rm=6;
CMP(&rd,&rm);
printf("%d",rd);


///=======
   /* unsigned long int regs[12];
    mostrar_registros(regs);*/
///>>>>>>> 30b42e4f09246222cba5759d5daa0e83e1ce138e
}

