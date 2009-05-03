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

  /*   int ch;

   while ((ch = getopt(argc, argv, "c:n:")) != 1) {
      switch (ch) {
         case 'c':
               break;
	 case 'n':
               break;
         case '?':
               usage();
      }
   }*/

   printf("uchat starting\n");
   init_screen();

   endwin();

   return 0;
}
