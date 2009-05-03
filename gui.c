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
     scrollok(stdscr, TRUE);
     printw("uChat IRC Client.\n");
     refresh();
}

void
init_mainwin(void) {
    WINDOW *mainwin;

    int height = (LINES - 5);
    int width = COLS;
    int starty = 2;
    int startx = 0;
    mainwin = newwin(height, width, starty, startx);
    box(mainwin, 0, 0);
    wprintw(mainwin, "The main windows: here come the messages\n");
    wrefresh(mainwin);
}
