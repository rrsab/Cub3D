#include "../../includes/cub3d.h"

int	ft_save(int fd, char **line, char **str)
{
	char	*tmp;
	size_t	i;

	tmp = NULL;
	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != 0)
		i++;
	if (str[fd][i] == '\n')
	{
		tmp = ft_strdup(str[fd] + i + 1);
		if (!tmp)
			return (-1);
	}
	*line = ft_substr(str[fd], 0, i);
	if (!*line)
		return (-1);
	free(str[fd]);
	str[fd] = tmp;
	if (tmp)
		return (1);
	return (0);
}

int	ft_check(int fd, int rb, char **line, char **str)
{
	if (rb < 0)
		return (-1);
	if (rb == 0 && str[fd] == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_save(fd, line, str));
}

int	ft_read_buf(int fd, char **line, char *buf, char **str)
{
	char		*tmp;
	int			rb;

	rb = read(fd, buf, BUFFER_SIZE);
	while (rb > 0)
	{
		buf[rb] = '\0';
		if (!str[fd])
			str[fd] = (ft_strdup(""));
		tmp = str[fd];
		str[fd] = ft_strjoin(str[fd], buf);
		if (!str[fd])
			return (-1);
		free(tmp);
		if (ft_strchr(str[fd], '\n'))
			break ;
		rb = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (ft_check(fd, rb, line, str));
}

int	get_next_line(int fd, char **line)
{
	static char	*arr[8192];
	char		*buf;

	if (!line || BUFFER_SIZE < 1 || fd < 0 || fd > 8192)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	return (ft_read_buf(fd, line, buf, arr));
}
