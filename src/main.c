#include "kbase.h"
#include "bios.h"
#include "mami.h"

#define WIDTH (256)
#define HEIGHT (224)

bios sdl_bios;
mami_fc *mami;

void init();

int main(void)
{
	init();
	return 0;
}

void init()
{
	bios_init(&sdl_bios,WIDTH,HEIGHT);
	mami = (mami_fc*)sdl_bios.mem;
	mami_init(mami,&sdl_bios);
}
