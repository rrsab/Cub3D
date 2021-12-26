#include "cub3d.h"

void	init_map(t_map *map)
{
	int	i;

	map->param_match = false;
	map->map_match = false;
	map->map = NULL;
	map->floor = -1;
	map->ceiling = -1;
	map->width = 0;
	map->height = 0;
	map->map_list = NULL;
	map->xpm = malloc(sizeof(char *) * 4);
	if (!map->xpm)
		ft_error(NULL);
	i = -1;
	while (++i < 4)
		map->xpm[i] = NULL;
}

static void	get_size_of_map(t_map **map, t_list *map_list)
{
	int	max;

	max = 0;
	while (map_list)
	{
		(*map)->height++;
		(*map)->width = ft_strlen(map_list->val);
		if ((*map)->width > max)
			max = (*map)->width;
		map_list = map_list->next;
	}
	(*map)->width = max;
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

static void	fill_map(t_map *map, t_list **map_list)
{
	int		y;
	t_list	*list;

	map->width += 2;
	map->height += 2;
	map->map = ft_malloc_x(sizeof(char *) * map->height);
	y = 0;
	list = *map_list;
	while (y < map->height)
	{
		map->map[y] = ft_malloc_x(sizeof(char) * map->width);
		if (y > 0 && y < map->height - 1)
		{
			ft_strlcpy(map->map[y] + 1, list->val, map->width - 1);
			list = list->next;
		}
		y++;
	}
	ft_lstclear(map_list);
	check_map(map);
	trimming_map(map);
}

void	map_creation(t_map *map)
{
	check_map_symbols(map->map_list);
	get_size_of_map(&map, map->map_list);
	fill_map(map, &map->map_list);
}
