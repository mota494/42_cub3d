/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:49:45 by mloureir          #+#    #+#             */
/*   Updated: 2025/04/30 15:58:28 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_c_path(char *buffer)
{
	int		i;
	char	*toret;

	i = 1;
	while (buffer[i] == 32 || (buffer[i] >= 9 && buffer[i] <= 13))
		i++;
	toret = ft_strdup(buffer + i);
	return (rm_nl(toret));
}

void	find_color(char *buffer, t_colors *colors)
{
	if (ft_strnstr(buffer, "F", 1))
	{
		colors[0].identifier = 'F';
		colors[0].path = get_c_path(buffer);
	}
	else if (ft_strnstr(buffer, "C", 1))
	{
		colors[1].identifier = 'C';
		colors[1].path = get_c_path(buffer);
	}
}

int	get_color(t_colors *colors, char *map_dir)
{
	int		fd;
	char	*buffer;

	fd = open(map_dir, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		find_color(buffer, colors);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	free(buffer);
	return (0);
}

int	parser(t_map *map, char *map_dir)
{
	if (check_errs(map_dir) != 0)
		return (1);
	if (get_texture(map->texture, map_dir) != 0)
		return (1);
	if (get_color(map->color, map_dir) != 0)
		return (1);
	return (0);
}
