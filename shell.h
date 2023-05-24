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

extern char **environ;

int _strcmp(const char *str1, const char *str2);
int  _strlen(const char *str);
char *_strdup(const char *str);
int _strncmp(const char *str1, const char *str2, size_t n);

char *remove_quotes(const char *str);
void splitWord(char **arg, char *str);
void print_env(void);
char *_getenv(char *val);
void refactcmd(char *path, char *path_token, char *cmd);
void execute(char *arg[]);
char *get_location(char *cmd);
#endif
