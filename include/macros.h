/*
** EPITECH PROJECT, 2018
** macros.h
** File description:
** macros
*/

#ifndef MACROS_H_
#define MACROS_H_

#include <my.h>

#define ABS(val)	((val < 0) ? (-val) : (val))
#define MIN(a, b)	((a < b) ? (a) : (b))
#define MAX(a, b)	((a > b) ? (a) : (b))
#define EQUALS(a, b)	(my_strcmp(a, b) == 0)

#define EOS		0
#define UNUSED		__attribute__((__unused__))

#endif
