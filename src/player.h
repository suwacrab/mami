#include "mami.h"

#ifndef PLAYER_H
#define PLAYER_H

/* -- const defs -- */

// shift & decimal
#define PLR_SHF (4)
#define PLR_DEC (1<<4)
// max walkspeed ()
#define PLR_MAXWALK (0x030)
// walkspeed (1.00)
#define PLR_WALKSPD (0x004)
// friction (0.50
#define PLR_FRC (0x002)

/* -- structs -- */
typedef struct player
{
	// suwa props
	suwa_stat stat;
	// player props
	vec2_16 pos; vec2_16 vel; // pos (12.4) & vel (4.4), $06
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
