#include "../includes/cub3d.h"
#include "parser.h"

void	init_map(t_map *map)
{
//	int	i;

	map->param_match = false;
	map->map_match = false;
	map->map = NULL;
	map->floor = -1;
	map->ceiling = -1;
	map->width = 0;
	map->height = 0;
	map->map_list = NULL;
	map->xpm = ft_calloc(4, sizeof(char *));
//	map->xpm = malloc(sizeof(char *) * 4);
//	if (!map->xpm)
//		ft_error(NULL);
//	i = -1;
//	while (++i < 4)
//		map->xpm[i] = NULL;
}

