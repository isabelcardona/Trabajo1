#include "instrucciones.h"



unsigned long int ands(long int rd, long int rm)
{
    rd= rd&rm;
    return rd;
}


unsigned long int eors(long int rd,long int rm)
{
    rd=rd^rm;
    return rd;
}


unsigned  long int movs(long int rd,long int imm)
{
    rd=imm;
    return rd;

}
 unsigned long int orrs(long int rd,long int rm)
{
    rd=rd|rm;
    return rd;
}


unsigned long int subs(long int rd,long int rm)
{
    rd-=rm;
    return rd;
}



