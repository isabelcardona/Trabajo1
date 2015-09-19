#include <stdio.h>
#include <stdlib.h>
#include "instrucciones.h"

#include <math.h>

<<<<<<< HEAD
void fbands(uint32_t rd,uint32_t rm) /** esta es la funcion que identifica las banderas*/
{
    uint32_t bands[4]={0};
    if(rd>2147483648) /**bandera de negativo*/
    {
        bands[0]=1;
    }
    if(rd=0) /**bandera de cero*/
    {
        bands[1]=1;
    }
    if(rd>4294967296) /**bandera de carry*/
    {
        bands[2]=1;
    }
    if(((rd&&rm)>=2147483648)&&((rd+rm)<2147483648)) /**bandera de sobreflujo*/
=======
void fbands(uint32_t rd, uint32_t rm, uint32_t* bands) // esta es parte de la estructura de las banderas
{
    if(rd>2147483647) //bandera de negativo
    {
        bands[0]=1;
    }
    else{
        bands[0]=0;
    }
    if(rd==0) //bandera de cero
    {
        bands[1]=1;
    }
    else{
        bands[1]=0;
    }
    if(rd>=4294967295) //bandera de carry
    {
        bands[2]=1;
    }
    else{
        bands[2]=0;
    }
    if(((rd&&rm)>=2147483648)&&((rd+rm)<2147483648)) //bandera de sobreflujo
>>>>>>> 8cb513235e6436d6163cdc9eeb515e60dbeef585
    {
        bands[3]=1;
    }
    else{
        bands[3]=0;
    }
}
