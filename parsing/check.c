#include "../includes/cub3d.h"
#include "parser.h"

void	ft_error(char *str)
{
	if (str)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putendl_fd(str, 2);
	}
	else
		perror(NULL);
	exit(1);
}

int	check_file(int argc, char *file)
{
	int	fd;

	fd = -1;
	if (argc != 2)
		ft_error("use './cub maps/map.cub'");
	if (ft_strcmp(file + ft_strlen(file) - 4, ".cub"))
		ft_error("use map with '.cub'");
	fd = open(file, O_RDONLY);
	printf("%s\t%d\n", file, fd);
	if (fd < 0 || read(fd, NULL, 0) < 0)
	{
		ft_error(NULL);
		close(fd);
	}
	return (fd);
}



