#include <stdio.h>
#include <stdlib.h>
#include "instrucciones.h"
#include "libreria.h"
#include "decoder.h"
#include <math.h>
#include <stdint.h>
#include <curses.h>
#include "io.h"

int main()
{

    uint32_t regs[16]={0},rd,rm,imm,r, mem[128]={0}, address=0, addr[128]={0}, interrup_regs[16], flash_mem[33], addr_flash[33], in_out[14], addr_inout[14];
    regs[13]=0x2000007f; // posicion de sp para una memoria de 128 bytes;
    int i,j,k,num_instructions,bands[4]={0},pc=0,op;
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

	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);	/* Pair 1 -> Texto verde
											   fondo Negro */
		/*border( ACS_VLINE, ACS_VLINE,
			ACS_HLINE, ACS_HLINE,
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);*/



	attron(COLOR_PAIR(1));	/* Activa el color verde para el
							  // texto y negro para el fondo Pair 1*/
    move(0, 20);
    printw("EMULADOR DE PROCESADOR ARM Cortex-M0_V6");
	refresh();
		/* Imprime en la pantalla
					Sin esto el printw no es mostrado */
    //move(4,9);//getch();
    attroff(COLOR_PAIR(1));



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
    for(i=0;i<14;i++){
        addr_inout[i]=0x40000000+i;
    }

    attron(COLOR_PAIR(2));
    move(6, 0);
    printw("Ingrese:\n 1:mostrar registros\n 2:mostrar Sram\n 3:mostrar puertos i/o");
	refresh();
	attroff(COLOR_PAIR(2));

while(1){
    NVIC(interrup_regs, flash_mem, regs, bands, mem);
for(regs[15]=0; regs[15]<num_instructions; regs[15]++){
    instruction = getInstruction(instructions[regs[15]]); // Instrucción en la posición 0
	decodeInstruction(instruction, regs, bands, mem, address, addr, flash_mem, flash_mem, in_out, addr_inout); // Debe ser modificada de acuerdo a cada código


    //mostrar_registros(regs, bands);


	scanf("%d",&op);
	switch (op)
	{
	    case 1: mostrar_registros(regs, bands);
	    break;
	    case 2: mostrar_sram(mem,addr);
	    break;
	    case 3: mostrar_iomem(in_out, addr_inout);
	    break;
	}

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













