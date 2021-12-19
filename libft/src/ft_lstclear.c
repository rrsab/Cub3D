#include "../inc/libft.h"

void	ft_lstclear(t_list **list)
{
	t_list	*tmp;

	if (list)
	{
		while (*list)
		{
			tmp = (*list)->next;
			ft_lstdelone(*list);
			*list = tmp;
		}
	}
}
