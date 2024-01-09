#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

char **accept_input(void);
int arr_size(char *string, char *delim);
void disp_prmpt(void);
void ex_logic(char *av);
void _env(void);
char **dirs_in_path(void);
char **str_to_arr(char *string, char *delim);
char *find_in_path(char *file_name);

char *_strcat(char *dst, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dst, char *src);
char *_strdup(char *s);
int _strlen(char *s);
void print(char *s);


#endif /* MAIN_H */
