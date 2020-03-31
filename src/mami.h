/*
 * mamizou futashizawa
 * 2020-03-29
*/

#include "keine.h"
#include "mokou.h"
#include "kbase.h"
#include "bios.h"

#include "suwako.h"
#include "kanako.h"

#include "fade.h"
#include "sinlut.h"

// futa is an unfortunate name...

#ifndef MAMIZOU_H
#define MAMIZOU_H

#define MAMI_FB_W ( 0x100 )
#define MAMI_FB_H ( 0x100 )
#define MAMI_FB_LEN ( MAMI_FB_W * MAMI_FB_H )

/* -- enums -- */
typedef enum mami_img {
	IMG_CHECKER = 0,
	IMG_BOREFONT = 1,
	IMG_BOBOFONT = 2,
	IMG_ARCFONT = 3,
	IMG_MAMIZOU = 4,
	IMG_SEVEN = 7
} mami_img;

/* -- structs -- */
typedef struct mami_fc {
	// main
	bios *io; // bios
	RGB16 fb_mem[ MAMI_FB_LEN ]; // framebuffer memory
	keine fb; // framebuffer
	uint32_t time;
	// asset
	keine img_bank[0x10];
	// objects
	kanako suwa_objs;
	suwako suwa_mem[0x200];
} PACKED mami_fc;

typedef struct mami_imginfo { const char *fname;keine_pixelfmt fmt; } mami_imginfo;

/* -- LUTs -- */
extern const mami_imginfo img_lut[];

/* -- main funcs -- */
extern mami_fc *mami_init(mami_fc *futa,bios *io);
extern void mami_updt(mami_fc *futa);
extern void mami_draw(mami_fc *futa);
extern void mami_run(mami_fc *futa);

/* -- asset funcs -- */
extern keine *mami_loadimg(mami_fc *futa,mami_img id);

/* -- draw funcs -- */
extern void mami_flip(mami_fc *futa);
extern void mami_drawarcfont(mami_fc *futa,char *txt,vec2_16 pos);

#endif
