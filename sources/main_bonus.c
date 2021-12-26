#include "cub3d.h"

void	rendering(t_main *data)
{
	rendering_floor_and_ceiling(data);
	rendering_environment(data);
	rendering_minimap(data);
	mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr, \
							data->win->img_ptr, 0, 0);
}

int	main(int argc, char **argv)
{
	t_main		data;
	t_map		map;
	t_player	player;
	t_win		win;
	t_lodev		lodev;

	data.map = &map;
	data.player = &player;
	data.win = &win;
	data.lodev = &lodev;
	parsing(argc, argv[1], &data);
	init_main_struct(&data);
	rendering(&data);
	handler_events(&data);
	mlx_loop(data.win->mlx_ptr);
}

void	init_mlx(t_win *win)
{
	win->win_width = WIN_WIDTH;
	win->win_height = WIN_HEIGHT;
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
	{
		ft_putendl_fd(strerror(errno), 2);
		exit(1);
	}
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!win->win_ptr)
	{
		ft_putendl_fd(strerror(errno), 2);
		exit(1);
	}
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	win->addr = mlx_get_data_addr(win->img_ptr, &win->bpp, &win->line_length,
			&win->endian);
}

void	init_lodev_struct(t_lodev *lodev)
{
	lodev->step_x = 0;
	lodev->step_y = 0;
	lodev->camera_x = 0;
	lodev->ray_dir_x = 0;
	lodev->ray_dir_y = 0;
	lodev->map_x = 0;
	lodev->map_y = 0;
	lodev->side_dist_x = 0;
	lodev->side_dist_y = 0;
	lodev->delta_dist_x = 0;
	lodev->delta_dist_y = 0;
	lodev->perp_wall_dist = 0;
	lodev->flag_hit = 0;
	lodev->side = '0';
}

void	init_main_struct(t_main *data)
{
	data->zoom = 8;
	init_mlx(data->win);
	data->textures = ft_malloc_x(sizeof(t_textures));
	init_lodev_struct(data->lodev);
	get_textures(data);
}
