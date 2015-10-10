#include <math.h>
#include <stdint.h>

void NVIC(uint32_t* interrup_regs, uint32_t* flash_mem, uint32_t* regs, uint32_t* bands, uint32_t* mem)
{
    int i=0;
    for(i=0;i<32;i++)
    {
        if(interrup_regs[i]==1){
            mem[0]=regs[15];
            mem[1]=bands[0];
            mem[2]=bands[1];
            mem[3]=bands[2];
            mem[4]=bands[3];
            mem[5]=regs[0];
            mem[6]=regs[1];
            mem[7]=regs[2];
            mem[8]=regs[3];
            mem[9]=regs[12];
            mem[10]=regs[14];
        }
        //En esta parte se ejecuta la instruccion de la interrupcion;
        if(regs[14]==0xfffffff){
            regs[15]=mem[0];
            bands[0]=mem[1];
            bands[1]=mem[2];
            bands[2]=mem[3];
            bands[3]=mem[4];
            regs[0]=mem[5];
            regs[1]=mem[6];
            regs[2]=mem[7];
            regs[3]=mem[8];
            regs[12]=mem[9];
            regs[14]=mem[10];
        }
    }
}
