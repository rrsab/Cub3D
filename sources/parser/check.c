#include "cub3d.h"

int	check_file(int argc, char *file)
{
	int	fd;

	if (argc != 2)
		ft_error("use './cub maps/map.cub'");
	if (ft_strcmp(file + ft_strlen(file) - 4, ".cub"))
		ft_error("use map with '.cub'");
	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) < 0)
	{
		ft_error(NULL);
		close(fd);
	}
	return (fd);
}

void	check_map_symbols(t_list *map_list)
{
	int	i;
	int	player;

	player = 0;
	while (map_list)
	{
		i = 0;
		while (map_list->val[i])
		{
			if (!ft_strchr(" 01NEWS", map_list->val[i]))
				ft_error("wrong symbol on the map\n");
			if (ft_strchr("NEWS", map_list->val[i]))
				player++;
			if (player > 1)
				ft_error("there must be only one player on the map\n");
			i++;
		}
		map_list = map_list->next;
	}
	if (player == 0)
		ft_error("there must be at least one player\n");
}

static bool	check_wall(char **map, int y, int x)
{
	return (!map[y + 1][x] || map[y + 1][x] == ' '
			|| !map[y - 1][x] || map[y - 1][x] == ' '
			|| !map[y][x + 1] || map[y][x + 1] == ' '
			|| !map[y][x - 1] || map[y][x - 1] == ' '
			|| !map[y + 1][x + 1] || map[y + 1][x + 1] == ' '
			|| !map[y + 1][x - 1] || map[y + 1][x - 1] == ' '
			|| !map[y - 1][x + 1] || map[y - 1][x + 1] == ' '
			|| !map[y - 1][x - 1] || map[y - 1][x - 1] == ' ');
}

void	check_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (++y < map->height - 1)
	{
		x = 0;
		while (++x < map->width - 1)
		{
			if (ft_strchr("0NEWS", map->map[y][x])
				&& check_wall(map->map, y, x))
				ft_error("this is the black hole on the map\n");
		}
	}
}
