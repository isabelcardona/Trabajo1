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


unsigned long int ROR (unsigned long int rd, unsigned long int rm, unsigned long int c)
  {
    unsigned long int tem, tem1;
    tem=rm>>c;
    tem1=rm<<(32−c);
    c=tem|tem1;
    }

unsigned long int Bic (unsigned long int rd, unsigned long int rm)
    {
     rd&=~rm;
    return rd;
    }

    unsigned long int Mvn(unsigned long int rd,unsigned long int rm)
{
    rd=~rm;
    return rd;
}

 unsigned long int ASR (unsigned long int rd,unsigned long int rm, unsigned long int c)

    {


    unsigned int tem;
    tem=~0>>(32-c);
    tem=tem<<(32-c);
    Rd=Rn>>c;
    Rd=Rd|tem;

    }


