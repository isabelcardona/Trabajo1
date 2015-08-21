#include "instrucciones.h"


long int ands(long int rd, long int rm)
{
    rd= rd&rm;
}
return rd;

long int eors(long int rd,long int rm)
{
    rd=rd^rm;
}
return rd;

long int movs(long int rd,long int imm)
{
    rd=imm;
}
return rd;

long int orrs(long int rd,long int rm)
{
    rd=rd|rm;
}
return rd;

long int subs(long int rd,long int rn,long int rm)
{
    rd=rn-=rm;
}
return rd;

