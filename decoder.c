#include "decoder.h"
#include "banderas.h"
#include "instrucciones.h"
#include "libreria.h"

char tipo1, tipo2, tipo3, *ptr, *xp; 
uint32_t Rd, Rm,a, b, c, temp, aux[16];
int x=0, i, j, p=0;



void decodeInstruction(instruction_t instruction, uint32_t* regs, uint32_t* bands, uint32_t* mem, uint32_t* address, uint32_t* addr, uint32_t* flash_mem, uint32_t* addr_flash, uint32_t* in_out, uint32_t* addr_inout)
{
    ptr=aux; 
    xp=regs;  /* puntero tipo caracter para guardar de 1 a 4 bytes de un registro*/

/* condiciones para las instrucciones de salto*/
    if( (strcmp(instruction.mnemonic,"B") == 0)){      
            regs[15]=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BX") == 0)){
            if(instruction.op1_type=='L'){
                temp=regs[14];
                regs[15]=temp;
            }
    else{
            regs[15]=instruction.op1_value;
    }
    }

    if( (strcmp(instruction.mnemonic,"BL") == 0)){
            regs[14]=regs[15]+1;
            if(instruction.op1_type=='#'){
                regs[15]=instruction.op1_value;
            }
            if(instruction.op1_type=='R'){
                regs[15]=regs[instruction.op1_value];
            }
    }
    if( (strcmp(instruction.mnemonic,"BLX") == 0)){
            uint32_t temp;
            temp=regs[14];
            regs[14]=regs[15]+1;
            if(instruction.op1_type=='#'){
                regs[15]=instruction.op1_value;
            }
            if(instruction.op1_type=='R'){
                regs[15]=regs[instruction.op1_value];
            }
            if(instruction.op1_type=='L'){
                regs[15]=temp;
            }
    }

    if( (strcmp(instruction.mnemonic,"BEQ") == 0) && (bands[1]==1)){
            regs[15]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BNE") == 0) && (bands[1]==0)){
            regs[15]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BCS") == 0) && (bands[2]==1)){
            regs[15]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BCC") == 0) && (bands[2]==0)){
            regs[15]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BMI") == 0) && (bands[0]==1)){
            regs[15]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BPL") == 0) && (bands[0]==0)){
            regs[15]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BVS") == 0) && (bands[3]==1)){
            regs[15]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BVC") == 0) && (bands[3]==0)){
            regs[15]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BHI") == 0) && (bands[2]==1) && (bands[1]==0)){
            regs[15]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BLS") == 0) && (bands[2]==0) && (bands[1]==1)){
            regs[15]+=instruction.op1_value;
    }
    if( (strcmp(instruction.mnemonic,"BGE") == 0) && (bands[0]==bands[3])){
            regs[15]+=instruction.op1_value;
    }
    if( (strcmp(instruction.mnemonic,"BLT") == 0) && (bands[0]!=bands[3])){
            regs[15]+=instruction.op1_value;
    }
    if( (strcmp(instruction.mnemonic,"BGT") == 0) && (bands[1]==0) && (bands[0]==bands[3])){
            regs[15]+=instruction.op1_value;
    }
    if( (strcmp(instruction.mnemonic,"BLE") == 0) && (bands[1]==0) && (bands[0]!=bands[3])){
            regs[15]+=instruction.op1_value;
    }
    if( (strcmp(instruction.mnemonic,"BAL") == 0) ){
            regs[15]+=instruction.op1_value;
    }


    if( strcmp(instruction.mnemonic,"CMP") == 0 ){
        move(4,0);
        printw("CMP ");
        refresh();
		a=instruction.op1_value; //--> Valor primer operando
		tipo1=instruction.op1_type;  //--> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		b=instruction.op2_value; //--> Valor primer operando
		tipo2=instruction.op2_type;
		// ... Igual para los otros operandos
		Rd=regs[a];
		Rm=regs[b];
		CMP(Rd,Rm,bands);
	}
    if( strcmp(instruction.mnemonic,"MOVS") == 0 ){
        move(4,0);
        printw("MOVS");
        refresh();
		a=instruction.op1_value; //--> Valor primer operando
		tipo1=instruction.op1_type;  //--> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		b=instruction.op2_value; //--> Valor primer operando
		tipo2=instruction.op2_type;
		c=instruction.op3_value; //--> Valor primer operando
		tipo3=instruction.op3_type;
		// ... Igual para los otros operandos
		Rd=regs[a];  /* asignacion del primer operando*/
		Rm=regs[b];  /* asignacion del segundo operando*/
		if(tipo2=='#'){   
        temp=bands[3];
		Rd=MOVS(Rd,b,bands);
		regs[a]=Rd;
		bands[3]=temp;
		}
		if(tipo2=='R'){
		Rd=MOVS(Rd,Rm,bands);
		temp=bands[3];
		regs[a]=Rd;
		bands[3]=temp;
		}
	}
	if( strcmp(instruction.mnemonic,"ADCS") == 0 ){    /* funcion de suma con carry*/
	    move(4,0);
        printw("ADCS");
        refresh();
		a=instruction.op1_value; //--> Valor primer operando
		tipo1=instruction.op1_type;  //--> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		b=instruction.op2_value; //--> Valor primer operando
		tipo2=instruction.op2_type;
		c=instruction.op3_value; //--> Valor primer operando
		tipo3=instruction.op3_type;
		// ... Igual para los otros operandos
		if(tipo3=='N'){
		Rd=regs[a];
		Rm=regs[b];
		temp=bands[3];
		Rd=ADCS(Rd,Rm,1,bands);
		bands[3]=temp;
		regs[a]=Rd;
		}
		else{
		Rd=regs[b];
		Rm=regs[c];
		Rd=ADCS(Rd,Rm,1,bands);
		regs[b]=Rd;
		}
	}
	if( strcmp(instruction.mnemonic,"LSLS") == 0 ){  /* corrimiento hacia la izquierda */
	    move(4,0);
        printw("LSLS");
        refresh();
		a=instruction.op1_value; //--> Valor primer operando
		tipo1=instruction.op1_type;  //--> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		b=instruction.op2_value; //--> Valor primer operando
		tipo2=instruction.op2_type;
		c=instruction.op3_value;
		tipo3=instruction.op2_type;
		// ... Igual para los otros operandos
		Rd=regs[a];
		Rm=regs[b];
		Rd=LSLS(Rd,Rm,c,bands);
		regs[a]=Rd;
	}
	if( strcmp(instruction.mnemonic,"ADDS") == 0 ){   /* suma aritmetica*/
	    move(4,0);
        printw("ADDS");
        refresh();
		a=instruction.op1_value; //--> Valor primer operando
		tipo1=instruction.op1_type;  //--> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		b=instruction.op2_value; //--> Valor primer operando
		tipo2=instruction.op2_type;
		c=instruction.op3_value; //--> Valor primer operando
		tipo3=instruction.op3_type;
		// ... Igual para los otros operandos
		if(tipo3=='N'){
		Rd=regs[a];
		Rm=regs[b];
		Rd=ADDS(Rd,Rm,bands);
		regs[a]=Rd;
		}
		else{
		Rd=regs[b];
		Rm=regs[c];
		Rd=ADDS(Rd,Rm,bands);
		regs[b]=Rd;
		}
	}
	if( strcmp(instruction.mnemonic,"SUBS") == 0 ){  /* resta aritmetica */
	    move(4,0);
        printw("SUBS");
        refresh();
		a=instruction.op1_value; //--> Valor primer operando
		tipo1=instruction.op1_type;  //--> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		b=instruction.op2_value; //--> Valor primer operando
		tipo2=instruction.op2_type;
		c=instruction.op3_value; //--> Valor primer operando
		tipo3=instruction.op3_type;
		// ... Igual para los otros operandos
		if(tipo3=='N'){
		Rd=regs[a];
		Rm=regs[b];
		Rd=SUBS(Rd,Rm,bands);
		regs[a]=Rd;
		}
		else{
		Rd=regs[b];
		Rm=regs[c];
		Rd=SUBS(Rd,Rm,bands);
		regs[b]=Rd;
		}
	}
	if( strcmp(instruction.mnemonic,"LSRS") == 0 ){  /* corrimiento hacia la derecha*/
	    move(4,0);
        printw("LSRS");
        refresh();
		a=instruction.op1_value; //--> Valor primer operando
		tipo1=instruction.op1_type;  //--> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		b=instruction.op2_value; //--> Valor primer operando
		tipo2=instruction.op2_type;
		c=instruction.op3_value;
		tipo3=instruction.op2_type;
		// ... Igual para los otros operandos
		Rd=regs[a];
		Rm=regs[b];
		Rd=LSRS(Rd,Rm,c,bands);
		regs[a]=Rd;
	}
	if( strcmp(instruction.mnemonic,"PUSH") == 0 ){  /* instruccion que copia datos en la memoria*/
        move(4,0);
        printw("PUSH");
        refresh();
        p=0;
        x=bitcount(instruction);
        address=regs[13]-(4*x);
        for(i=0;i<14;i++){
            if(instruction.registers_list[i]==1){
                aux[p]=regs[i];
                memA(ptr, mem, addr);
                address+=4;
                p++;
            }
        }
        regs[13]=regs[13]-(4*x);
	}
	if( strcmp(instruction.mnemonic,"POP") == 0 ){  /* instruccion que saca datos de la memoria*/
	    move(4,0);
        printw("POP ");
        refresh();
        x=bitcount(instruction);
        address=regs[13];
        p=0;
        for(i=0;i<14;i++){
            if(instruction.registers_list[i]==1){
                               regs[i]=aux[p];
                               address+=4;
                               p++;
                            }
                    }
        regs[13]=regs[13]+(4*x);
	}

	/*instrucciones  que sacan datos de la memoria por bytes*/
	if( strcmp(instruction.mnemonic,"LDR") == 0 )   
    {
       uint32_t imm, offset_addr;
       move(4,0);
       printw("LDR");
       refresh();
       if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&(instruction.op3_type=='#')){
            imm=(uint32_t)instruction.op3_value*4;
            offset_addr=regs[instruction.op2_value]+imm;
            if(offset_addr<0x20000000){
               for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr){
                    regs[instruction.op1_value]=flash_mem[i]||flash_mem[i+1]||flash_mem[i+2]||flash_mem[i+3];
                }
            }
            }
            if(offset_addr>=0x40000000){
               for(i=0;i<8;i++){
                if(addr_inout[i]==offset_addr){
                    regs[instruction.op1_value]=in_out[i]||in_out[i+1]||in_out[i+2]||in_out[i+3];
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    regs[instruction.op1_value]=mem[i]||mem[i+1]||mem[i+2]||mem[i+3];
                }
            }
       }
       }
       if((instruction.op1_type=='R')&&(instruction.op2_type=='SP')&&(instruction.op3_type=='#')){
            imm=(uint32_t)instruction.op3_value*4;
            offset_addr=regs[13]+imm;
            if(offset_addr<0x20000000){
               for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr){
                    regs[instruction.op1_value]=flash_mem[i]||flash_mem[i+1]||flash_mem[i+2]||flash_mem[i+3];
                }
            }
            }
            if(offset_addr>=0x40000000){
               for(i=0;i<8;i++){
                if(addr_inout[i]==offset_addr){
                    regs[instruction.op1_value]=in_out[i]||in_out[i+1]||in_out[i+2]||in_out[i+3];
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    regs[instruction.op1_value]=mem[i]||mem[i+1]||mem[i+2]||mem[i+3];
                }
            }
            }
       }
       if((instruction.op1_type=='R')&&(instruction.op2_type=='PC')&&(instruction.op3_type=='#')){
            imm=(uint32_t)instruction.op3_value*4;
            offset_addr=regs[15]+imm;
            if(offset_addr<0x20000000){
               for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr){
                    regs[instruction.op1_value]=flash_mem[i]||flash_mem[i+1]||flash_mem[i+2]||flash_mem[i+3];
                }
            }
            }
            if(offset_addr>=0x40000000){
               for(i=0;i<8;i++){
                if(addr_inout[i]==offset_addr){
                    regs[instruction.op1_value]=in_out[i]||in_out[i+1]||in_out[i+2]||in_out[i+3];
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    regs[instruction.op1_value]=mem[i]||mem[i+1]||mem[i+2]||mem[i+3];
                }
            }
            }
       }
       if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&(instruction.op3_type=='R')){
            offset_addr=regs[instruction.op2_value]+regs[instruction.op3_value];
            if(offset_addr<0x20000000){
               for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr){
                    regs[instruction.op1_value]=flash_mem[i]||flash_mem[i+1]||flash_mem[i+2]||flash_mem[i+3];
                }
            }
            }
            if(offset_addr>=0x40000000){
               for(i=0;i<8;i++){
                if(addr_inout[i]==offset_addr){
                    regs[instruction.op1_value]=in_out[i]||in_out[i+1]||in_out[i+2]||in_out[i+3];
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    regs[instruction.op1_value]=mem[i]||mem[i+1]||mem[i+2]||mem[i+3];
                }
            }
            }
       }
	}


	if( strcmp(instruction.mnemonic,"LDRB") == 0 )
    {
       uint32_t imm, offset_addr;
       move(4,0);
       printw("LDRB");
       refresh();
       if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&(instruction.op3_type=='#')){
           imm=(uint32_t)instruction.op3_value;
            offset_addr=regs[instruction.op2_value]+imm;
            if(offset_addr<0x20000000){
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr){
                    regs[instruction.op1_value]=(uint32_t)flash_mem[i];
                }
            }
            }
            if(offset_addr>=0x40000000){
                for(i=0;i<33;i++){
                if(addr_inout[i]==offset_addr){
                    regs[instruction.op1_value]=(uint32_t)in_out[i];
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    regs[instruction.op1_value]=(uint32_t)mem[i];
                }
            }
            }
       }
       if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&(instruction.op3_type=='R')){
            offset_addr=regs[instruction.op2_value]+regs[instruction.op3_value];
            if(offset_addr<0x20000000){
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr){
                    regs[instruction.op1_value]=(uint32_t)flash_mem[i];
                }
            }
            }
            if(offset_addr>=0x40000000){
                for(i=0;i<33;i++){
                if(addr_inout[i]==offset_addr){
                    regs[instruction.op1_value]=(uint32_t)in_out[i];
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    regs[instruction.op1_value]=(uint32_t)mem[i];
                }
            }
            }
       }
    }


    if( strcmp(instruction.mnemonic,"LDRH") == 0 )
    {
       uint32_t imm, offset_addr;
       move(4,0);
       printw("LDRH");
       refresh();
       if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&(instruction.op3_type=='#')){
           imm=(uint32_t)instruction.op3_value*2;
            offset_addr=regs[instruction.op2_value]+imm;
            if(offset_addr<0x20000000)
            {
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr){
                    regs[instruction.op1_value]=(uint32_t)flash_mem[i]||flash_mem[i+1];
                }
            }
            }
            if(offset_addr>=0x40000000)
            {
                for(i=0;i<8;i++){
                if(addr_flash[i]==offset_addr){
                    regs[instruction.op1_value]=(uint32_t)in_out[i]||in_out[i+1];
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    regs[instruction.op1_value]=(uint32_t)mem[i]||mem[i+1];
                }
            }
            }
       }
       if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&(instruction.op3_type=='R')){
            offset_addr=regs[instruction.op2_value]+regs[instruction.op3_value];
            if(offset_addr<0x20000000)
            {
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr){
                    regs[instruction.op1_value]=(uint32_t)flash_mem[i]||flash_mem[i+1];
                }
            }
            }
            if(offset_addr>=0x40000000)
            {
                for(i=0;i<8;i++){
                if(addr_flash[i]==offset_addr){
                    regs[instruction.op1_value]=(uint32_t)in_out[i]||in_out[i+1];
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    regs[instruction.op1_value]=(uint32_t)mem[i]||mem[i+1];
                }
            }
            }
       }
    }


    if( strcmp(instruction.mnemonic,"LDRSB") == 0 )
    {
       uint32_t imm, offset_addr;
       move(4,0);
       printw("LDRSB");
       refresh();
       if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&(instruction.op3_type=='R')){
            offset_addr=regs[instruction.op2_value]+regs[instruction.op3_value];
            if(offset_addr<0x20000000){
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr){
                    regs[instruction.op1_value]=(int32_t)flash_mem[i];
                }
            }
            }
            if(offset_addr>=0x40000000){
                for(i=0;i<33;i++){
                if(addr_inout[i]==offset_addr){
                    regs[instruction.op1_value]=(int32_t)in_out[i];
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    regs[instruction.op1_value]=(int32_t)mem[i];
                }
            }
            }
       }
    }


    if( strcmp(instruction.mnemonic,"LDRSH") == 0 )
    {
       uint32_t imm, offset_addr;
       move(4,0);
       printw("LDRSH");
       refresh();
       if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&(instruction.op3_type=='R')){
            offset_addr=regs[instruction.op2_value]+regs[instruction.op3_value];
            if(offset_addr>=0x40000000){
                for(i=0;i<8;i++){
                if(addr_inout[i]==offset_addr){
                    regs[instruction.op1_value]=(int32_t)in_out[i]||in_out[i+1];
                }
            }
            }
            if(offset_addr<0x20000000){
                for(i=0;i<8;i++){
                if(addr_flash[i]==offset_addr){
                    regs[instruction.op1_value]=(int32_t)flash_mem[i]||flash_mem[i+1];
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    regs[instruction.op1_value]=(int32_t)mem[i]||mem[i+1];
                }
            }
            }
       }
    }

		/*instrucciones que guardan datos en la memoria*/
    if( strcmp(instruction.mnemonic,"STR") == 0 )
    {
       uint32_t imm, offset_addr;
       move(4,0);
       printw("STR");
       refresh();
       if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&(instruction.op3_type=='#')){
            imm=(uint32_t)instruction.op3_value*4;
            offset_addr=regs[instruction.op2_value]+imm;
            if(offset_addr<0x20000000){
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr)
                {
                    flash_mem[i]=*(xp+(instruction.op1_value*4));
                    flash_mem[i+1]=*(xp+(instruction.op1_value*4)+1);
                    flash_mem[i+2]=*(xp+(instruction.op1_value*4)+2);
                    flash_mem[i+3]=*(xp+(instruction.op1_value*4)+3);
                }
            }
            }
            if(offset_addr>=0x40000000){
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr)
                {
                    in_out[i]=*(xp+(instruction.op1_value*4));
                    in_out[i+1]=*(xp+(instruction.op1_value*4)+1);
                    in_out[i+2]=*(xp+(instruction.op1_value*4)+2);
                    in_out[i+3]=*(xp+(instruction.op1_value*4)+3);
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr)
                {
                    mem[i]=*(xp+(instruction.op1_value*4));
                    mem[i+1]=*(xp+(instruction.op1_value*4)+1);
                    mem[i+2]=*(xp+(instruction.op1_value*4)+2);
                    mem[i+3]=*(xp+(instruction.op1_value*4)+3);
                }
            }
            }
       }
       if((instruction.op1_type=='R')&&(instruction.op2_type=='SP')&&(instruction.op3_type=='#')){
            imm=(uint32_t)instruction.op3_value*4;
            offset_addr=regs[13]+imm;
            if(offset_addr<0x20000000){
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr)
                {
                    flash_mem[i]=*(xp+(instruction.op1_value*4));
                    flash_mem[i+1]=*(xp+(instruction.op1_value*4)+1);
                    flash_mem[i+2]=*(xp+(instruction.op1_value*4)+2);
                    flash_mem[i+3]=*(xp+(instruction.op1_value*4)+3);
                }
            }
            }
            if(offset_addr>=0x40000000){
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr)
                {
                    in_out[i]=*(xp+(instruction.op1_value*4));
                    in_out[i+1]=*(xp+(instruction.op1_value*4)+1);
                    in_out[i+2]=*(xp+(instruction.op1_value*4)+2);
                    in_out[i+3]=*(xp+(instruction.op1_value*4)+3);
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    mem[i]=*(xp+(instruction.op1_value*4));
                    mem[i+1]=*(xp+(instruction.op1_value*4)+1);
                    mem[i+2]=*(xp+(instruction.op1_value*4)+2);
                    mem[i+3]=*(xp+(instruction.op1_value*4)+3);
                }
            }
            }
       }
       if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&(instruction.op3_type=='R')){
            offset_addr=regs[instruction.op2_value]+regs[instruction.op3_value];
            if(offset_addr<0x20000000){
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr)
                {
                    flash_mem[i]=*(xp+(instruction.op1_value*4));
                    flash_mem[i+1]=*(xp+(instruction.op1_value*4)+1);
                    flash_mem[i+2]=*(xp+(instruction.op1_value*4)+2);
                    flash_mem[i+3]=*(xp+(instruction.op1_value*4)+3);
                }
            }
            }
            if(offset_addr>=0x40000000){
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr)
                {
                    in_out[i]=*(xp+(instruction.op1_value*4));
                    in_out[i+1]=*(xp+(instruction.op1_value*4)+1);
                    in_out[i+2]=*(xp+(instruction.op1_value*4)+2);
                    in_out[i+3]=*(xp+(instruction.op1_value*4)+3);
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    mem[i]=*(xp+(instruction.op1_value*4));
                    mem[i+1]=*(xp+(instruction.op1_value*4)+1);
                    mem[i+2]=*(xp+(instruction.op1_value*4)+2);
                    mem[i+3]=*(xp+(instruction.op1_value*4)+3);
                }
            }
            }
       }
    }


    if( strcmp(instruction.mnemonic,"STRB") == 0 )
    {
       uint32_t imm, offset_addr;
       move(4,0);
       printw("STRB");
       refresh();
       if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&(instruction.op3_type=='#')){
           imm=(uint32_t)instruction.op3_value;
            offset_addr=regs[instruction.op2_value]+imm;
            if(offset_addr<0x20000000){
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr){
                    flash_mem[i]=*(xp+(instruction.op1_value*4));
                }
            }
            }
            if(offset_addr>=0x40000000){
                for(i=0;i<33;i++){
                if(addr_inout[i]==offset_addr){
                    in_out[i]=*(xp+(instruction.op1_value*4));
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    mem[i]=*(xp+(instruction.op1_value*4));
                }
            }
            }
       }
       if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&(instruction.op3_type=='R')){
            offset_addr=regs[instruction.op2_value]+regs[instruction.op3_value];
            if(offset_addr<0x20000000){
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr){
                    flash_mem[i]=*(xp+(instruction.op1_value*4));
                }
            }
            }
            if(offset_addr>=0x40000000){
                for(i=0;i<33;i++){
                if(addr_inout[i]==offset_addr){
                    in_out[i]=*(xp+(instruction.op1_value*4));
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    mem[i]=*(xp+(instruction.op1_value*4));
                }
            }
            }
       }
    }


    if( strcmp(instruction.mnemonic,"STRH") == 0 )
    {
       uint32_t imm, offset_addr;
       move(4,0);
       printw("STRH");
       refresh();
       if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&(instruction.op3_type=='#')){
           imm=(uint32_t)instruction.op3_value;
            offset_addr=regs[instruction.op2_value]+imm;
            if(offset_addr<0x20000000){
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr){
                    flash_mem[i]=*(xp+(instruction.op1_value*4));
                    flash_mem[i+1]=*(xp+(instruction.op1_value*4)+1);
                }
            }
            }
            if(offset_addr>=0x40000000){
                for(i=0;i<8;i++){
                if(addr_inout[i]==offset_addr){
                    in_out[i]=*(xp+(instruction.op1_value*4));
                    in_out[i+1]=*(xp+(instruction.op1_value*4)+1);
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    mem[i]=*(xp+(instruction.op1_value*4));
                    mem[i+1]=*(xp+(instruction.op1_value*4)+1);
                }
            }
            }
       }
       if((instruction.op1_type=='R')&&(instruction.op2_type=='R')&&(instruction.op3_type=='R')){
            offset_addr=regs[instruction.op2_value]+regs[instruction.op3_value];
            if(offset_addr<0x20000000){
                for(i=0;i<33;i++){
                if(addr_flash[i]==offset_addr){
                    flash_mem[i]=*(xp+(instruction.op1_value*4));
                    flash_mem[i+1]=*(xp+(instruction.op1_value*4)+1);
                }
            }
            }
            if(offset_addr>=0x40000000){
                for(i=0;i<8;i++){
                if(addr_inout[i]==offset_addr){
                    in_out[i]=*(xp+(instruction.op1_value*4));
                    in_out[i+1]=*(xp+(instruction.op1_value*4)+1);
                }
            }
            }
            else{
            for(i=0;i<128;i++){
                if(addr[i]==offset_addr){
                    mem[i]=*(xp+(instruction.op1_value*4));
                    mem[i+1]=*(xp+(instruction.op1_value*4)+1);
                }
            }
            }
       }
    }
}


instruction_t getInstruction(char* instStr)  /*funcion que lee del archivo de texto las instrucciones*/
{
	instruction_t instruction=
	{
		.registers_list = {0},
		.op3_type  = 'N',
		.op3_value = 0
	};
	char* split = (char*)malloc(strlen(instStr)+1);
	int num=0;

	strcpy(split, instStr);
	/* Obtiene el mnemonico de la instrucción */
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);

	/* Separa los operandos */
	while (split != NULL)
	{
		switch(num){
			case 1:
				if(split[0] == '{'){
					instruction.op1_type  = split[0];
					split++;
					do{
						if(split[0]=='L')
							instruction.registers_list[14] = 1;
						else if(split[0]=='P')
							instruction.registers_list[15] = 1;
						else
							instruction.registers_list[(uint8_t)strtoll(split+1, NULL, 0)] = 1;

						split = strtok(NULL, ",");
					}while(split != NULL);
				}else{
					instruction.op1_type  = split[0];
					instruction.op1_value = (uint32_t)strtoll(split+1, NULL, 0);
				}
				break;

			case 2:
				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;
		}
		if(split != NULL){
			split = strtok(NULL, " ,.");
			num++;
		}
	}

	if(instruction.op1_type == 'L'){
		instruction.op1_value = 14;
		instruction.op1_type = 'R';
	}

	if(instruction.op1_type == '{'){
		instruction.op1_type = 'P';
	}

	free(split);

	return instruction;
}

int readFile(char* filename, ins_t* instructions)  /* funcion que lee el archivo de texto*/
{
	FILE* fp;	/* Puntero a un archivo  */
	int lines;	/* Cantidad de líneas del archivo */
	int line=0;	/* Línea leida */
	char buffer[50]; /* Almacena la cadena leida */

	fp = fopen(filename, "r");	/* Abrir el archivo como solo lectura */
	if( fp==NULL )
		return -1;	/* Error al abrir el archivo */

	lines = countLines(fp);	/* Cantidad de líneas*/

	/* Asignación dinámica de memoria para cada instrucción */
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}

	fclose(fp);	/* Cierra el archivo */

	return lines;
}


int countLines(FILE* fp)  /*funcion que cuenta el numero de lineas que tiene el archivo de texto*/
{
	int lines=0;
	char buffer[50];

	while( fgets(buffer, 50, fp) != NULL )
		lines++;

	rewind(fp);

	return lines;
}
int bitcount(instruction_t instruction){  /*funcion que indica los operandos activos para las funciones de push y pop*/
    int cont=0;
    for(i=0;i<16;i++){
        if(instruction.registers_list[i]==1){
            cont++;
        }
    }
    return cont;
}

void memA(char* ptr, uint32_t* mem, uint32_t* addr){   /* funcion que asigna valores en la memoria para las funciones push y pop*/
    int k;
    for(k=0;k<20;k++){
        mem[k]=*(ptr+k);
    }
}







