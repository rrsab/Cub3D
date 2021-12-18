#include "../includes/cub3d.h"
#include "parser.h"

int	count_of_symbols(char *str, char symbol)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == symbol)
			count++;
	}
	return  (count);
}

bool	str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
