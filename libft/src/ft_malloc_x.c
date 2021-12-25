#include "../inc/libft.h"

void	*ft_malloc_x(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_error(NULL);
	return (ptr);
}
