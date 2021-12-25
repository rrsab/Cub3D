#include "cub3d.h"

void	calculate_ray_param(t_main *data, int x_line)
{
	data->lodev->camera_x = 2 * (float)x_line / data->win->win_width - 1;
	data->lodev->ray_dir_x = data->player->dir_x \
						- data->player->plane_x * data->lodev->camera_x;
	data->lodev->ray_dir_y = data->player->dir_y \
						- data->player->plane_y * data->lodev->camera_x;
	data->lodev->map_x = (int)data->player->x;
	data->lodev->map_y = (int)data->player->y;
	data->lodev->delta_dist_x = fabsf(1 / data->lodev->ray_dir_x);
	data->lodev->delta_dist_y = fabsf(1 / data->lodev->ray_dir_y);
}

void	calculate_distance(t_main *data)
{
	if (data->lodev->ray_dir_x < 0)
	{
		data->lodev->step_x = -1;
		data->lodev->side_dist_x = (data->player->x - data->lodev->map_x) \
								* data->lodev->delta_dist_x;
	}
	else
	{
		data->lodev->step_x = 1;
		data->lodev->side_dist_x = (data->lodev->map_x + 1.0 - data->player->x) \
								* data->lodev->delta_dist_x;
	}
	if (data->lodev->ray_dir_y < 0)
	{
		data->lodev->step_y = -1;
		data->lodev->side_dist_y = (data->player->y - data->lodev->map_y) \
								* data->lodev->delta_dist_y;
	}
	else
	{
		data->lodev->step_y = 1;
		data->lodev->side_dist_y = (data->lodev->map_y + 1.0 - data->player->y) \
								* data->lodev->delta_dist_y;
	}
}

void	calculate_extreme_pixels(t_main *data)
{
	t_lodev	*lodev;

	lodev = data->lodev;
	lodev->draw_start = (-lodev->line_height + data->win->win_height) / 2;
	if (lodev->draw_start < 0)
		lodev->draw_start = 0;
	lodev->draw_end = (lodev->line_height + data->win->win_height) / 2;
	if (lodev->draw_end > data->win->win_height)
		lodev->draw_end = data->win->win_height - 1;
}

void	calculate_wall_x(t_main *data)
{
	t_lodev	*lodev;

	lodev = data->lodev;
	if (lodev->side == 'V')
		lodev->wall_x = data->player->y + lodev->perp_wall_dist \
					* lodev->ray_dir_y;
	else
		lodev->wall_x = data->player->x + lodev->perp_wall_dist \
					* lodev->ray_dir_x;
	lodev->wall_x -= floor(lodev->wall_x);
}
