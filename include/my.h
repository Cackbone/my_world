/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

void my_memset(char *, char, int);
char *my_strdup(char *);
int my_isnum(char);
int my_str_isnum(char *);
int my_strcmp(char *, char *);
int my_strncmp(char *, char *, int);
char *my_concat(char *, char *);
int get_array_size(char **);
char *get_env(char **, char *);
void my_puterr(char *);
int my_put_nbr(int, int);
void my_free_array(char **);
int my_getnbr(char *);
int my_strlen(char *);
char *my_strncpy(char *, char *, int);
char *my_substring(char *, int, int);
int start_by(char *, char *);
int count_noregex(char *, char *);
char **my_strsplit(char *, char *);
char *my_strcat(char *, char *);

#endif
