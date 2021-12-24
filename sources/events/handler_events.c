#include "cub3d.h"

//void	handler_arrows_keys(int key, t_main *data)
//{
//
//}

void	handler_ad_keys(int key, t_player *player, char **map)
{
	if (key == MAIN_PAD_A)
	{
		if (map[(int)player->y][(int)(player->x + player->dir_y * STEP)] != '1')
			player->x += player->dir_y * STEP;
		if (map[(int)(player->y - player->dir_x * STEP)][(int)player->x] != '1')
			player->y -= player->dir_x * STEP;
	}
	else if (key == MAIN_PAD_D)
	{
		if (map[(int)player->y][(int)(player->x - player->dir_y * STEP)] != '1')
			player->x -= player->dir_y * STEP;
		if (map[(int)(player->y + player->dir_x * STEP)][(int)player->x] != '1')
			player->y += player->dir_x * STEP;
	}
}

void	handler_ws_keys(int key, t_player *player, char **map)
{
	if (key == MAIN_PAD_W)
	{
		if (map[(int)player->y][(int)(player->x + player->dir_x * STEP)] != '1')
			player->x += player->dir_x * STEP;
		if (map[(int)(player->y + player->dir_y * STEP)][(int)player->x] != '1')
			player->y += player->dir_y * STEP;
	}
	else if (key == MAIN_PAD_S)
	{
		if (map[(int)player->y][(int)(player->x - player->dir_x * STEP)] != '1')
			player->x -= player->dir_x * STEP;
		if (map[(int)(player->y - player->dir_y * STEP)][(int)player->x] != '1')
			player->y -= player->dir_y * STEP;
	}
}

static int	exit_cub3D(t_main *data)
{
	mlx_destroy_window(data->win->mlx_ptr, data->win->win_ptr);
	exit(0);
}

int	handler_keyboard(int key, t_main *data)
{
	if (key == MAIN_PAD_ESC)
		exit_cub3D(data);
	else if (key == MAIN_PAD_W || key == MAIN_PAD_S)
		handler_ws_keys(key, data->player, data->map->map);
	else if (key == MAIN_PAD_A || key == MAIN_PAD_D)
		handler_ad_keys(key, data->player, data->map->map);
//	else if (key == ARROW_RIGHT || key == ARROW_LEFT)
//		hanler_arrows_keys(key, data->player, data->map->map);
	rendering(data);
	return (0);
}

void	handler_events(t_main *data)
{
	mlx_hook(data->win->win_ptr, 2, 0, handler_keyboard, data);
	mlx_hook(data->win->win_ptr, 17, 0, exit_cub3D, data);
}
