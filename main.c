/*
 * main.c
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
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
     char buffer[BUFMAX] = { 0 };
     InputBufStruct ib;
     fd_set fd;
     static struct timeval timeout;

     memset(ib.buffer, 0, BUFMAX);
     ib.pos = 0;

  /*
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
  */

   running = 1;
   printf("uchat starting\n");

   init_connection();
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
                       memset(buffer, 0, BUFMAX);
                       n = recv(Socket, buffer, BUFMAX, 0);

                       if(n > 0)
                       {
                            wprintw(mainwin, buffer);
                            wrefresh(mainwin);
                       }
                  }
             }
        }

        wmove(inputwin, 0, ib.pos);
        wrefresh(inputwin);
        gui_update_statuswin();
   }

   close(Socket);
   endwin();

   return 0;
}
