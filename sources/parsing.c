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
	if (seperate_colors(colors) != 0)
		return (1);
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
