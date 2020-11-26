#ifndef SHELL_H_
#define SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/stat.h>


extern char **environ;
char **divide_string(char *str, char *divide);
void exe(char **args, char *str);
char *_strdup(char *str);
char *_concat(char *str, char *strconcat);
char *space_delete(char *str, int index);
char *getpath(const char *direction);
int ubicationpath(const char *direction);
char *_getenv(char *direction);
void free_mem_string(char **args);
void free_mem(char *str);
int compare(char *str1, char *str2);
void env(char *str);
void invalid_command(char **args);


#endif
