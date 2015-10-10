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

    uint32_t regs[16]={0},rd,rm,imm,r, mem[128]={0}, address=0, addr[128]={0}, interrup_regs[33], flash_mem[33], addr_flash[33], in_out[8], addr_inout[8];
    regs[13]=0x2000007f; // posicion de sp para una memoria de 128 bytes;
    int i,j,k,num_instructions,bands[4]={0},pc=0;
		ins_t read;
		char** instructions;
		instruction_t instruction;

		 /* Arreglo con las instrucciones */
	//---------------------------//



	/* Ejemplo de uso
		Llama la función que separa el mnemonico y los operandos
		Llama la instrucción que decodifica y ejecuta la instrucción
	*/

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
    move(0, 20);
    printw("EMULADOR DE PROCESADOR ARM Cortex-M0_V6");
	refresh();
		/* Imprime en la pantalla
					Sin esto el printw no es mostrado */
    //move(4,9);//getch();



            num_instructions = readFile("code.txt", &read);
		if(num_instructions==-1)
			return 0;

		if(read.array==NULL)
			return 0;

		instructions = read.array;
    for(i=0;i<128;i++){
        addr[i]=0x20000000+i;
    }
    for(i=0;i<33;i++){
        addr_flash[i]=0x00000000+i;
    }
    for(i=0;i<8;i++){
        addr_inout[i]=0x40000000+i;
    }

while(1){
    NVIC(interrup_regs, flash_mem, regs, bands, mem);
for(regs[15]=0; regs[15]<num_instructions; regs[15]++){
    instruction = getInstruction(instructions[regs[15]]); // Instrucción en la posición 0
	decodeInstruction(instruction, regs, bands, mem, address, addr, flash_mem, flash_mem, in_out, addr_inout); // Debe ser modificada de acuerdo a cada código
    //registros[instruction.op1_value] = instruction.op2_value;
	//------- No modificar ------//

    j=0;
    k=0;
    if(regs[15]==0){
    for(i=6;i<17;i=i+2){
    if((j==5)||(j==9)){
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
    move(6,66);
    printw("N=");
	refresh();
	move(8,66);
    printw("Z=");
	refresh();
	move(10,66);
    printw("C=");
	refresh();
	move(12,66);
    printw("V=");
	refresh();
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

	printw("%x            ",regs[j]);
	refresh();	/* Imprime en la pantalla Sin esto el printw no es mostrado */
    if(j==12){
        i=100;
    }
	j++;
    }

    move(6,68);
    printw("%d",bands[0]);
    refresh();
    move(8, 68);
    printw("%d",bands[1]);
    refresh();
    move(10, 68);
    printw("%d",bands[2]);
    refresh();
    move(12, 68);
    printw("%d",bands[3]);
    refresh();
	/* Libera la memoria reservada para las instrucciones */
    getch();
}
}


	for(i=0; i<num_instructions; i++){
		free(read.array[i]);
	}
	free(read.array);
	//---------------------------//

	endwin();	/* Finaliza el modo curses */

	return 0;
	}












