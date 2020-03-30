/* main file
 * mamizou platformer
 * by suwacrab 2020-03-30
 * touhou project by team shanghai alice
*/

/* -- includes -- */
#include "kbase.h"
#include "bios.h"
#include "mami.h"

/* -- funcs -- */
#define WIDTH (256)
#define HEIGHT (160)

/* -- vars -- */
bios sdl_bios;
mami_fc *mami;

/* -- funcs -- */
void init();
void boot();

/* -- func defs -- */
int main(void)
{
	init();
	boot();
	return 0;
}

void init()
{
	bios_init(&sdl_bios,WIDTH,HEIGHT);
	mami = (mami_fc*)sdl_bios.mem;
	mami_init(mami,&sdl_bios);
}
void boot()
{
	mami_run(mami);
}

