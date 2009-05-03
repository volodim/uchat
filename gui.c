/*
 * gui.c
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 *
 */

#include "global.h"

int
init_screen(void)
{
     initscr();
     keypad(stdscr, TRUE);
     scrollok(stdscr, TRUE);
     printw("Welcome to uChat IRC Client.\n");
     refresh();

     return 0;
}
