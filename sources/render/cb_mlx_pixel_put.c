#include "../../includes/cub3d.h"

void	cb_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_length + x * (win->bpp / 8));
	*(unsigned int *)dst = color;
}
