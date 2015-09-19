#include "decoder.h"
#include "banderas.h"
#include "instrucciones.h"
#include "libreria.h"

char tipo1, tipo2, tipo3;
uint32_t Rd, Rm,a, b, c;

void decodeInstruction(instruction_t instruction, uint32_t* regs, uint32_t* bands, int* pc)
{
    /*int lr;
    if( (strcmp(instruction.mnemonic,"BL") == 0)){
            printf("aaaaaaaaaaaaa");
            tipo1=instruction.op1_type;
            a=instruction.op1_value;
            lr=pc+1;
            pc=pc+a;
    }

    if( (strcmp(instruction.mnemonic,"B") == 0)){
            tipo1=instruction.op1_type;
            a=instruction.op1_value;
            pc=a;
    }

    if( (strcmp(instruction.mnemonic,"BCC") == 0) && (bands[2]==0)){
            tipo1=instruction.op1_type;
            a=instruction.op1_value;
            pc=pc+a;
    }

    if( (strcmp(instruction.mnemonic,"BNE") == 0) && (bands[1]==0)){
            tipo1=instruction.op1_type;
            a=instruction.op1_value;
            pc=pc+a;
    }
    if( (strcmp(instruction.mnemonic,"BX") == 0) && (bands[1]==0)){
            pc=lr;
    }*/


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
		Rd=MOVS(Rd,b,bands);
		regs[a]=Rd;
		}
		if(tipo2=='R'){
		Rd=MOVS(Rd,Rm,bands);
		regs[a]=Rd;
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
		Rd=ADCS(Rd,Rm,1,bands);
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
