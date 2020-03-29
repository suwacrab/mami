#include "mami.h"

/* -- main funcs -- */
mami_fc *mami_init(mami_fc *futa,bios *io)
{
	printf("biosram: %p\n",io);
	printf("mamizou: %p\n",futa);
	futa->io = io;
	return futa;
}
