/*
 * mamizou futashizawa
 * 2020-03-29
*/

#include "keine.h"
#include "mokou.h"
#include "kbase.h"
#include "bios.h"

// futa is an unfortunate name...

#ifndef MAMIZOU_H
#define MAMIZOU_H

#define MAMI_FB_W ( 0x100 )
#define MAMI_FB_H ( 0x100 )
#define MAMI_FB_LEN ( MAMI_FB_W * MAMI_FB_H )

/* -- enums -- */
typedef enum mami_img {
	IMG_CHECKER = 0
} mami_img;

/* -- structs -- */
typedef struct mami_fc {
	// main
	bios *io; // bios
	RGB16 fb_mem[ MAMI_FB_LEN ]; // framebuffer memory
	keine fb; // framebuffer 
	// asset
	keine img_bank[0x10];
	// game
	uint32_t time;
} PACKED mami_fc;

/* -- main funcs -- */
extern mami_fc *mami_init(mami_fc *futa,bios *io);
extern void mami_updt(mami_fc *futa);
extern void mami_draw(mami_fc *futa);
extern void mami_run(mami_fc *futa);

/* -- asset funcs -- */
extern keine *mami_loadimg(mami_fc *futa,mami_img id,const char *fname,keine_pixelfmt fmt);

/* -- draw funcs -- */
extern void mami_flip(mami_fc *futa);

#endif
