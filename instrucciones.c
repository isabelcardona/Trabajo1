#include "instrucciones.h"
#include <stdio.h>
#include <math.h>
#include <stdint.h>


 uint32_t flags=0;
uint32_t ands(uint32_t rd, uint32_t  rm)
{
    rd= rd&rm;
    flags=idefbands(rd,rm);
    return rd;
}


uint32_t eors(uint32_t rd,uint32_t rm)
{
    rd=rd^rm;
    flags=idefbands(rd,rm);
    return rd;
}


uint32_t movs(uint32_t rd,uint32_t imm)
{
    rd=imm;
    flags=idefbands(rd,imm);
    return rd;

}
/**
*\esta funcion mueve los archivos pero en realidad la funcion que hace es copiar
*/
 uint32_t orrs(uint32_t rd,uint32_t rm)
{
    rd=rd|rm;
    flags=idefbands(rd,rm);
    return rd;
}


uint32_t subs(uint32_t rd,uint32_t rm)
{
    rd-=rm;
    flags=idefbands(rd,rm);
    return rd;
}
uint32_t LSL(uint32_t rd,uint32_t rm)
{
  rd=rd*2^rm;
  flags=idefbands(rd,rm);
  return rd;
}
uint32_t LSR(uint32_t rd,uint32_t rm)
{
    rd=rd/(2^rm);
    flags=idefbands(rd,rm);
    return rd;
}


uint32_t ADD(uint32_t rd,uint32_t rm)
{
    rd=rd+rm;
    flags=idefbands(rd,rm);
    return rd;
}
uint32_t MUL(uint32_t rd, uint32_t rm)
{
    rd=rd*rm;
    flags=idefbands(rd,rm);
    return rd;
}

uint32_t LSLS(uint32_t rd,uint32_t rm)
{
  rd=rd*2^rm;
  return rd;

}
/**
*\ esta funcion desplaza el registro rd hacia la izquierda las veces que lo indique rm
*/



uint32_t SBC(uint32_t rd, uint32_t rm, uint32_t c)
{
    rd=rd-rm+c;
    flags=idefbands(rd,rm);
    return rd;
}
void NOP(void)
{

}
/**
*\esta funcion desplaza el registro rd hacia la derecha las veces que lo indique rm pero no se multiplica, solo se divide
*/
uint32_t ADC(uint32_t rd,uint32_t rm,uint32_t c)
{

    rd=rd+rm+c;
    return rd;
}
/**
*\esta funcion realiza una suma agregandole la bandera de acarreo
*/
void CMN(uint32_t rd, uint32_t rm)
{
    rd=rd+rm;
    return rd;
}
/**
*\esta funcion realiza la suma aritmetica pero el resultado no lo guarda
*/
void CMP(uint32_t *rd,uint32_t *rm)
{
    *rd=*rd-*rm;
    }
/**
*\esta funcion realiza una resta aritmetica sin guardar el resultado, n no se retorna
*/
void TST(uint32_t rd, uint32_t rm)
{
    rd=rd&rm;
}
/**
*\esta funcion se realiza una operacion AND y su resultado se guarda en n pero no se retorna nada
*/

/**
*esta funcion realiza una suma aritmetica
*/


/**
*\esta funcion realiza una resta agregandole la bandera de acarreo
*/


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
/**
*\esta funcion realiza una operacion AND entre un registro y otro
*/


uint32_t MVN(uint32_t rd,uint32_t rm)
{
    rd=~rm;
    flags=fbands(rd,rm);

    return rd;
}

 uint32_t ASR(uint32_t rd,uint32_t rm, uint32_t c)

{
  uint32_t tem;
    tem=~0>>(32-c);
    tem=tem<<(32-c);
    rd=rm>>c;
    rd=rd|tem;
    flags=idefbands(rd,rm);
    return rd;
}
