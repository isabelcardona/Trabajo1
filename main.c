#include <stdio.h>
#include <stdlib.h>
#include "instrucciones.h"
#include "libreria.h"
#include "decoder.h"
#include <math.h>
#include <stdint.h>
#include <curses.h>

int main()
{
<<<<<<< HEAD
    uint32_t regs[13]={0},rd,rm,imm,r; /** definicion de las variables regs y bands  como arreglos de los registros*/
    int i,j,k,num_instructions,bands[4]={0},pc=0; /**  y las banderas, operandos de las instrucciones.*/
=======
    uint32_t regs[13]={0},rd,rm,imm,r;
    int i,j,k,num_instructions,bands[4]={0},pc=0;
>>>>>>> 8cb513235e6436d6163cdc9eeb515e60dbeef585
		ins_t read;
		char** instructions;
		instruction_t instruction;

		num_instructions = readFile("code.txt", &read); /** funcion que lee las instrucciones desde un archivo .txt y las implementa en el proceso.*/
		if(num_instructions==-1)                        /** funcion que cierra el programa cuando encuentra un error al subir el archivo de texto */
			return 0;

		if(read.array==NULL)                             /** condicion de retorno cuando llegue al final del archivo de las instrucciones */
			return 0;

		instructions = read.array; /** Arreglo con las instrucciones */
	//---------------------------//



	/* Ejemplo de uso
		Llama la función que separa el mnemonico y los operandos
		Llama la instrucción que decodifica y ejecuta la instrucción
	*/
<<<<<<< HEAD
	for(pc=0; pc<num_instructions; pc++)     //proseso para que el programa contador (pc)
                                             //realize instrucciones ejecute funciones con
    {                                        //instrucciones de posiciones positivas

    if(pc==-2)     /**condicion para que el pc que va de dos en dos inicie en cero*/
	{
=======
	for(pc=0; pc<num_instructions; pc++){
            //pc=pc-2;
    if(pc==-2){
>>>>>>> 8cb513235e6436d6163cdc9eeb515e60dbeef585
        pc=pc+2;
    }
	// Esto debe ser ciclico para la lectura de todas las instrucciones, de acuerdo
	// al valor del PC (Program Counter)
	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */

	start_color();	/* Permite manejar colores */

	init_pair(1, COLOR_GREEN, COLOR_BLACK);	/* Pair 1 -> Texto verde
											   fondo Negro */


	/*border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);*/

	attron(COLOR_PAIR(1));	/* Activa el color verde para el
							   texto y negro para el fondo Pair 1*/
<<<<<<< HEAD
    move(0, 20);  /**posicion del cursor en filas y columnas*/
=======
    move(0, 20);
>>>>>>> 8cb513235e6436d6163cdc9eeb515e60dbeef585
    printw("EMULADOR DE PROCESADOR ARM Cortex-M0_V6");
	refresh();	/* Imprime en la pantalla
					Sin esto el printw no es mostrado */
					//getch();
    instruction = getInstruction(instructions[pc]); // Instrucción en la posición 0
	decodeInstruction(instruction, regs, bands, pc); // Debe ser modificada de acuerdo a cada código
    //registros[instruction.op1_value] = instruction.op2_value;
	//------- No modificar ------//

    j=0;
    k=0;
<<<<<<< HEAD
    if(pc==0)
	{
    for(i=6;i<17;i=i+2) /** proceso que recorre las filas y columnas */
	{
    if((j==5)||(j==9)){  /** proceso que recorre cada registro*/
=======
    if(pc==0){
    for(i=6;i<17;i=i+2){
    if((j==5)||(j==9)){
>>>>>>> 8cb513235e6436d6163cdc9eeb515e60dbeef585
        k=k+22;
        i=6;
    }
	move(i, k);	/* Mueve el cursor a la posición i,k*/
	printw("R%d=",j);
	refresh();	/* Imprime en la pantalla
					Sin esto el printw no es mostrado */
    if(j==12){
        i=100;
    }

	j++;
    }
    }

    	attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */

    j=0;
    k=0;
    for(i=6;i<17;i=i+2){
    if((j==5)||(j==9)){
        k=k+22;
        i=6;
    }
    move(i, k+3);	/* Mueve el cursor a la posición i,k*/
    if(j>9){
       move(i, k+4);	/* Mueve el cursor a la posición i,k*/
    }

	printw("%d  ",regs[j]);
	refresh();	/* Imprime en la pantalla Sin esto el printw no es mostrado */
    if(j==12){
        i=100;
    }
	j++;
    }

<<<<<<< HEAD
    move(18, 0); /**posicion de inicio fila columna donde se muestran las banderas*/

    printw("N=%x",bands[0]);   /**imprime la bandera de negativo*/
    refresh();
    move(19, 0);
    printw("Z=%x",bands[1]);   /**imprime la bandera de cero*/
    refresh();
    move(20, 0);
    printw("C=%x",bands[2]);  /**imprime la bandera de acarreo*/
    refresh();
    move(21, 0);
    printw("V=%x",bands[3]);  /**imprime la bandera de sobreflujo*/
=======
    move(18, 0);

    printw("N=%x",bands[0]);
    refresh();
    move(19, 0);
    printw("Z=%x",bands[1]);
    refresh();
    move(20, 0);
    printw("C=%x",bands[2]);
    refresh();
    move(21, 0);
    printw("V=%x",bands[3]);
>>>>>>> 8cb513235e6436d6163cdc9eeb515e60dbeef585
    refresh();
	/* Libera la memoria reservada para las instrucciones */
    getch();
	}

	for(i=0; i<num_instructions; i++){
		free(read.array[i]);
	}
	free(read.array);
	//---------------------------//

	endwin();	/* Finaliza el modo curses */
<<<<<<< HEAD

	return 0;
}
=======

	return 0;
}



>>>>>>> 8cb513235e6436d6163cdc9eeb515e60dbeef585
