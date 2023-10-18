#ifndef HEAD_H
#define HEAD_H
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>
extern char **environ;
int _strlen(char *s);
char *_strdup(char *str);
int _putstring(char *s);
int _putchar(char c);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
char *_getenv(char *varname);
char *location(char *command);
char **fill(char *command);
void free_grid(char **grid);
int _check(char **arg, int status, char *command);
int _fork(int status, char *path, char **args, int err);
char *handle_int(int n);
void errors(int er, char *command);
char *error(char *str, int n);
int compare_string(char *s1, char *s2);
void print_environ(char **environ);
int _strncmp(char *str1, char *str2, size_t n);
char *_strtok(char *str, char delim);
#endif
