/*
 * main.c
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 * Copyright (C) xorg62 - 2009
 * <xorg62@gmail.com>
 *
 */

#include "global.h"

void
usage(void) {
   fprintf(stderr, "uchat: must writting some help, heh :)\n");
   exit(1);
}

int
main(int argc, char *argv[]) {

     int n;
     char buffer[BUFSIZE] = { 0 };
     InputBufStruct ib;
     fd_set fd;
     static struct timeval timeout;
     int online = 0;

     memset(ib.buffer, 0, BUFSIZE);
     ib.pos = 0;

     if(argc > 1) {
     int ch;
      while ((ch = getopt(argc, argv, "c:n:")) != 1) {
       switch (ch) {
         case 'c':
               break;
	 case 'n':
               break;
         case '?':
               usage();
       }
      }
     }

   running = 1;
   printf("uchat starting\n");

   init_gui();
   gui_get_input(&ib);

   while(running)
   {
        timeout.tv_sec = 0;
        timeout.tv_usec = 10000;
        FD_ZERO(&fd);
        FD_SET(STDIN_FILENO, &fd);

        if(Socket >= 0)
             FD_SET(Socket, &fd);

        if(select(FD_SETSIZE, &fd, NULL, NULL, &timeout))
        {
             if(FD_ISSET(STDIN_FILENO, &fd))
                  gui_get_input(&ib);
             else
             {
                  if(Socket >= 0 && (FD_ISSET(Socket, &fd)))
                  {
                       memset(buffer, 0, BUFSIZE);
                       n = recv(Socket, buffer, BUFSIZE, 0);

                       if(n > 0)
                       {
                            wprintw(mainwin, buffer);
                            wrefresh(mainwin);
                       }
                  }
             }
        }


        gui_update_statuswin(online);

        /* Alway put cursor in the inputwin */
        wmove(inputwin, 0, ib.pos);
        wrefresh(inputwin);
   }
   clear();
   endwin();

   return 0;
}
