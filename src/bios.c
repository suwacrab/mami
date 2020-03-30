#include "bios.h"

/*	--	 main functions	--	*/
void bios_init(bios *kernel,u32 w,u32 h)
{
	/*	--	sdl init	--	*/
	// main
	s32 sdlflags = SDL_INIT_VIDEO | SDL_INIT_AUDIO;
	if( SDL_Init(sdlflags) < 0 )
	{ printf("couldn't init sdl: '%s'\n",SDL_GetError()); exit(-1); }
	// video
	s32 vidflags = SDL_SWSURFACE;
	kernel->window = SDL_SetVideoMode(w,h,16,vidflags);
	kernel->w = w; kernel->h = h;
	// event
	kernel->quit = false;
	kernel->time = 0;
	kernel->keystate = SDL_GetKeyState(NULL);
}

/*	--	update funcs	--	*/
void bios_update(bios *kernel)
{
	// update input
	SDL_PumpEvents();
	bios_checkquit(kernel);
}
void bios_checkquit(bios *kernel)
{
	kernel->quit = kernel->keystate[SDLK_ESCAPE];
}

/*	--	draw funcs	--	*/
void bios_draw(bios *kernel)
{
	bios_clearscreen(kernel);
}
void bios_clearscreen(bios *kernel)
{
	SDL_Surface *window = kernel->window;
	// clear window
	SDL_Rect windowrect = { 0,0,kernel->w,kernel->h };
	SDL_FillRect(window,&windowrect,
		SDL_MapRGB(window->format,0,0,0)
	);
}
void bios_flip(bios *kernel)
{
	SDL_Delay(SDL_SECOND/60);
	SDL_Flip(kernel->window);
}
