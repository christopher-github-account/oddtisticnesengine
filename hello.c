//some of this code was written by someone else. not AI tho
#include "neslib.h"

// link the pattern table into CHR ROM
//#link "chr_generic.s"

/*
	Version 0.00 by oddtistic chris [6/7/2026] <- funny number
        
        Stuff to GENUINELY add:
                2)
                4)
                5)
                6)
                7)
*/

void draw_sprite(int sprite, int x, int y)
{
     oam_spr(x, y, sprite, 0, 0); 
}


int x = 0;
int y = 0;

// main function, run after console reset
void main(void) {

  // set palette colors
  pal_col(0, 0x02);
  pal_col(1,0x14);	// fuchsia
  pal_col(2,0x10);	// grey
  pal_col(3,0x30);	// white
  
  while(1)
  {
    char pad = pad_poll(0);
    if (pad&PAD_LEFT) x -= 1;
    if (pad&PAD_RIGHT) x += 1;
    if (pad&PAD_UP) y -= 1;
    if (pad&PAD_DOWN) y += 1;
    draw_sprite(0x30, x, y);
    ppu_on_all();
  }
  // write text to name table
  vram_adr(NTADR_A(2,2));		// set address
  vram_write("HELLO, WORLD!", 13);	// write bytes to video RAM

  // enable PPU rendering (turn on screen)
  

  // infinite loop
}
