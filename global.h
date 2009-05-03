/*
 * global.h
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 *
 */

#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>

#define IRC_NICK  volodim
#define IRC_SERV  irc.freenode.net

/*
 * Prototypes
 */

/* gui.c */
int init_screen(void);

#endif
