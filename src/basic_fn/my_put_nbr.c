/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** my_put_nbr
*/

#include <my.h>
#include <macros.h>
#include <unistd.h>

int my_put_nbrchar(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

int my_put_nbr(int fd, int nbr)
{
	int mod = ABS(nbr % 10);
	int div = nbr / 10;
	int len = 0;

	if (nbr < 0) {
		div *= -1;
		len += my_put_nbrchar(fd, '-');
	}
	if (div > 0)
		len += my_put_nbr(fd, div);
	len += my_put_nbrchar(fd, mod + '0');
	return (len);
}
