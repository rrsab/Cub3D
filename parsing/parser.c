#include "../includes/cub3d.h"
#include "parser.h"

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

void	parsing(int argc, char *file, t_main *data)
{
	int	fd;

	fd = check_file(argc, file);
	init_map(data->map);
	init_player(data);
	parsing_param(fd, data->map);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_main	data;
	parsing(argc, argv[1], &data);
	return (0);
}


