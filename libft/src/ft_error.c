#include "../inc/libft.h"

void	ft_error(char *str)
{
	if (str)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putendl_fd(str, 2);
	}
	else
		perror(NULL);
	exit(1);
}
