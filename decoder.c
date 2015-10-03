#include "decoder.h"
#include "banderas.h"
#include "instrucciones.h"
#include "libreria.h"

char tipo1, tipo2, tipo3, *ptr;
uint32_t Rd, Rm,a, b, c, temp, aux[16];
int x=0, i, j, p=0;



void decodeInstruction(instruction_t instruction, uint32_t* regs, uint32_t* bands, uint32_t* mem, uint32_t* address, uint32_t* addr)
{
    ptr=regs;

	/* condiciones de salto*/
    if( (strcmp(instruction.mnemonic,"B") == 0)){    /* salta a un valor inmediato  */ 
            regs[15]=instruction.op1_value;
    }                                              
    if( (strcmp(instruction.mnemonic,"BX") == 0)){   /* salta a un inmediato o a LR */
            regs[15]=instruction.op1_value-1;
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

	/* condiciones de las instrucciones que se muestran en la interfaz */
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
		Rd=regs[a];
		Rm=regs[b];
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
	if( strcmp(instruction.mnemonic,"ADCS") == 0 ){
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
	if( strcmp(instruction.mnemonic,"LSLS") == 0 ){
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
	if( strcmp(instruction.mnemonic,"ADDS") == 0 ){
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
	if( strcmp(instruction.mnemonic,"SUBS") == 0 ){
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
	if( strcmp(instruction.mnemonic,"LSRS") == 0 ){
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
	if( strcmp(instruction.mnemonic,"PUSH") == 0 ){       /* instruccion que guarda registros en la memoria  */ 
        move(4,0);
        printw("PUSH");
        refresh();
        x=bitcount(instruction);
        address=regs[13]-(4*x);    /* address es igual a la posicion en la que debe quedar el sp "regs[13]"   */    
        p=0;
        for(i=0;i<14;i++){
            if(instruction.registers_list[i]==1){               
                aux[p]=regs[i];
                memA(address, regs, i, ptr, mem, addr);
                address+=4;
                p++;
            }
        }
        regs[13]=regs[13]-(4*x);
	}
	if( strcmp(instruction.mnemonic,"POP") == 0 ){        /* instruccion que saca los registros de la memoria y los ubica en otros registros */
	    move(4,0);
        printw("POP ");
        refresh();
        x=bitcount(instruction);
        address=regs[13];
        p=0;
        for(i=0;i<14;i++){
            if(instruction.registers_list[i]==1){
                                printf("b");
                               regs[i]=aux[p];
                               address+=4;
                               p++;
                            }
                    }
        regs[13]=regs[13]+(4*x);
        for(i=0;i<50;i++){
            printf("\n%x",mem[i]);
        }
	}
	
}


instruction_t getInstruction(char* instStr)
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

int readFile(char* filename, ins_t* instructions)
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


int countLines(FILE* fp)
{
	int lines=0;
	char buffer[50];

	while( fgets(buffer, 50, fp) != NULL )
		lines++;

	rewind(fp);

	return lines;
}
int bitcount(instruction_t instruction){
    int cont=0;
    for(i=0;i<16;i++){
        if(instruction.registers_list[i]==1){
            cont++;
        }
    }
    return cont;
}

void memA(uint32_t* address, uint32_t* regs, int h, char* p, uint32_t* mem, uint32_t* addr){  /* memoria en la que quedan guardados los registros */
    int k=0;
    for(j=0;j<128;j++){                   /* recorre el tamaño de la memoria, en este caso de 128 bytes */
        if(addr[j]==address){             /* addr es el arreglo con las direcciones que se le asigna a la memoria */
            for(k=0;k<4;k++){
                mem[k]=*(p+h+k);
            }
        }
    }
}



