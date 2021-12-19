#include "../includes/cub3d.h"
#include "parser.h"

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

void	set_player_POV(t_player *player, char c)
{

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
			if (map->map[y][x] == 'N' || map->map[y][x] == 'N'
				|| map->map[y][x] == 'W' || map->map[y][x] == 'E')
			{
				player->y = (float)y + 0.0f;
				player->x = (float)x + 0.0f;
				set_player_POV(player, map->map[y][x]);
				return ;
			}
		}
	}
}
