/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:30:02 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 21:30:03 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_new_str(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_str;

	i = 0;
	nb_str = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if ((s[i] && s[i] != c))
			nb_str++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb_str);
}

static char	**ft_mem_error(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static void	ft_get_next_str(char **next_str, unsigned int *next_str_len, char c)
{
	unsigned int	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	nb_str;
	unsigned int	i;

	if (!s)
		return (NULL);
	nb_str = ft_count_new_str(s, c);
	arr = (char **)malloc(sizeof(char *) * (nb_str + 1));
	if (!arr)
		return (NULL);
	i = -1;
	next_str = (char *)s;
	next_str_len = 0;
	while (++i < nb_str)
	{
		ft_get_next_str(&next_str, &next_str_len, c);
		arr[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (!arr[i])
			return (ft_mem_error(arr));
		ft_strlcpy(arr[i], next_str, next_str_len + 1);
	}
	arr[i] = NULL;
	return (arr);
}
