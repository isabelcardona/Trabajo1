#include <stdio.h>
#include <stdlib.h>
#include "instrucciones.h"

#include <math.h>

uint32_t idefbands(uint32_t rd,uint32_t rm)
{
    uint32_t bands[4]={0};
    if(rd>2147483648)
    {
        bands[0]=1;
    }
    if(rd=0)
    {
        bands[1]=1;
    }
    if(rd>4294967296)
    {
        bands[2]=1;
    }
    if(((rd&&rm)>=2147483648)&&((rd+rm)<2147483648))
    {
        bands[3];
    }
        return bands;
}
