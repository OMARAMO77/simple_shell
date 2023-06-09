#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

extern char **environ;


int main(int argc, char **argv, char **env);
int _putchar(char c);
void prompt(void);
void handle_sigint();	/* don't change it for betty */
char *_strncpy(char *dest, char *src, int n);
char *path_to(const char *filename);
int check_path(const char *command, char ch);
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);
int _strncmp(const char *s1, const char *s2, int n);
int _strcmp(const char *s1, const char *s2);
char *exe_cmd(char *cmd);
void errmsg(char *hsh, int cmdnum, char *cmd);
int _atoi(char *s);
int empty(char ch);
int emp_str(char *cmd);


#endif
