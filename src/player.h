#include "mami.h"

#ifndef PLAYER_H
#define PLAYER_H

/* -- structs -- */
typedef struct player
{
	// suwa props
	suwa_stat stat;
	// player props
	vec2_16 pos; vec2_8 vel; // pos (12.4) & vel (4.4), $06
	s8 hp,maxhp; // hp & maxhp, $02
	
} PACKED player;

/* -- main funcs -- */
extern void player_init(player *plr);
extern void player_updt(player *plr,mami_fc *futa);
extern void player_draw(player *plr,mami_fc *futa);

/* -- draw funcs -- */
extern void player_drawdebug(player *plr,mami_fc *futa);

/* -- updt funcs -- */
extern void player_updtmove(player *plr,mami_fc *futa);

#endif
