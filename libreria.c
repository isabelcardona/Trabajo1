#include "instrucciones.h"
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <curses.h>
#include "io.h"


void mostrar_registros(uint32_t* regs, uint32_t* bands) 
{
    attron(COLOR_PAIR(1));

    int i,j,k;
    j=0;
    k=0;
    for(i=6;i<17;i=i+2){
    if((j==5)||(j==9)){
        k=k+22;
        i=6;
    }


	move(i, k);	/** Mueve el cursor a la posición i,k*/
	printw("R%d=",j);
	refresh();	/** Imprime en la pantalla
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
	attroff(COLOR_PAIR(1));	/** DEshabilita los colores Pair 1 */

    attron(COLOR_PAIR(2));
    j=0;
    k=0;
    for(i=6;i<17;i=i+2){
    if((j==5)||(j==9)){
        k=k+22;
        i=6;
    }
    move(i, k+3);	/** Mueve el cursor a la posición i,k*/
    if(j>9){
       move(i, k+4);	/** Mueve el cursor a la posición i,k*/
    }

	printw("%x            ",regs[j]);
	refresh();	/** Imprime en la pantalla Sin esto el printw no es mostrado */
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
	attroff(COLOR_PAIR(2));

}


void mostrar_sram(uint32_t* mem, uint32_t* addr)
{
    int i,j,k;
    k=0;
    attron(COLOR_PAIR(2));
    for(i=0;i<25;i++){
            for(j=0;j<80;j++){
                 move(i,j);
                 printw(" ");
                 refresh;
            }
    }
    attroff(COLOR_PAIR(2));



    attron(COLOR_PAIR(1));
    for(i=0,j=6;i<128;i++,j++){
        mvprintw(j, k, "%x",addr[i]);
        if((j==20)||(j==39)||(j==58)||(j==77)||(j==96)||(j==115))
        {
            k+=20;
            j=5;
        }
    }
    k=10;
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    for(i=0,j=6;i<128;i++,j++){
        mvprintw(j, k, "%x",mem[i]);
        if((j==20)||(j==39)||(j==58)||(j==77)||(j==96)||(j==115))
        {
            k+=20;
            j=5;
        }
    }
    attroff(COLOR_PAIR(2));
}


void mostrar_iomem(uint32_t* in_out, uint32_t* addr_inout){
    int i,j,k;
    k=0;
    attron(COLOR_PAIR(2));
    for(i=0;i<25;i++){
            for(j=0;j<80;j++){
                 move(i,j);
                 printw(" ");
                 refresh;
            }
    }
    attron(COLOR_PAIR(3));
    mvprintw(6, 0, "PORT-A");
    mvprintw(8, 0, "DDR");
    mvprintw(10, 0, "PORT");
    mvprintw(12, 0, "PIN");
    mvprintw(14, 0, "INTERRUPT");
    mvprintw(6, 40, "PORT-B");
    mvprintw(8, 40, "DDR");
    mvprintw(10, 40, "PORT");
    mvprintw(12, 40, "PIN");
    mvprintw(14, 40, "INTERRUPT");
    attroff(COLOR_PAIR(3));

    attron(COLOR_PAIR(2));
    mvprintw(8, 10, "%x",in_out[0]);
    mvprintw(10, 10, "%x",in_out[1]);
    mvprintw(12, 10, "%x",in_out[2]);
    mvprintw(14, 10, "%x",in_out[3]);

    mvprintw(8, 50, "%x",in_out[10]);
    mvprintw(10, 50, "%x",in_out[11]);
    mvprintw(12, 50, "%x",in_out[12]);
    mvprintw(14, 50, "%x",in_out[13]);
    attroff(COLOR_PAIR(2));

}



