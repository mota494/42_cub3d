#include "../cub3d.h"

int	is_line_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (if_space(str[i]) == 0)
			break;
		i++;
	}
	if (i == ft_strlen(str))
		return (1);
	else
		return (0);
}

int	count_map(int fd)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (is_line_empty(buffer) == 0)
			break ;
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	buffer = get_next_line(fd);	
	while (buffer)
	{
		i++;
		if (is_line_empty(buffer) == 1)
			break ;
		free(buffer);
		buffer = get_next_line(fd);
	}
	return (i - 1);
}

int	get_map(char **map, char *map_dir)
{
	int		fd;
	char	*buffer;
	int		i;

	i = 0;
	fd = open(map_dir, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (is_a_param(buffer) != 1)
			i++;
		free(buffer);
		if (i == 6)
			break;
		buffer = get_next_line(fd);
	}
	i = count_map(fd);
	close(fd);
	if (i <= 0)
		return (1);
	return (0);
}
