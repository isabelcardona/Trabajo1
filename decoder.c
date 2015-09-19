#include "decoder.h"
#include "banderas.h"
#include "instrucciones.h"
#include "libreria.h"
int a, b, pc=0;
float c;
char tipo1, tipo2;
uint32_t Rd, Rm;

int decodeInstruction(instruction_t instruction)
{
    if( (strcmp(instruction.mnemonic,"BL"))&&(bands[0]==1) ){
            pc=2;
    }
    if( strcmp(instruction.mnemonic,"B") == 0 ){
            pc=0;
    }
    if( (strcmp(instruction.mnemonic,"BCC"))&&(bands[1]==0) ){
            pc=2;
    }
    if( strcmp(instruction.mnemonic,"BX") == 0 ){
            pc=pc+2;
    }
    if( strcmp(instruction.mnemonic,"CMP") == 0 ){
		a=instruction.op1_value; //--> Valor primer operando
		tipo1=instruction.op1_type  //--> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		b=instruction.op2_value; //--> Valor primer operando
		tipo2=instruction.op2_type
		// ... Igual para los otros operandos
		Rd=regs[a];
		Rm=regs[b];
		CMP(Rd,Rm)
	}
    if( strcmp(instruction.mnemonic,"MOVS") == 0 ){
		a=instruction.op1_value; //--> Valor primer operando
		tipo1=instruction.op1_type  //--> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		c=instruction.op2_value; //--> Valor primer operando
		tipo2=instruction.op2_type
		// ... Igual para los otros operandos
		Rd=regs[a];
		Rd=ADC(Rd,c)
	}
	if( strcmp(instruction.mnemonic,"ADCS") == 0 ){
		a=instruction.op1_value; //--> Valor primer operando
		tipo1=instruction.op1_type  //--> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		b=instruction.op2_value; //--> Valor primer operando
		tipo2=instruction.op2_type
		// ... Igual para los otros operandos
		Rd=regs[a];
		Rm=regs[b];
		Rd=ADC(Rd,Rm,1)
	}
	if( strcmp(instruction.mnemonic,"LSLS") == 0 ){
		a=instruction.op1_value; //--> Valor primer operando
		tipo1=instruction.op1_type  //--> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		b=instruction.op2_value; //--> Valor primer operando
		tipo2=instruction.op2_type
		// ... Igual para los otros operandos
		Rd=regs[a];
		Rm=regs[b];
		Rd=LSLS(Rd,Rm)
	}
	if( strcmp(instruction.mnemonic,"ADDS") == 0 ){
		a=instruction.op1_value; //--> Valor primer operando
		tipo1=instruction.op1_type  //--> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		b=instruction.op2_value; //--> Valor primer operando
		tipo2=instruction.op2_type
		// ... Igual para los otros operandos
		Rd=regs[a];
		Rm=regs[b];
		Rd=ADDS(Rd,Rm)
	}
	if( strcmp(instruction.mnemonic,"SUBS") == 0 ){
		a=instruction.op1_value; //--> Valor primer operando
		tipo1=instruction.op1_type  //--> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		b=instruction.op2_value; //--> Valor primer operando
		tipo2=instruction.op2_type
		// ... Igual para los otros operandos
		Rd=regs[a];
		Rm=regs[b];
		Rd=SUBS(Rd,Rm)
	}
	if( strcmp(instruction.mnemonic,"LSRS") == 0 ){
		a=instruction.op1_value; //--> Valor primer operando
		tipo1=instruction.op1_type  //--> Tipo primer operando (R->Registro #->Numero N->Ninguno)
		b=instruction.op2_value; //--> Valor primer operando
		tipo2=instruction.op2_type
		// ... Igual para los otros operandos
		Rd=regs[a];
		Rm=regs[b];
		Rd=LSRS(Rd,Rm)
	}
	return pc;
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
