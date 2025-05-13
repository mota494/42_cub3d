/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:11:12 by mloureir          #+#    #+#             */
/*   Updated: 2025/05/13 17:01:57 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*jump_empty(int fd)
{
	char	*buffer;

	buffer = get_next_line(fd);
	while (buffer)
	{
		if (is_line_empty(buffer) == 0)
			break ;
		free(buffer);
		buffer = get_next_line(fd);
	}
	return (buffer);
}

int	paste_map(int fd, t_map *map)
{
	char	*buffer;
	int		i;

	i = 1;
	map->map = ft_calloc(map->map_y + 1, sizeof(char *));
	buffer = jump_empty(fd);
	map->map[0] = ft_strdup(buffer);
	while (buffer)
	{
		if (is_line_empty(buffer) == 1)
			break ;
		free(buffer);
		buffer = get_next_line(fd);
		if (buffer)
			map->map[i] = ft_strdup(buffer);
		i++;
	}
	return (0);
}

int	copy_map(t_map *map, char *map_dir)
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
			break ;
		buffer = get_next_line(fd);
	}
	if (paste_map(fd, map) != 0)
		return (1);
	return (0);
}
