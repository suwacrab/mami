#include "player.h"

/* -- main funcs -- */
void player_init(player *plr)
{
	/* -- player stat settin -- */
	plr->pos = (vec2_16){0,0};
	plr->vel = (vec2_16){0,0};
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
	// vars
	mami_joyp *joyp = &futa->joyp;
	vec2_16 *pos = &plr->pos;
	vec2_16 *vel = &plr->vel;
	/* -- set vel depending on dir */
	s16 yvel = vel->y;
	s16 xvel = vel->x;
	if(joyp->down) yvel += int2fx(4,4);
	if(joyp->up) yvel -= int2fx(4,4);

	if( (joyp->left) || (joyp->right) )
	{
		if(joyp->right) xvel += PLR_WALKSPD;
		if(joyp->left) xvel -= PLR_WALKSPD;
		if(xvel < (-PLR_MAXWALK)) xvel = -PLR_MAXWALK;
	} else
	{
		xvel += (-SIGN(xvel) * PLR_FRC);
	}

	vel->y = yvel; // 4.4 fixed
	vel->x = xvel; // 4.4 fixed
	/* -- move player depending on vel */
	pos->x += ((s16)vel->x); // 4.4 > 12.4
	pos->y += ((s16)vel->y); // 4.4 > 12.4 
}

/* -- draw funcs -- */
void player_drawdebug(player *plr,mami_fc *futa)
{
	// vars
	vec2_16 pos = plr->pos;
	vec2_16 txtpos = { pos.x>>4,pos.y>>4 };
	/* -- print pos -- */
	char txt[0x20];
	sprintf(txt,"POS: %d,%d",pos.x,pos.y);
	printf("%s\n",txt);
	mami_drawarcfont(futa,txt,txtpos);
}
