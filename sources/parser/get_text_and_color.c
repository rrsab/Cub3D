#include "cub3d.h"

static int	create_trgb(int transparency, int red, int green, int blue)
{
	return (transparency << 24 | red << 16 | green << 8 | blue);
}

static int	get_color(char *str)
{
	int		i;
	int		color[3];
	char	*rgb;
	char	**array;

	if (count_of_symbols(str, ',') != 2)
		ft_error("not valid color\n");
	rgb = ft_strtrim(str, " ");
	array = ft_split(rgb, ',');
	i = -1;
	while (++i < 3)
	{
		if (!str_isdigit(array[i]))
			ft_error("not valid color code\n");
		color[i] = ft_atoi(array[i]);
	}
	ft_free_array(array);
	free(rgb);
	return (create_trgb(0, color[0], color[1], color[2]));
}

static char	*get_texture(char *str)
{
	return (ft_strtrim(str, " "));
}

void	get_text_and_color(char *str, t_map *map)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (!ft_strncmp(str, "F ", 2) && map->floor == -1)
		map->floor = get_color(str + 2);
	else if (!ft_strncmp(str, "C ", 2) && map->ceiling == -1)
		map->ceiling = get_color(str + 2);
	else if (!ft_strncmp(str, "NO ", 3) && !map->xpm[0])
		map->xpm[0] = get_texture(str + 3);
	else if (!ft_strncmp(str, "SO ", 3) && !map->xpm[1])
		map->xpm[1] = get_texture(str + 3);
	else if (!ft_strncmp(str, "WE ", 3) && !map->xpm[2])
		map->xpm[2] = get_texture(str + 3);
	else if (!ft_strncmp(str, "EA ", 3) && !map->xpm[3])
		map->xpm[3] = get_texture(str + 3);
	else
		ft_error("invalid param\n");
	map->param_match = (map->floor >= 0 && map->ceiling >= 0 && map->xpm[0]
						&& map->xpm[1] && map->xpm[2] && map->xpm[3]);
}
