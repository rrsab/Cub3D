#include "cub3d.h"

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
	return (count);
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

float	ft_degree_to_ratio(float degree)
{
	return (degree * acos(-1.0) / 180);
}

void	ft_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*addr;

	addr = win->addr + y * win->line_length + x * (win->bpp / 8);
	*(unsigned int *)addr = color;
}

unsigned int	setup_color_texture(t_texture *img, int i, int j)
{
	unsigned int	color;
	char			*addr;

	addr = img->addr + (j * img->size_line + i * (img->bpp / 8));
	color = *(unsigned int *)addr;
	return (color);
}
