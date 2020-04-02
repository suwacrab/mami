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
	player_drawmami(plr,futa);
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
	
	if( (joyp->left) || (joyp->right) )
	{
		if(joyp->right) {
			if(xvel < 0) { xvel += PLR_DECWALK; if(xvel >= 0) xvel = 0x008; }
			else if(xvel < PLR_MAXWALK) xvel += PLR_WALKSPD;
		}
		if(joyp->left) xvel -= PLR_WALKSPD;
		if(xvel < (-PLR_MAXWALK)) xvel = -PLR_MAXWALK;
		if(xvel > (PLR_MAXWALK)) xvel = PLR_MAXWALK;
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
void player_drawmami(player *plr,mami_fc *futa)
{
	// vars
	vec2_16 pos = plr->pos;
	vec2_16 vel = plr->vel;
	keine *fb = &futa->fb;
	keine *mami_img = &futa->img_bank[IMG_MAMIZOU];
	/* rect gettin & drawin */
	u32 frame = 0;
	u32 anim = 0;
	s32 px = ((s32)pos.x>>PLR_SHF) - 16;
	s32 py = ((s32)pos.y>>PLR_SHF) - 16;
	mokou_attr attr = {
		.src=mami_img,.dst=fb,
		.srcrect = {frame*32,anim*32,32,32},
		.pos = { {px,py} },
		.mode = 0,.fillp = 0xFFFF,
		.flip = 0
	};

	mokou_sprN( &attr );
}
void player_drawdebug(player *plr,mami_fc *futa)
{
	// vars
	vec2_16 pos = plr->pos;
	vec2_16 vel = plr->vel;
	vec2_16 txtpos = { pos.x>>4,pos.y>>4 };
	/* -- print pos -- */
	char txt[0x40];
	float fpx = (float)pos.x / (PLR_DEC);
	float fpy = (float)pos.y / (PLR_DEC);
	float fvx = (float)vel.x / (PLR_DEC);
	float fvy = (float)vel.y / (PLR_DEC);
	sprintf(txt,"POS: %.2f,%.2f\nVEL: %.2f,%.2f",fpx,fpy,fvx,fvy);
	mami_drawarcfont(futa,txt,0,0);
}
