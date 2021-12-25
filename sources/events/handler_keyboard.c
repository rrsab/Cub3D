#include "cub3d.h"

static void	handler_arrows_keys(int key, t_player *plr)
{
	float	prev_dir_x;
	float	prev_plane_x;
	int		dir;

	dir = 1;
	if (key == ARROW_LEFT)
		dir = -1;
	plr->angle += dir * ANGLE;
	prev_dir_x = plr->dir_x;
	prev_plane_x = plr->plane_x;
	plr->dir_x = plr->dir_x * cos(ANGLE) - plr->dir_y * sin(dir * ANGLE);
	plr->dir_y = prev_dir_x * sin(dir * ANGLE) + plr->dir_y * cos(ANGLE);
	plr->plane_x = plr->plane_x * cos(ANGLE) - plr->plane_y * sin(dir * ANGLE);
	plr->plane_y = prev_plane_x * sin(dir * ANGLE) + plr->plane_y * cos(ANGLE);
}

static void	handler_ad_keys(int key, t_player *player, char **map)
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

static void	handler_ws_keys(int key, t_player *player, char **map)
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

int	exit_cub3d(t_main *data)
{
	mlx_destroy_window(data->win->mlx_ptr, data->win->win_ptr);
	exit(0);
}

int	handler_keyboard(int key, t_main *data)
{
	if (key == MAIN_PAD_ESC)
		exit_cub3d(data);
	else if (key == MAIN_PAD_W || key == MAIN_PAD_S)
		handler_ws_keys(key, data->player, data->map->map);
	else if (key == MAIN_PAD_A || key == MAIN_PAD_D)
		handler_ad_keys(key, data->player, data->map->map);
	else if (key == ARROW_RIGHT || key == ARROW_LEFT)
		handler_arrows_keys(key, data->player);
	rendering(data);
	return (0);
}
