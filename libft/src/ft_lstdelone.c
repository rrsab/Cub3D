#include "../inc/libft.h"

void	ft_lstdelone(t_list *list)
{
	if (list->val)
		free(list->val);
	if (list)
		free(list);
	list = NULL;
}
