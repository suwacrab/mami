#include "mami.h"

/* -- main funcs -- */
mami_fc *mami_init(mami_fc *futa,bios *io)
{
	/* -- main init -- */
	futa->io = io;
	RGB16 *fb_mem = futa->fb_mem;
	keine *fb = &futa->fb;
	// framebuffers
	fb->w = MAMI_FB_W; fb->h = MAMI_FB_H;
	fb->m = fb_mem;
	fb->fmt = KEINE_PIXELFMT_RGB15;
	fb->pal0 = NULL; fb->pal1 = NULL;
	fb->fillp = 0xFFFF;
	// debug print
	printf("biosram: $%08lX ($%08lX)\n",(uptr)io,sizeof(bios));
	printf("mamizou: $%08lX ($%08lX)\n",(uptr)futa,sizeof(mami_fc));
	
	/* -- asset loading -- */
	keine *img_bank = futa->img_bank;
	mami_loadimg(futa,IMG_CHECKER,"gfx/checker.bmp",KEINE_PIXELFMT_PAL4);
	return futa;
}

void mami_run(mami_fc *futa)
{
	/* -- main loop -- */
	bios *io = futa->io;

	while( !io->quit )
	{
		// update
		bios_update(io);
		keine_clear(&futa->fb);
		mami_updt(futa);
		// draw
		mami_draw(futa);
		// vsync
		mami_flip(futa);
		futa->time++;
	}
}

void mami_updt(mami_fc *futa)
{

}
void mami_draw(mami_fc *futa)
{
	// vars
	keine *fb = &futa->fb;
	// test draw
	keine *checker = &futa->img_bank[IMG_CHECKER];
	mokou_attr attr1 = { 
		.src=checker,.dst=fb,
		.srcrect={ 0,0,checker->w,checker->h },
		.pos={ {futa->time,0} },
		.mode=0,.fillp=0xFFFF,
		.flip=0
	};
		
	mokou_sprN( &attr1 );
}

/* -- asset funcs -- */
keine *mami_loadimg(mami_fc *futa,mami_img id,const char *fname,keine_pixelfmt fmt)
{
	keine_loadimg(&futa->img_bank[id],fname,fmt);
}

/* -- draw funcs -- */
void mami_flip(mami_fc *futa)
{
	/* -- copy fb to window -- */
	bios *io = futa->io;
	keine *fb = &futa->fb;
	SDL_Surface *window = io->window;
	SDL_Rect copyrect = { .x=0,.y=0,.w=1,.h=1 };
	
	for( u32 y=0; y<fb->h; y++ )
	{
		copyrect.y = y;
		for( u32 x=0; x<fb->w; x++ )
		{
			copyrect.x = x;
			RGB16 pix = mokou_pget16(fb,x,y);
			u32 clr = SDL_MapRGB(window->format,
				(pix&31)<<3,((pix>>5)&31)<<3,(pix>>10)<<3
			);
			SDL_FillRect(window,&copyrect,clr);
		}
	}

	bios_flip(io);
}

