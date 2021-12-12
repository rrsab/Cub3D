/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:34:00 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 21:34:01 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin3(char const *s1, char c, char const *s2)
{
	char	*str;
	size_t	i1;
	size_t	i2;

	i1 = -1;
	i2 = -1;
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (!str)
		return (0);
	while (s1[++i1])
		str[i1] = s1[i1];
	str[i1++] = c;
	while (s2[++i2])
		str[i1 + i2] = s2[i2];
	str[i1 + i2] = '\0';
	return (str);
}
