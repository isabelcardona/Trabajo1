#include "instrucciones.h"

unsigned long int ands(unsigned long int rd, unsigned long int rm)
{
    rd= rd&rm;
    return rd;
}


unsigned long int eors(unsigned long int rd,unsigned long int rm)
{
    rd=rd^rm;
    return rd;
}


unsigned  long int movs(unsigned long int rd,unsigned long int imm)
{
    rd=imm;
    return rd;

}
 unsigned long int orrs(unsigned long int rd,unsigned long int rm)
{
    rd=rd|rm;
    return rd;
}


unsigned long int subs(unsigned long int rd,unsigned long int rm)
{
    rd-=rm;
    return rd;
}



