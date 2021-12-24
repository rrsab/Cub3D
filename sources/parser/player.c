#include "cub3d.h"

void 	init_player(t_main *data)
{
	data->player->x = 0.0F;
	data->player->y = 0.0F;
	data->player->plane_x = 0.0F;
	data->player->plane_y = 0.0F;
	data->player->dir_x = 0.0F;
	data->player->dir_y = 0.0F;
	data->player->angle = 0.0F;
}

float	ft_degree_to_ratio(float degree)
{
	return (degree * acos(-1.0) / 180);
}

static void	set_begin_angle(t_player *player, char c)
{
	if (c == 'N')
		player->angle = ft_degree_to_ratio(270);
	else if (c == 'S')
		player->angle = ft_degree_to_ratio(90);
	else if (c == 'W')
		player->angle = ft_degree_to_ratio(180);
	else if (c == 'E')
		player->angle = ft_degree_to_ratio(0);
}

static void	set_player_POV(t_player *player, char c)
{
	if (c == 'N')
	{
		player->dir_y = -1.0;
		player->plane_x = -0.66;
	}
	else if (c == 'S')
	{
		player->dir_y = 1.0;
		player->plane_x = 0.66;
	}
	else if (c == 'W')
	{
		player->dir_x = -1.0;
		player->plane_y = 0.66;
	}
	else if (c == 'E')
	{
		player->dir_x = 1.0;
		player->plane_y = -0.66;
	}
	set_begin_angle(player, c);
}

void	find_player(t_player *player, t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S'
				|| map->map[y][x] == 'W' || map->map[y][x] == 'E')
			{
				player->y = (float)y + 0.1f;
				player->x = (float)x + 0.1f;
				set_player_POV(player, map->map[y][x]);
				return ;
			}
		}
	}
}
