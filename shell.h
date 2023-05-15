#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void splitWord(char **arg, char *str);
#endif
