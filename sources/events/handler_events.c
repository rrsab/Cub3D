#include "cub3d.h"

int	mouse_move(int x, int y, t_main *data)
{
	t_player	*plr;
	float		angle;
	float		prev_dir_x;
	float		prev_plane_x;
	int			dir;

	plr = data->player;
	prev_dir_x = plr->dir_x;
	prev_plane_x = plr->plane_x;
	dir = 1;
	if (plr->mouse_x > x || x < 0)
		dir = -1;
	angle = ANGLE / 4;
	plr->angle += dir * angle;
	plr->dir_x = plr->dir_x * cos(angle) - plr->dir_y * sin(dir * angle);
	plr->dir_y = prev_dir_x * sin(dir * angle) + plr->dir_y * cos(angle);
	plr->plane_x = plr->plane_x * cos(angle) - plr->plane_y * sin(dir * angle);
	plr->plane_y = prev_plane_x * sin(dir * angle) + plr->plane_y * cos(angle);
	data->player->mouse_x = x;
	data->player->mouse_y = y;
	rendering(data);
	return (0);
}

int	mouse_release(int key, int x, int y, t_main *data)
{
	(void)x;
	(void)y;
	(void)key;
	data->player->left_button = 0;
	return (0);
}

int	mouse_key(int key, int x, int y, t_main *data)
{
	(void)x;
	(void)y;
	if (key == 1)
		data->player->left_button = 1;
	return (0);
}

void	handler_events(t_main *data)
{
	mlx_hook(data->win->win_ptr, 2, 0, handler_keyboard, data);
	mlx_hook(data->win->win_ptr, 4, 0, mouse_key, data);
	mlx_hook(data->win->win_ptr, 5, 0, mouse_release, data);
	mlx_hook(data->win->win_ptr, 6, 0, mouse_move, data);
	mlx_hook(data->win->win_ptr, 17, 0, exit_cub3d, data);
}
