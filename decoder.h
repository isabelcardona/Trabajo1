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
	uint32_t op1_value;
	uint32_t op2_value;
	uint32_t op3_value;
	uint32_t  registers_list[16];
}instruction_t;




/** \fn void decodeInstruction(instruction_t instruction)
    \brief Decodifica la instrucción y la ejecuta.
    \param instruction instrucción a decodificar y ejecutar.
*/

void decodeInstruction(instruction_t instruction, uint32_t* regs, uint32_t* bands, uint32_t* mem, uint32_t* address, uint32_t* addr, uint32_t* flash_mem, uint32_t* addr_flash, uint32_t* in_out, uint32_t* addr_inout);
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
	\return estructura tipo instruction_t.
*/
int readFile(char* filename, ins_t* instructions);

/** \fn int countLines(FILE fp)
    \brief lee el archivo completo.
    \param filename  cadena que contiene nombre del archivo.
	\return Entero con la cantidad de líneas del archivo.
*/
int countLines(FILE* fp);
/** 
    \brief Cuenta la cantidad de líneas de un archivo.
    \param fp Puntero al archivo.
	\return Entero con la cantidad de líneas del archivo.
*/

int bitcount(instruction_t instruction);
/** 
    \brief indica los registros activos para las funciones de push y pop.
    \param instruction_t estructura con la instruccion.
	\return Entero con la cantidad de registros activos.
*/

void memA(char* p, uint32_t* mem, uint32_t* addr);
/** 
    \brief asigna valores en la memoria para las funciones de push y pop.
    \param1 p puntuero que permite guardar byte por byte.
	\param2 mem arreglo para la Sram.
	\param3 addr arreglo con las direcciones corespondientes a la memoria.
*/

#endif /*_DECODER_H_*/
