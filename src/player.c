#include "player.h"

/* -- main funcs -- */
void player_init(player *plr)
{
	/* -- player stat settin -- */
	plr->pos = (vec2_16){16,32};
	plr->vel = (vec2_8){0,0};
	plr->maxhp = 5;
	plr->hp = plr->maxhp;
	
	// debug printin
	printf("player: $%08lX [$%08lX]\n",(uptr)plr,sizeof(player));
}
void player_draw(player *plr,mami_fc *futa)
{
	player_drawdebug(plr,futa);
}
void player_updt(player *plr,mami_fc *futa)
{
	player_updtmove(plr,futa);
}

/* -- update funcs -- */
void player_updtmove(player *plr,mami_fc *futa)
{

}

/* -- draw funcs -- */
void player_drawdebug(player *plr,mami_fc *futa)
{
	
}
