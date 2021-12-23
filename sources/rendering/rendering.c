#include "cub3d.h"

void	ft_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*addr;

	addr = win->addr + y * win->line_length + x * (win->bpp / 8);
	*(unsigned int *)addr = color;
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
		while (++j < data->win->win_width)
			ft_mlx_pixel_put(data->win, j, i, data->map->floor);
	}
}

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
	if (data->lodev->side == 'H')
		data->lodev->perp_wall_dist = data->lodev->side_dist_y \
								- data->lodev->delta_dist_y;
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

void	draw_line(t_main *data, t_lodev *lodev, int x)
{
	int tex_y;
	int color;

	while (lodev->draw_start <= lodev->draw_end)
	{
		tex_y = (int)lodev->tex_pos & (64 -1);
		lodev->tex_pos += lodev->step;
		if (lodev->side == 'H')
		{
			if (lodev->step_y == -1)
				color = data->textures->west->matrix[lodev->tex_x][tex_y];
			else
				color = data->textures->east->matrix[lodev->tex_x][tex_y];
		}
		else
		{
			if (lodev->step_x == -1)
				color = data->textures->north->matrix[lodev->tex_x][tex_y];
			else
				color = data->textures->south->matrix[lodev->tex_x][tex_y];
		}
		ft_mlx_pixel_put(data->win, x, lodev->draw_start, color);
		data->lodev->draw_start++;
	}
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
		data->lodev->tex_x = (int)(data->lodev->wall_x * (double)(64));
		if (data->lodev->side == 0 && data->lodev->ray_dir_x > 0)
			data->lodev->tex_x = 64 - data->lodev->tex_x - 1;
		if (data->lodev->side == 1 && data->lodev->ray_dir_y < 0)
			data->lodev->tex_x = 64 - data->lodev->tex_x - 1;
		data->lodev->step = 1.0 * 64 / data->lodev->line_height;
		data->lodev->tex_pos = (data->lodev->draw_start - data->win->win_height \
					/ 2  + data->lodev->line_height / 2) * data->lodev->step;
		draw_line(data, data->lodev, x);
		x++;
	}
}
