#include "instrucciones.h"
#include <stdio.h>
#include <math.h>


unsigned long int ands(unsigned long int rd, unsigned long int rm)
{
    rd= rd&rm;
    flags=idefbands(rd,rm);
    return rd;
}


unsigned long int eors(unsigned long int rd,unsigned long int rm)
{
    rd=rd^rm;
    flags=idefbands(rd,rm);
    return rd;
}


unsigned  long int movs(unsigned long int rd, unsigned long int rd, unsigned long int imm)
{
    rd=imm;
    flags=idefbands(rd,rm);
    return rd;

}
/**
*\esta funcion mueve los archivos pero en realidad la funcion que hace es copiar
*/
 unsigned long int orrs(unsigned long int rd,unsigned long int rm)
{
    rd=rd|rm;
    flags=idefbands(rd,rm);
    return rd;
}


unsigned long int subs(unsigned long int rd,unsigned long int rm)
{
    rd-=rm;
    flags=idefbands(rd,rm);
    return rd;
}
unsigned long int LSL(unsigned long int rd,unsigned long int rm);
{
  rd=rd*2^rm;
  flags=idefbands(rd,rm);
  return rd;
}
unsigned long int LSR(unsigned long int rd,unsigned long int rm);
{
    rd=rd/(2^rm);
    flags=idefbands(rd,rm);
    return a;
}
unsigned long int ADC(unsigned long int rd,unsigned long int rm,unsigned long int c);
{
    rd=rd+rm+c;
    flags=idefbands(rd,rm);
    return rd;
}
void CMN(unsigned long int rd, unsigned long int rm);
{
    n=rd+rm;
    flags=idefbands(rd,rm);
}
void CMP(unsigned long int rd,unsigned long int rm);
{
    n=rd-rm;
    flags=idefbands(rd,rm);
}
void TST(unsigned long int rd, unsigned long int rm);
{
    n=rd&rm;
    flags=idefbands(rd,rm);
}
unsigned long int ADD(unsigned long int rd,unsigned long int rm);
{
    rd=rd+rm;
    flags=idefbands(rd,rm);
    return rd;
}
unsigned long int MUL(unsigned long int rd, unsigned long int rm);
{
    rd=rd*rm;
    flags=idefbands(rd,rm);
    return rd;
}

unsigned long int LSL(unsigned long int rd,unsigned long int rm);
{
  rd=rd*2^rm;
  return rd;

}
/**
*\esta funcion desplaza el registro rd hacia la izquierda las veces que lo indique rm
*/
unsigned long int LSR(unsigned long int rd,unsigned long int rm);
{
    rd=rd/(2^rm);
    return a;

unsigned long int SBC(unsigned long int rd, unsigned long int rm, unsigned long int c);
{
    rd=rd-rm+c;
    flags=idefbands(rd,rm);
    return rd;
}
void NOP(unsigned long int rd, unsigned long int rm);


}
/**
*\esta funcion desplaza el registro rd hacia la derecha las veces que lo indique rm pero no se multiplica, solo se divide
*/
unsigned long int ADC(unsigned long int rd,unsigned long int rm,unsigned long int c);
{

<<<<<<< HEAD
    rd=rd+rm+c;
}
/**
*\esta funcion realiza una suma agregandole la bandera de acarreo
*/
void CMN(unsigned long int rd, unsigned long int rm);
{
    n=rd+rm;
}
/**
*\esta funcion realiza la suma aritmetica pero el resultado no lo guarda
*/
void CMP(unsigned long int rd,unsigned long int rm);
{
    n=rd-rm;
}
/**
*\esta funcion realiza una resta aritmetica sin guardar el resultado, n no se retorna
*/
void TST(unsigned long int rd, unsigned long int rm);
{
    n=rd&rm;
}
/**
*\esta funcion se realiza una operacion AND y su resultado se guarda en n pero no se retorna nada
*/
unsigned long int ADD(unsigned long int rd,unsigned long int rm);
{
    rd=rd+rm;
    return rd;
}
/**
*\esta funcion realiza una suma aritmetica
*/
unsigned long int MUL(unsigned long int rd, unsigned long int rm);
{
    rd=rd*rm;
    return rd;
}
unsigned long int SBC(unsigned long int rd, unsigned long int rm, unsigned long int c);
{
    rd=rd-rm+c;
}
/**
*\esta funcion realiza una resta agregandole la bandera de acarreo
*/
unsigned long int NOP(unsigned long int rd, unsigned long int rm);


void REV(unsigned long int rd, unsigned long int rm);
{
     rd=Rm<<24;
     rd=rd|Rm>>24;
     rd=rd|((((rm<<8)>>24)<<8)|(((rm<<16)>>24)<<16));

}


void REV(unsigned long int rd, unsigned long int rm);
{
     rd=Rm<<24;
     rd=rd|Rm>>24;
     rd=rd|((((rm<<8)>>24)<<8)|(((rm<<16)>>24)<<16));
     flags=idefbands(rd,rm);
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
unsigned long int ROR(unsigned long int rd, unsigned long int rm, unsigned long int c)
{
    unsigned long int tem, tem1;
    tem=rd>>c;
    tem1=rd<<(32−c);
    c=tem|tem1;
    flags=idefbands(rd,rm);
    return c;

}

unsigned long int BIC(unsigned long int rd, unsigned long int rm);
{
     rd&=~rm;

    return rd;
}
/**
*\esta funcion realiza una operacion AND entre un registro y otro
*/
unsigned long int MVN(unsigned long int rd,unsigned long int rm);
{
    rd=~rm;
     flags=idefbands(rd,rm);
    return rd;
}

unsigned long int MVN(unsigned long int rd,unsigned long int rm);
{
    rd=~rm;
    flags=idefbands(rd,rm);

    return rd;
}

 unsigned long int ASR(unsigned long int rd,unsigned long int rm, unsigned long int c);

{
    unsigned int tem;
    tem=~0>>(32-c);
    tem=tem<<(32-c);
    rd=rn>>c;
    rd=rd|tem;
    flags=idefbands(rd,rm);
    return rd;
}
