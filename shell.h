#ifndef SHELL_H
#define SHELL_H
#define EOF (-1)
extern char **environ;

/* INCLUDES */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>

/* STRUCTS */

/* PROMPT/CMD FUNCS */
void print_prompt1(void);
void print_prompt2(void);
char *read_cmd(void);
int executecmd(char **tokens, char *cmd);

/* TOKEN FUNCS */
char **tokenArray(char *cmd);
void free_toks(char **toks);
size_t countword(char *cmd);

/* STRING FUNCS */
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_bstrcat(char *dest, char *src);

/* MISC FUNCS */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);

#endif
