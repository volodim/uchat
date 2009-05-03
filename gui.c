/*
 * gui.c
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 *
 */

#include "global.h"

int
init_screen(void) {
  int ch;

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();

  printw("Welcome to uChat IRC Client.\n");
  mvprintw(67, 0, "status bar goes here.\n");
  ch = getch();
  return 0;
}
