#include "instrucciones.h"
#include <stdio.h>
#include <math.h>


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
unsigned long int LSL(unsigned long int rd,unsigned long int rm);
{
  rd=rd*2^rm;
  return rd;

}
unsigned long int LSR(unsigned long int rd,unsigned long int rm);
{
    rd=rd/(2^rm);
    return a;

}
unsigned long int ADC(unsigned long int rd,unsigned long int rm,unsigned long int c);
{

    rd=rd+rm+c;
}
void CMN(unsigned long int rd, unsigned long int rm);
{
    n=rd+rm;
}
void CMP(unsigned long int rd,unsigned long int rm);
{
    n=rd-rm;
}
void TST(unsigned long int rd, unsigned long int rm);
{
    n=rd&rm;
}
unsigned long int ADD(unsigned long int rd,unsigned long int rm);
{
    rd=rd+rm;
    return rd;
}
unsigned long int MUL(unsigned long int rd, unsigned long int rm);
{
    rd=rd*rm;
    return rd;
}
unsigned long int SBC(unsigned long int rd, unsigned long int rm, unsigned long int c);
{
    rd=rd-rm+c;
}
unsigned long int NOP(unsigned long int rd, unsigned long int rm);


void REV(unsigned long int rd, unsigned long int rm);
{
     rd=Rm<<24;
     rd=rd|Rm>>24;
     rd=rd|((((rm<<8)>>24)<<8)|(((rm<<16)>>24)<<16));

}

void REV16(unsigned long int rd,unsigned long int rm);
{
     rd=((rm<<24)>>16)|((rm<<16)>>24);
     rm=rd|(((rm>>24)<<16)|((rm>>16)<<24));
}
unsigned long int ROR(unsigned long int rd, unsigned long int rm, unsigned long int c)

{
    unsigned long int tem, tem1;
    tem=rm>>c;
    tem1=rm<<(32−c);
    c=tem|tem1;
}

unsigned long int BIC(unsigned long int rd, unsigned long int rm);
{
     rd&=~rm;
    return rd;
}

unsigned long int MVN(unsigned long int rd,unsigned long int rm);
{
    rd=~rm;
    return rd;
}

 unsigned long int ASR(unsigned long int rd,unsigned long int rm, unsigned long int c);
{
    unsigned int tem;
    tem=~0>>(32-c);
    tem=tem<<(32-c);
    rd=rn>>c;
    rd=rd|tem;

}
