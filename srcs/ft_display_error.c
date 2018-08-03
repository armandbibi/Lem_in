
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "libft.h"

void ft_display_error(char **lst_error)
{
	printf("%s", *lst_error);
	lst_error++;
	lst_error = NULL;
	exit(1);
}

void	ft_add_error(char **lst_error, int error)
{
	lst_error[1] = 0;
	lst_error[2] = 0;
	lst_error[0] = ft_strdup(strerror(error));
}

char 	**ft_innit_error()
{
	char **lst_error;

	lst_error = malloc(sizeof(char *) * 3);
	if (!lst_error)
		exit(-1);
	return (lst_error);
}
