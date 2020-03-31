#include "mami.h"

/* -- LUTs -- */
const mami_imginfo img_lut[] = {
	/* 00 */ {"gfx/checker.bmp",KEINE_PIXELFMT_PAL4},
	/* 01 */ {"gfx/borefont.png",KEINE_PIXELFMT_PAL4},
	/* 02 */ {"gfx/bobofont.bmp",KEINE_PIXELFMT_PAL4},
	/* 03 */ {"gfx/arcfont.bmp",KEINE_PIXELFMT_PAL4},
	/* 04 */ {"gfx/mamizou.bmp",KEINE_PIXELFMT_PAL4},
	/* 05 */ {NULL},
	/* 06 */ {NULL},
	/* 07 */ {"gfx/seven.bmp",KEINE_PIXELFMT_PAL4},
	/* 08 */ {NULL}
};

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
	const mami_imginfo *info = img_lut;
	mami_loadimg(futa,IMG_CHECKER);
	mami_loadimg(futa,IMG_BOREFONT);
	mami_loadimg(futa,IMG_BOBOFONT);
	mami_loadimg(futa,IMG_ARCFONT);
	mami_loadimg(futa,IMG_MAMIZOU);
	mami_loadimg(futa,IMG_SEVEN);
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
	bios *io = futa->io;
	keine *fb = &futa->fb;
	uint32_t time = futa->time;
	// obj drawin
	u32 ntime = fixmul2(lu_cos(time<<8),256,12) & 0xFF;
	u32 range = fixmul2(lu_cos(time<<7),32,12);
	for( u32 ang = ntime; ang < ntime+0x100; ang += 0x20 )
	{
		vec2_16 pos;
		// 0xFF > 0xFF00
		f16 sx = lu_cos(ang<<8) + (1<<6);
		f16 sy = lu_sin(ang<<8) + (1<<6);
		pos.x = (io->w>>1) + fixmul2(lu_cos(ang<<8),range,12);
		pos.y = (io->h>>1) + fixmul2(lu_sin(ang<<8),range,12);
		keine *img = &futa->img_bank[IMG_SEVEN];
		mokou_attr attr1 = { 
			.src=img,.dst=fb,
			// 0xFF > 0x07
			.srcrect={ ((ang>>5)&7)*16,0, 16,16 },
			.pos={ {pos.x,pos.y} },
			.mode=0,.fillp=0xFFFF,
			.flip=0
		};
			
		mokou_sprN( &attr1 );
	}

	// text drawin
	vec2_16 txtpos = { 0,io->h-8 };
	char txt[0x20];
	sprintf(txt,"TIME: %04X\n",futa->time);
	mami_drawarcfont(futa,txt,txtpos);
}

/* -- asset funcs -- */
keine *mami_loadimg(mami_fc *futa,mami_img id)
{
	keine *img = NULL;
	const mami_imginfo *info = &img_lut[id];
	if( access(info->fname,F_OK) != -1 )
	{
		keine *img = keine_loadimg(&futa->img_bank[id],info->fname,info->fmt);
		printf("<img loaded> [$%02X] [$%08lX] '%s'\n",id,(uptr)img,info->fname);
	} else {
		printf("<img load failed> file '%s' doesn't exist...\n",info->fname);
		exit(-1);
	}
	return img;
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
void mami_drawarcfont(mami_fc *futa,char *txt,vec2_16 pos)
{
	// vars
	keine *font = &futa->img_bank[IMG_ARCFONT];
	mokou_attr attr = {
		.src=font,.dst=&futa->fb,
		.srcrect={ 40,40,8,8 },
		.pos={ {0,0} },
		.mode=0,.fillp=0xFFFF,
		.flip=0
	};
	u32 len = strlen(txt);
	u32 ox,oy;
	ox = oy = 0;
	/* -- text drawin -- */
	for( u32 i=0; i<len; i++ )
	{
		u8 c = txt[i];
		if( c == '\n' )
		{ ox=0; oy++; }
		else
		{
			attr.pos[0] = (vec2_16){ pos.x + (ox*8),pos.y + (oy*8) };
			attr.srcrect = (SDL_Rect){ (c&15)*8,(c>>4)*8,8,8 };
			mokou_sprN( &attr );
			ox++;
		}
	}
}
