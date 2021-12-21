#include "cub3d.h"

void	ft_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*addr;

	addr = win->addr + y * win->line_length + x * (win->bpp / 8);
	color = *(unsigned int *)addr;
}

void	rendering_floor_and_ceiling(t_main *data)
{
	int	i;
	int j;

	i = -1;
	while (++i < data->win->win_height / 2)
	{
		j = -1;
		while (++j < data->win->win_width)
			ft_mlx_pixel_put(data->win, j, i, data->map->ceiling);
	}
	i = data->win->win_height / 2 - 1;
	while (++i < data->win->win_height)
	{
		j = -1;
		while (++j < data->win, j, i, data->win->win_width)
			ft_mlx_pixel_put(data->win, j, i, data->map->floor);
	}
}

void	calcualate_ray_param(t_main *data, int x_line)
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

void	check_hit_wall(t_main *data)
{
	data->lodev->flag_hit = 0;
	while (data->lodev->flag_hit == 0)
	{
		if (data->lodev->side_dist_x < data->lodev->side_dist_y)
		{
			data->lodev->side_dist_x += data->lodev->delta_dist_x;
			data->lodev->map_x += data->lodev->step_x;
			data->lodev->side = 'V';
		}
		else
		{
			data->lodev->side_dist_y += data->lodev->delta_dist_y;
			data->lodev->map_y += data->lodev->step_y;
			data->lodev->side = 'H';
		}
		if (data->map->map[data->lodev->map_y][data->lodev->map_x] == '1')
			data->lodev->flag_hit = 1;
	}
	if (data->lodev->side == 'V')
		data->lodev->perp_wall_dist = data->lodev->side_dist_x \
								- data->lodev->delta_dist_x;
	else
		data->lodev->perp_wall_dist = data->lodev->side_dist_x \
								- data->lodev->delta_dist_x;
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

void	rendering_environment(t_main *data)
{
	int	x;

	x = 0;
	while (x < data->win->win_width)
	{
		calculate_ray_param(data, x);
		calculate_distance(data);
		check_hit_wall(data);
		data->lodev->line_height = (int)(data->win->win_height \
								/ data->lodev->perp_wall_dist);
		calculate_extreme_pixels(data);
		calculate_wall_x(data);
	}
}

void	rendering(t_main *data)
{
	rendering_floor_and_ceiling(data);
	rendering_environment(data);

}

