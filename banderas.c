#include <stdio.h>
#include <stdlib.h>
#include "instrucciones.h"

#include <math.h>

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
    {
        bands[3]=1;
    }
    return bands;
}
