#include "decoder.h"
#include "banderas.h"
#include "instrucciones.h"
#include "libreria.h"

char tipo1, tipo2, tipo3;
uint32_t Rd, Rm,a, b, c, temp, R[8];
int aux[8]={0};

void decodeInstruction(instruction_t instruction, uint32_t* regs, uint32_t* bands)
{


    if( (strcmp(instruction.mnemonic,"B") == 0)){
            regs[13]=instruction.op1_value-1;
    }
    if( (strcmp(instruction.mnemonic,"BX") == 0)){
            regs[13]=instruction.op1_value-1;
    }

    if( (strcmp(instruction.mnemonic,"BL") == 0)){
            regs[14]=regs[13]+1;
            if(instruction.op1_type=='#'){
                regs[13]=instruction.op1_value;
            }
            if(instruction.op1_type=='R'){
                regs[13]=regs[instruction.op1_value];
            }
    }
    if( (strcmp(instruction.mnemonic,"BLX") == 0)){
            uint32_t temp;
            temp=regs[14];
            regs[14]=regs[13]+1;
            if(instruction.op1_type=='#'){
                regs[13]=instruction.op1_value;
            }
            if(instruction.op1_type=='R'){
                regs[13]=regs[instruction.op1_value];
            }
            if(instruction.op1_type=='L'){
                regs[13]=temp;
            }
    }

    if( (strcmp(instruction.mnemonic,"BEQ") == 0) && (bands[1]==1)){
            regs[13]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BNE") == 0) && (bands[1]==0)){
            regs[13]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BCS") == 0) && (bands[2]==1)){
            regs[13]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BCC") == 0) && (bands[2]==0)){
            regs[13]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BMI") == 0) && (bands[0]==1)){
            regs[13]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BPL") == 0) && (bands[0]==0)){
            regs[13]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BVS") == 0) && (bands[3]==1)){
            regs[13]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BVC") == 0) && (bands[3]==0)){
            regs[13]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BHI") == 0) && (bands[2]==1) && (bands[1]==0)){
            regs[13]+=instruction.op1_value;
    }

    if( (strcmp(instruction.mnemonic,"BLS") == 0) && (bands[2]==0) && (bands[1]==1)){
            regs[13]+=instruction.op1_value;
    }
    if( (strcmp(instruction.mnemonic,"BGE") == 0) && (bands[0]==bands[3])){
            regs[13]+=instruction.op1_value;
    }
    if( (strcmp(instruction.mnemonic,"BLT") == 0) && (bands[0]!=bands[3])){
            regs[13]+=instruction.op1_value;
    }
    if( (strcmp(instruction.mnemonic,"BGT") == 0) && (bands[1]==0) && (bands[0]==bands[3])){
            regs[13]+=instruction.op1_value;
    }
    if( (strcmp(instruction.mnemonic,"BLE") == 0) && (bands[1]==0) && (bands[0]!=bands[3])){
            regs[13]+=instruction.op1_value;
    }
    if( (strcmp(instruction.mnemonic,"BAL") == 0) ){
            regs[13]+=instruction.op1_value;
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
	if( strcmp(instruction.mnemonic,"PUSH") == 0 ){


}


instruction_t getInstruction(char* instStr)
{
	instruction_t instruction;
	char* split = (char*)malloc(strlen(instStr));
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
				instruction.op1_type  = split[0];
				instruction.op1_value = (uint32_t)strtol(split+1, NULL, 0);
				break;

			case 2:
				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtol(split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtol(split+1, NULL, 0);
				break;
		}

		split = strtok(NULL, " ,.");
		num++;
	}

	if(num==3){
		instruction.op3_type  = 'N';
		instruction.op3_value = 0;
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

	lines = countLines(fp)-1;	/* Cantidad de líneas*/

	/* Asignación dinámica de memoria para cada instrucción */
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc(strlen(buffer)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}

	fclose(fp);	/* Cierra el archivo */

	return lines;
}


int countLines(FILE* fp)
{
	int lines=0;
	int ch;

	while(!feof(fp))
	{
	  ch = fgetc(fp);
	  if(ch == '\n')
		lines++;
	}
	rewind(fp);

	return lines;
}

int bitcount(instruction_t instruction, uint32_t R, int* aux){
    int cont=0;
    if((instruction.op1_type=='R')||(instruction.op1_type=='L')){
        cont++;
        aux[0]=instruction.op1_value;
    }
    if((instruction.op2_type=='R')||(instruction.op2_type=='L')){
        cont++;
        aux[1]=instruction.op2_value;
    }
    if((instruction.op3_type=='R')||(instruction.op3_type=='L')){
        cont++;
        aux[2]=instruction.op3_value;
    }
    if((instruction.op4_type=='R')||(instruction.op4_type=='L')){
        cont++;
        aux[3]=instruction.op4_value;
    }
    if((instruction.op5_type=='R')||(instruction.op5_type=='L')){
        cont++;
        aux[4]=instruction.op5_value;
    }
    if((instruction.op6_type=='R')||(instruction.op6_type=='L')){
        cont++;
        aux[5]=instruction.op6_value;
    }
    if((instruction.op7_type=='R')||(instruction.op7_type=='L')){
        cont++;
        aux[6]=instruction.op7_value;
    }
    if((instruction.op8_type=='R')||(instruction.op8_type=='L')){
        cont++;
        aux[7]=instruction.op8_value;
    }
    return cont;
}
}





