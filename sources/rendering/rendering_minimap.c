#include "cub3d.h"

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

static void	draw_square(t_main *data, int start_x, int start_y, int color)
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

void	cast_rays(t_main *data, t_player *player, t_map *map)
{
	int			zoom;
	t_player	ray;
	float		start;
	float		end;

	zoom = data->zoom;
	ray = *player;
	start = player->angle - ft_degree_to_ratio(FOV) / 2;
	end = player->angle + ft_degree_to_ratio(FOV) / 2;
	while (start <= end)
	{
		ray.x = player->x * data->zoom;
		ray.y = player->y * data->zoom;
		while (map->map[(int)(ray.y / zoom)][(int)(ray.x / zoom)] != '1')
		{
			ray.x += cos(start);
			ray.y += sin(start);
			if (map->map[(int)(ray.y / zoom)][(int)(ray.x / zoom)] != '1')
				ft_mlx_pixel_put(data->win, ray.x, ray.y, RED);
		}
		start += 2 / (acos(-1.0) * data->win->win_width);
	}
}

void	rendering_minimap(t_main *data)
{
	int	zoom;

	zoom = data->zoom;
	draw_minimap(data, data->map);
	draw_player(data, zoom * data->player->x, zoom * data->player->y, TEAL);
	cast_rays(data, data->player, data->map);
}
