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
