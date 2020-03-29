/*
 * mamizou futashizawa
 * 2020-03-29
*/

#include "kbase.h"
#include "bios.h"

// futa is an unfortunate name...

#ifndef MAMIZOU_H
#define MAMIZOU_H

typedef struct mami_fc {
	bios *io;
} mami_fc;

/* -- main funcs -- */
extern mami_fc *mami_init(mami_fc *futa,bios *io);


#endif
