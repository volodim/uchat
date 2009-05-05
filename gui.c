/*
 * gui.c
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 *
 */

#include "global.h"

void
init_gui(void)
{
     int bg = -1;

     initscr();
     noecho();
     keypad(stdscr, TRUE);
     printw("uChat IRC Client.\n");

     /* Color support */
     start_color();
     bg = (use_default_colors() == OK) ? -1 : COLOR_BLACK;
     init_pair(0, bg, bg);
     init_pair(1, COLOR_BLACK, COLOR_GREEN);

     /* Init main window and the borders */
     mainwin = newwin(LINES - 2, COLS, 1, 0);
     scrollok(mainwin, TRUE);
     wrefresh(mainwin);

     /* Init input window */
     inputwin = newwin(1, COLS, LINES - 1, 0);
     wmove(inputwin, 0, 0);
     wrefresh(inputwin);

     /* Init status window (with the hour / current chan) */
     statuswin = newwin(1, COLS, LINES - 2, 0);
     wbkgd(statuswin, COLOR_PAIR(1));
     wrefresh(statuswin);

     refresh();

     return;
}

void
gui_update_statuswin(void)
{
     werase(statuswin);

     mvwprintw(statuswin, 0, 0, "[%s]", global_date);

     wbkgd(statuswin, COLOR_PAIR(1));

     wrefresh(statuswin);

     return;
}

void
gui_get_input(InputBufStruct *ib)
{
     int i, c;

     halfdelay(1);

     switch((c = getch()))
     {
     case UCHAT_KEY_ENTER:
          if(ib->pos || strlen(ib->buffer))
          {
               input_manage(ib->buffer);
               werase(inputwin);
               memset(ib->buffer, 0, 1024);
               ib->pos = 0;
               wmove(inputwin, 0, ib->pos);
          }
          break;

     case KEY_LEFT:
          if(ib->pos >= 1)
          {
               --(ib->pos);
               wmove(inputwin, 0, ib->pos);
          }
          break;

     case KEY_RIGHT:
          if(ib->buffer[ib->pos] != 0)
          {
               ++(ib->pos);
               wmove(inputwin, 0, ib->pos);
          }
          break;

     case 127:
     case KEY_BACKSPACE:
          if(ib->pos >= 1)
          {
               --(ib->pos);
               wmove(inputwin, 0, ib->pos);
               ib->buffer[ib->pos] = '\0';
               wdelch(inputwin);
          }
          break;

     case KEY_DC:
          wdelch(inputwin);
          if(ib->buffer[ib->pos] != 0
             && ib->pos >= 0)
               for(i = ib->pos; i < (int)strlen(ib->buffer); ++i)
                    ib->buffer[i] = ib->buffer[i + 1];
          break;

     case KEY_HOME:
          wmove(inputwin, 0, 0);
          ib->pos = 0;
          break;

     case KEY_END:
          wmove(inputwin, 0, strlen(ib->buffer));
          ib->pos = strlen(ib->buffer);
          break;

     default:
          if(c > 0 && strlen(ib->buffer) < BUFSIZE)
          {
               ib->buffer[ib->pos] = c;
               ++(ib->pos);
               winsch(inputwin, c);
               wmove(inputwin, 0, ib->pos);
          }
          break;
     }

     wrefresh(inputwin);

     return;
}
