/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:25:40 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 21:25:42 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*b_elem;

	if (lst)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			b_elem = ft_lstlast(*(lst));
			b_elem->next = new;
		}
	}
}
