/*
 * gui.c
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 *
 */

#include "global.h"

void
init_screen(void)
{
     initscr();

     keypad(stdscr, TRUE);
     printw("uChat IRC Client.\n");

     /* Init main window and the borders */
     mainwin = newwin(LINES - 2, COLS, 1, 0);
     scrollok(mainwin, TRUE);

     refresh();
     wrefresh(mainwin);

     return;
}

