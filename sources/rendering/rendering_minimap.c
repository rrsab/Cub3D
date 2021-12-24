#include "cub3d.h"

#ifndef COLORS_H
# define COLORS_H

# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define SILVER		0xC0C0C0
# define GRAY		0x808080
# define OLIVE		0x808000
# define YELLOW		0xFFFF00
# define JAFFA		0xEF8633
# define SAFFRON	0xF3AF3D
# define RED		0xFF0000
# define MAROON		0x800000
# define BRICK		0xC2294E
# define GREEN		0x008000
# define TEAL		0x008080
# define AQUA		0x00FFFF
# define LIME		0x00FF00
# define BLUE		0x0000FF
# define NAVY		0x000080
# define PURPLE		0x800080
# define FUCHSIA	0xFF00FF
# define DISCO		0x9A1F6A
# define FLAMINGO	0xEC4B27
# define INDIGO		0x4b0082

#endif

static void	draw_player(t_main *data, int start_x, int start_y, int color)
{
	int	x;
	int	y;

	y = start_y;
	while (y < data->zoom / 4 + start_y)
	{
		x = start_x;
		while (x < data->zoom / 4 + start_x)
		{
			ft_mlx_pixel_put(data->win, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_square(t_main * data, int start_x, int start_y, int color)
{
	int	x;
	int	y;

	y = start_y;
	while (y < data->zoom + start_y)
	{
		x = start_x;
		while (x < data->zoom + start_x)
		{
			ft_mlx_pixel_put(data->win, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_minimap(t_main *data, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width && map->map[y][x] != '\0')
		{
			if (map->map[y][x] == '1')
				draw_square(data, x * data->zoom, y * data->zoom, BLACK);
			else if (map->map[y][x] == '0' || ft_isalpha(data->map->map[y][x]))
				draw_square(data, x * data->zoom, y * data->zoom, AQUA);
			x++;
		}
		y++;
	}
}

void	rendering_minimap(t_main *data)
{
	int	zoom;

	zoom = data->zoom;
	draw_minimap(data, data->map);
	draw_player(data, zoom * data->player->x, zoom * data->player->y, TEAL);
}

