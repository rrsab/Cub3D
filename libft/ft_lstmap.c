/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:27:04 by salyce            #+#    #+#             */
/*   Updated: 2021/08/01 21:27:06 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*n_elem;

	if (lst && f)
	{	
		n_elem = ft_lstnew(f(lst->content));
		result = n_elem;
		lst = lst->next;
		while (lst)
		{
			n_elem = ft_lstnew(f(lst->content));
			if (!n_elem)
			{
				ft_lstclear(&n_elem, del);
				return (0);
			}
			lst = lst->next;
			ft_lstadd_back(&result, n_elem);
		}
		return (result);
	}
	return (0);
}
