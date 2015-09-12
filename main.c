#include <stdio.h>
#include <stdlib.h>
#include "instrucciones.h"
#include "libreria.h"
#include <math.h>
#include <stdint.h>
int main()
{
uint32_t regs[12]; //funcion de los registros
uint32_t rd,rm,imm,r;
mostrar_registros(regs);
rd=10;
rm=6;
CMP(&rd,&rm);
printf("%d",rd);

}

