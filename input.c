/*
 * input.c
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 *
 */

#include "global.h"

const char struct socket_commands[] = {
  { "/join",    input_join },
  { "/nick",    input_setnick },
  { "/quit",    input_quit },
  { "/help",    input_help }
};


void
input_help(void) {

}

void
input_setnick(char nickname[]) {

}

void
input_join(char chan_name[]) {

}

int
input_quit(char msg[]) {
  return EXIT_SUCCESS;
}
