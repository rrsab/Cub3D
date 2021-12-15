#include "../../includes/cub3d.h"

static void	turn_right(t_m *data)
{
	float	prev_dir_x;
	float	prev_plane_x;

	data->plr->angle += ROTATION_STEP;
	prev_dir_x = data->plr->dir_x;
	prev_plane_x = data->plr->plane_x;
	data->plr->dir_x = data->plr->dir_x * cos(ROTATION_STEP)
		- data->plr->dir_y * sin(ROTATION_STEP);
	data->plr->dir_y = prev_dir_x * sin(ROTATION_STEP)
		+ data->plr->dir_y * cos(ROTATION_STEP);
	data->plr->plane_x = data->plr->plane_x * cos(ROTATION_STEP)
		- data->plr->plane_y * sin(ROTATION_STEP);
	data->plr->plane_y = prev_plane_x * sin(ROTATION_STEP)
		+ data->plr->plane_y * cos(ROTATION_STEP);
}

static void	turn_left(t_m *data)
{
	float	prev_dir_x;
	float	prev_plane_x;

	prev_dir_x = data->plr->dir_x;
	prev_plane_x = data->plr->plane_x;
	data->plr->angle -= ROTATION_STEP;
	data->plr->dir_x = data->plr->dir_x * cos(-ROTATION_STEP)
		- data->plr->dir_y * sin(-ROTATION_STEP);
	data->plr->dir_y = prev_dir_x * sin(-ROTATION_STEP)
		+ data->plr->dir_y * cos(-ROTATION_STEP);
	data->plr->plane_x = data->plr->plane_x * cos(-ROTATION_STEP)
		- data->plr->plane_y * sin(-ROTATION_STEP);
	data->plr->plane_y = prev_plane_x * sin(-ROTATION_STEP)
		+ data->plr->plane_y * cos(-ROTATION_STEP);
}

void	cb_handle_arrows(int key, t_m *data)
{
	if (key == ARROW_LEFT)
	{
		turn_left(data);
		cb_rendering(data);
	}
	if (key == ARROW_RIGHT)
	{
		turn_right(data);
		cb_rendering(data);
	}
}

void	cb_handle_ws_keys(int key, t_m *data)
{
	if (key == MAIN_PAD_W)
	{
		if (data->map->map[(int)data->plr->y]
			[(int)(data->plr->x + data->plr->dir_x * STEP)] != '1')
			data->plr->x += data->plr->dir_x * STEP;
		if (data->map->map[(int)(data->plr->y + data->plr->dir_y * STEP)]
			[(int)data->plr->x] != '1')
			data->plr->y += data->plr->dir_y * STEP;
		cb_rendering(data);
	}
	if (key == MAIN_PAD_S)
	{
		if (data->map->map[(int)data->plr->y]
			[(int)(data->plr->x - data->plr->dir_x * STEP)] != '1')
			data->plr->x -= data->plr->dir_x * STEP;
		if (data->map->map[(int)(data->plr->y - data->plr->dir_y * STEP)]
			[(int)data->plr->x] != '1')
			data->plr->y -= data->plr->dir_y * STEP;
		cb_rendering(data);
	}
}

void	cb_handle_ad_keys(int key, t_m *data)
{
	if (key == MAIN_PAD_A)
	{
		if (data->map->map[(int)data->plr->y]
			[(int)(data->plr->x + data->plr->dir_y * STEP)] != '1')
			data->plr->x += data->plr->dir_y * STEP;
		if (data->map->map[(int)(data->plr->y - data->plr->dir_x * STEP)]
			[(int)data->plr->x] != '1')
			data->plr->y -= data->plr->dir_x * STEP;
		cb_rendering(data);
	}
	if (key == MAIN_PAD_D)
	{
		if (data->map->map[(int)data->plr->y]
			[(int)(data->plr->x - data->plr->dir_y * STEP)] != '1')
			data->plr->x -= data->plr->dir_y * STEP;
		if (data->map->map[(int)(data->plr->y + data->plr->dir_x * STEP)]
			[(int)data->plr->x] != '1')
			data->plr->y += data->plr->dir_x * STEP;
		cb_rendering(data);
	}
}
