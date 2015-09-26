#ifndef _DECODER_H_
#define	_DECODER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>


typedef struct
{
	char** array;
}ins_t;


typedef struct
{
	char mnemonic[10];
	char op1_type;
	char op2_type;
	char op3_type;
	char op4_type;
	char op5_type;
	char op6_type;
	char op7_type;
	char op8_type;
	uint32_t op1_value;
	uint32_t op2_value;
	uint32_t op3_value;
	uint32_t op4_value;
	uint32_t op5_value;
	uint32_t op6_value;
	uint32_t op7_value;
	uint32_t op8_value;
}instruction_t;


/** \fn void decodeInstruction(instruction_t instruction)
    \brief Decodifica la instrucción y la ejecuta.
    \param instruction instrucción a decodificar y ejecutar.
*/

void decodeInstruction(instruction_t instruction, uint32_t* regs, uint32_t* bands);

/** \fn instruction_t getInstruction(char* instStr)
    \brief Obtiene la instrucción separada por partes.
    \param instrStr cadena que contiene la instrucción.
	\return instruction_t la instrucción separada por partes.
*/
instruction_t getInstruction(char* instStr);

/** \fn int readFile(char** instructions)
    \brief Lee instrucciones de un archivo.
    \param filename Nombre del archivo.
    \param instructions estructura con arreglo con las instrucciones leidas.
	\return Entero indicando la cantidad de líneas.
*/
int readFile(char* filename, ins_t* instructions);

/** \fn int countLines(FILE fp)
    \brief Cuenta la cantidad de líneas de un archivo.
    \param fp Puntero al archivo.
	\return Entero con la cantidad de líneas del archivo.
*/
int countLines(FILE* fp);

int bitcount(instruction_t instruction, uint32_t R, int* aux);

#endif /*_DECODER_H_*/
