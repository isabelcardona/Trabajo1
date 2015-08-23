#include <stdio.h>
#include <stdlib.h>
#include "instrucciones.h"
#include "libreria.h"

int main()
{
long int regs[13];
long int rd,rm,imm;
mostrar_registros(regs);
eors(rd,rm);
movs(rd,imm);
orrs(rd,rm);
subs(rd,rm);

}

