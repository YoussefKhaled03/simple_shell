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
unsigned int i = 0;
pid_t status;
int _strlen(char *s);
char *_strdup(char *str);
int _putstring(char *s);
int _putchar(char c);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
char *_getenv(const char *varname);
char *location(char *command);
char **fill(char *command);
void free_grid(int **grid, int height);
#endif
