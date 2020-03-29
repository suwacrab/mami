#include "keine.h"

#ifndef MOKOU_H
#define MOKOU_H

/* -- sprite modes -- */
/*
 * 0b000 - normal sprite, pos[0] is used
 * 0b001 - scaled sprite, pos[0] and pos[2] are used
 * 0b010 - distorted sprite, all 4 coords are used
*/


typedef struct mokou_attr
{
	keine *src,*dst;
	SDL_Rect *srcrect;
	vec2_16 pos[4]; 
	u16 mode,fillp;
	u8 flip;
} mokou_attr;

/*	--	pset functions	--	*/
extern RGB8 *mokou_pread4(keine* yago,u32 x, u32 y);
extern void mokou_pset4(keine* yago,s32 x, s32 y,RGB8 c);
extern RGB8 mokou_pget4(keine* yago,s32 x, s32 y);

extern RGB8 *mokou_pread8(keine* yago,u32 x, u32 y);
extern void mokou_pset8(keine* yago,s32 x, s32 y,RGB8 c);
extern RGB8 mokou_pget8(keine* yago,s32 x, s32 y);

extern RGB16 *mokou_pread16(keine* yago,u32 x, u32 y);
extern void mokou_pset16(keine* yago,s32 x, s32 y,RGB16 c);
extern RGB16 mokou_pget16(keine* yago,s32 x, s32 y);
extern void mokou_rect16(keine *yago,s32 px,s32 py,s32 dx,s32 dy,RGB16 c);

/*	--	fill functions	--	*/
extern void mokou_sprN( mokou_attr *attr; );

#endif
