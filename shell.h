#ifndef SHELL_H
#define SHELL_H

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
#include <signal.h>

/* PROMPT/CMD FUNCS */
void print_prompt1(void);
void print_prompt2(void);
char *read_cmd(void);
void executecmd(char **av, char **toks, char *path, char *cmd, int count);

/* TOKEN FUNCS */
char **tokenArray(char *cmd, char *delim, int signal);
void free_toks(char **toks);
size_t countword(char *str, char delim);
char *check_path(char *str);
char *find_path(char **toks);

/* STRING FUNCS */
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *estrcat(char *dest, char *src, int i);
char *_bstrcat(char *dest, char *src);
char *funkycat(char *dest, char *middle, char *src);

/* MISC FUNCS */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void dirchg(char **cmdtoks, char **av, int count);
char *_memset(char *s, char b, unsigned int n);
void execError(char *av, char *input, int count);
void errorhandler(char *av, char *input, int count);
int compareStr(char **av, char *cmd, char **toks, int count);
char *int_to_str(int n, char *str);
char *check_cwd(char *pathstr);

#endif
