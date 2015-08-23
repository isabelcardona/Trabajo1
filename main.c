#include <stdio.h>
#include <stdlib.h>
#include "instrucciones.h"
#include "libreria.h"

int main()
{
<<<<<<< HEAD
long int regs[13];
long int rd,rm,imm;
mostrar_registros(regs);
eors(rd,rm);
movs(rd,imm);
orrs(rd,rm);
subs(rd,rm);

=======
    unsigned long int regs[12];
    mostrar_registros(regs);
>>>>>>> 30b42e4f09246222cba5759d5daa0e83e1ce138e
}

