#include "instrucciones.h"
#include <stdio.h>
#include <math.h>
#include <stdint.h>


uint32_t ANDS(uint32_t rd, uint32_t  rm, uint32_t* bands)
{
    rd=rd&rm;
    fbands(rd,rm,bands);
    return rd;
}


uint32_t EORS(uint32_t rd,uint32_t rm, uint32_t* bands)
{
    rd=rd^rm;
    fbands(rd,rm,bands);
    return rd;
}


uint32_t MOVS(uint32_t rd,uint32_t imm, uint32_t* bands)  //funcion que copia archivo en otro
{
    rd=imm;
    fbands(rd,imm,bands);
    return rd;

}

 uint32_t ORRS(uint32_t rd,uint32_t rm, uint32_t* bands)
{
    rd=rd|rm;
    fbands(rd,rm,bands);
    return rd;
}


uint32_t SUBS(uint32_t rd,uint32_t rm, uint32_t* bands)
{
    rd-=rm;
    fbands(rd,rm,bands);
    return rd;
}
uint32_t LSLS(uint32_t rd,uint32_t rm, uint32_t imm, uint32_t* bands)
{
  rd=rd<<imm;
  fbands(rd,rm,bands);
  return rd;
}
uint32_t LSRS(uint32_t rd,uint32_t rm, uint32_t imm, uint32_t* bands)
{
    rd=rm>>imm;            //esta función desplaza el registro rd hacia la derecha
    fbands(rd,rm,bands);     //las veces que lo indique rm pero no se multiplica, solo se divide.
    return rd;
}


uint32_t ADDS(uint32_t rd,uint32_t rm, uint32_t* bands)  //esta funcion realiza una suma aritmetica
{
    rd=rd+rm;
    fbands(rd,rm,bands);
    return rd;
}
uint32_t MUL(uint32_t rd, uint32_t rm, uint32_t* bands)
{
    rd=rd*rm;
    fbands(rd,rm,bands);
    return rd;
}


uint32_t SBC(uint32_t rd, uint32_t rm, uint32_t c, uint32_t* bands)
{
    rd=rd-rm+c;
    fbands(rd,rm,bands);
    return rd;
}
void NOP(void) //función que no realiza ninguna operacion
{

}

uint32_t ADCS(uint32_t rd,uint32_t rm,uint32_t c, uint32_t* bands)
{

    rd=rd+rm+c; //esta funcion realiza una suma agregandole la bandera de acarreo
    fbands(rd,rm,bands);
    return rd;
}



void CMN(uint32_t rd, uint32_t rm, uint32_t* bands)
{
    rd=rd+rm;   //esta funcion realiza la suma aritmetica pero el resultado no lo guarda
    fbands(rd,rm,bands);
}

void CMP(uint32_t rd,uint32_t rm, uint32_t* bands)
{
    rd=rd-rm;  //esta funcion realiza una resta aritmetica sin guardar el resultado, n no se retorna
    fbands(rd,rm,bands);
}



void TST(uint32_t rd, uint32_t rm, uint32_t* bands)
{
    rd=rd&rm;   //funcion que realiza una operacion AND y su resultado se guarda en n pero no se retorna nada
    fbands(rd,rm,bands);

}

void REV(uint32_t rd, uint32_t rm, uint32_t* bands)
{
     rd=rm<<24;
     rd=rd|rm>>24;
     rd=rd|((((rm<<8)>>24)<<8)|(((rm<<16)>>24)<<16));
     fbands(rd,rm,bands);

}


uint32_t MVN(uint32_t rd,uint32_t rm, uint32_t* bands)
{
    rd=~rm;
    fbands(rd,rm,bands);
    return rd;
}

void REV16(uint32_t rd,uint32_t rm, uint32_t* bands)
{
     rd=((rm<<24)>>16)|((rm<<16)>>24);
     rm=rd|(((rm>>24)<<16)|((rm>>16)<<24));
     fbands(rd,rm,bands);

}
uint32_t ROR(uint32_t rd, uint32_t rm, uint32_t x, uint32_t* bands)

{
   uint32_t tem, tem1;
    tem=rm>>x;
    tem1=rm<<32;
    x=tem|tem1;
    fbands(rd,rm,bands);

}


uint32_t BIC(uint32_t rd,uint32_t rm, uint32_t* bands)
{
     rd&=~rm;
    fbands(rd,rm,bands);
    return rd;
}

uint32_t ASR(uint32_t rd,uint32_t rm, uint32_t x, uint32_t* bands)
{
  uint32_t tem; //variable temporal
    tem=~0>>(32-x);
    tem=tem<<(32-x);
    rd=rm>>x;
    rd=rd|tem;
    fbands(rd,rm,bands);
    return rd;
}
