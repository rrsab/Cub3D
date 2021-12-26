#include "cub3d.h"

static void	parsing_param(int fd, t_map *map)
{
	int		res;
	char	*line;

	res = 1;
	line = NULL;
	while (res)
	{
		res = get_next_line(fd, &line);
		if (res < 0)
			ft_error(NULL);
		if (!ft_strlen(line) && map->map_list && !map->map_match)
			map->map_match = true;
		if (ft_strlen(line))
		{
			if (map->map_match)
				ft_error("invalid map\n");
			if (map->param_match)
				ft_lstadd_back(&map->map_list, ft_lstnew(ft_strdup(line)));
			else
				get_text_and_color(line, map);
		}
		free(line);
	}
}

static void	trimming_map(t_map *map)
{
	int		y;
	int		i;
	char	**map_trim;

	map->width -= 2;
	map->height -= 2;
	y = -1;
	i = 0;
	map_trim = ft_malloc_x(sizeof(char *) * (map->height + 1));
	while (++y < map->height + 2)
	{
		if (y != 0 && y != (map->height + 1))
			map_trim[i++] = ft_strdup(map->map[y] + 1);
		free(map->map[y]);
	}
	map_trim[i] = NULL;
	free(map->map);
	map->map = map_trim;
}

void	parsing(int argc, char *file, t_main *data)
{
	int	fd;

	fd = check_file(argc, file);
	init_map(data->map);
	init_player(data);
	parsing_param(fd, data->map);
	close(fd);
	map_creation(data->map);
	check_map(data->map);
	trimming_map(data->map);
	if (!data->map->param_match)
		ft_error("map is not valid\n");
	find_player(data->player, data->map);
}
