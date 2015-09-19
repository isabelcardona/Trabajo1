#include <stdio.h>
#include <stdlib.h>
#include "instrucciones.h"
#include "libreria.h"
#include <math.h>
#include <stdint.h>
int main()
{
uint32_t regs[12]; //funcion de los registros
uint32_t rd,rm,imm,r;
mostrar_registros(regs);
rd=10;
rm=6;
CMP(&rd,&rm);
printf("%d",rd);
int i, num_instructions;
		ins_t read;
		char** instructions;
		instruction_t instruction;

		num_instructions = readFile("code.txt", &read);
		if(num_instructions==-1)
			return 0;

		if(read.array==NULL)
			return 0;

		instructions = read.array; /* Arreglo con las instrucciones */
	//---------------------------//



	/* Ejemplo de uso
		Llama la funci�n que separa el mnemonico y los operandos
		Llama la instrucci�n que decodifica y ejecuta la instrucci�n
	*/
	for(pc=0; pc<num_instructions; pc=pc+2;){
            pc=pc-2;
    if(pc==-2){
        pc=pc+2;
    }
	// Esto debe ser ciclico para la lectura de todas las instrucciones, de acuerdo
	// al valor del PC (Program Counter)
	instruction = getInstruction(instructions[pc]); // Instrucci�n en la posici�n 0
	pc=decodeInstruction(instruction); // Debe ser modificada de acuerdo a cada c�digo
    printf("%d\n",instruction.op1_value);
    //registros[instruction.op1_value] = instruction.op2_value;
	//------- No modificar ------//
	/* Libera la memoria reservada para las instrucciones */
	}
	for(i=0; i<num_instructions; i++){
		free(read.array[i]);
	}
	free(read.array);
	//---------------------------//

}

