#include "instrucciones.h"
#include <stdio.h>
#include <math.h>
#include <stdint.h>


uint32_t flags=0; //funcion de banderas, valor inicial
uint32_t ands(uint32_t rd, uint32_t  rm)
{
    rd= rd&rm;
    flags=fbands(rd,rm);
    return rd;
}


uint32_t eors(uint32_t rd,uint32_t rm)
{
    rd=rd^rm;
    flags=idefbands(rd,rm);
    return rd;
}


uint32_t movs(uint32_t rd,uint32_t imm)  //funcion que copia archivo en otro
{
    rd=imm;
    flags=fbands(rd,imm);
    return rd;

}

 uint32_t orrs(uint32_t rd,uint32_t rm)
{
    rd=rd|rm;
    flags=fbands(rd,rm);
    return rd;
}


uint32_t subs(uint32_t rd,uint32_t rm)
{
    rd-=rm;
    flags=fbands(rd,rm);
    return rd;
}
uint32_t LSL(uint32_t rd,uint32_t rm)
{
  rd=rd*2^rm;
  flags=fbands(rd,rm);
  return rd;
}
uint32_t LSR(uint32_t rd,uint32_t rm)
{
    rd=rd/(2^rm);            //esta función desplaza el registro rd hacia la derecha
    flags=fbands(rd,rm);     //las veces que lo indique rm pero no se multiplica, solo se divide.
    return rd;
}


uint32_t ADD(uint32_t rd,uint32_t rm)  //esta funcion realiza una suma aritmetica
{
    rd=rd+rm;
    flags=fbands(rd,rm);
    return rd;
}
uint32_t MUL(uint32_t rd, uint32_t rm)
{
    rd=rd*rm;
    flags=fbands(rd,rm);
    return rd;
}

uint32_t LSLS(uint32_t rd,uint32_t rm)
{
  rd=rd*2^rm;   // esta funcion desplaza el registro rd hacia la izquierda las veces que lo indique rm

  return rd;

}

uint32_t SBC(uint32_t rd, uint32_t rm, uint32_t c)
{
    rd=rd-rm+c;
    flags=idefbands(rd,rm);
    return rd;
}
void NOP(void) //función que no realiza ninguna operacion
{

}

uint32_t ADC(uint32_t rd,uint32_t rm,uint32_t c)
{

    rd=rd+rm+c;     //esta funcion realiza una suma agregandole la bandera de acarreo
    return rd;
}



void CMN(uint32_t rd, uint32_t rm)
{
    rd=rd+rm;   //esta funcion realiza la suma aritmetica pero el resultado no lo guarda

}

void CMP(uint32_t *rd,uint32_t *rm)
{
    *rd=*rd-*rm;  //esta funcion realiza una resta aritmetica sin guardar el resultado, n no se retorna
}



void TST(uint32_t rd, uint32_t rm)
{
    rd=rd&rm;   //funcion que realiza una operacion AND y su resultado se guarda en n pero no se retorna nada

}

void REV(uint32_t rd, uint32_t rm)
{
     rd=rm<<24;
     rd=rd|rm>>24;
     rd=rd|((((rm<<8)>>24)<<8)|(((rm<<16)>>24)<<16));

}


uint32_t Bic (uint32_t rd, uint32_t rm)
    {
     rd&=~rm;
    return rd;
    }

uint32_t Mvn(uint32_t rd,uint32_t rm)
{
    rd=~rm;
    return rd;
}

void REV16(uint32_t rd,uint32_t rm)
{
     rd=((rm<<24)>>16)|((rm<<16)>>24);
     rm=rd|(((rm>>24)<<16)|((rm>>16)<<24));

}
uint32_t ROR(uint32_t rd, uint32_t rm, uint32_t c)

{
   uint32_t tem, tem1;
    tem=rm>>c;
    tem1=rm<<32;
    c=tem|tem1;

}


uint32_t BIC(uint32_t rd,uint32_t rm)
{
     rd&=~rm;

    return rd;
}

uint32_t MVN(uint32_t rd,uint32_t rm)
{
    rd=~rm;
    flags=fbands(rd,rm);

    return rd;
}

uint32_t ASR(uint32_t rd,uint32_t rm, uint32_t c)

{
  uint32_t tem; //variable temporal
    tem=~0>>(32-c);
    tem=tem<<(32-c);
    rd=rm>>c;
    rd=rd|tem;
    flags=fbands(rd,rm);
    return rd;
}
