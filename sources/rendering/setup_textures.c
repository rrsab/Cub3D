#include "cub3d.h"

static void	setup_texture(t_main *data, t_texture *texture, char *file)
{
	int	i;
	int	j;
	int	width_texture;
	int	height_texture;

	texture->img = mlx_xpm_file_to_image(data->win->mlx_ptr, file,
			&width_texture, &height_texture);
	if (!texture->img)
		ft_error("xpm file not read\n");
	if (height_texture != 64 || width_texture != 64)
		ft_error("wrong texture size\n");
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->size_line, &texture->endian);
	texture->matrix = ft_malloc_x(sizeof(int *) * width_texture);
	i = -1;
	while (++i < width_texture)
	{
		j = -1;
		texture->matrix[i] = ft_malloc_x(sizeof(int) * height_texture);
		while (++j < height_texture)
			texture->matrix[i][j] = setup_color_texture(texture, i, j);
	}
}

void	get_textures(t_main *data)
{
	data->textures->north = ft_malloc_x(sizeof(t_texture));
	data->textures->south = ft_malloc_x(sizeof(t_texture));
	data->textures->west = ft_malloc_x(sizeof(t_texture));
	data->textures->east = ft_malloc_x(sizeof(t_texture));
	setup_texture(data, data->textures->north, data->map->xpm[0]);
	setup_texture(data, data->textures->south, data->map->xpm[1]);
	setup_texture(data, data->textures->west, data->map->xpm[2]);
	setup_texture(data, data->textures->east, data->map->xpm[3]);
}
