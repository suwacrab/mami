#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "kbase.h"

#ifndef BIOS_H
#define BIOS_H

/* -- types -- */
#define BIOS_RAM_SIZE ( MBSIZE(1) )
typedef u8 bios_ram[ BIOS_RAM_SIZE ];
/*	--	structs	--	*/
typedef struct bios {
	// screen vars
	SDL_Surface *window;
	uint32_t w,h;
	// event vars
	SDL_Event inpevent;
	uint8_t *keystate;
	uint32_t time;
	bool quit;
	// game vars
	bios_ram mem;
} bios;

/*	--	main funcs	--	*/
extern void bios_init(bios *kernel,u32 w,u32 h);

/*	--	update funcs	--	*/
extern void bios_boot(bios *kernel);
extern void bios_update(bios *kernel);
extern void bios_checkquit(bios *kernel);

/*	--	draw functions --	*/
extern void bios_draw(bios *kernel);
extern void bios_clearscreen(bios *kernel);

#endif
