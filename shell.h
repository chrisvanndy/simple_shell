#ifndef SHELL_H
#define SHELL_H

extern char **environ;

/* INCLUDES */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <unistd.h>

/* STRUCTS */

/* PROMPT/CMD FUNCS */
void print_prompt1(void);
void print_prompt2(void);
char *read_cmd(void);
int executecmd(char  **tokens);

/* STRING FUNCS */
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
size_t countword(char *cmd);
char **tokenArray(char *cmd);
void free_toks(char **toks);

/* MISC FUNCS */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);

#endif
