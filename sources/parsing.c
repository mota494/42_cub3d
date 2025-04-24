/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:49:45 by mloureir          #+#    #+#             */
/*   Updated: 2025/04/24 18:12:42 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_texture(char *buffer, t_textures *textures)
{
	if (ft_strnstr(buffer, "NO", ft_strlen(buffer)))
	{
		textures[0].identifier = ft_strdup("NO");
		textures[0].count += 1;
		textures[0].path = ft_strdup(buffer + 3);
	}
	else if (ft_strnstr(buffer, "EA", ft_strlen(buffer)))
	{
		textures[1].identifier = ft_strdup("EA");
		textures[1].count += 1;
		textures[1].path = ft_strdup(buffer + 3);
	}
	else if (ft_strnstr(buffer, "WE", ft_strlen(buffer)))
	{
		textures[2].identifier = ft_strdup("WE");
		textures[2].count += 1;
		textures[2].path = ft_strdup(buffer + 3);
	}
	else if (ft_strnstr(buffer, "SO", ft_strlen(buffer)))
	{
		textures[3].identifier = ft_strdup("SO");
		textures[3].count += 1;
		textures[3].path = ft_strdup(buffer + 3);
	}
}

int	get_texture(t_textures *textures, char *map_dir)
{
	int		fd;
	char	*buffer;

	fd = open(map_dir, O_RDONLY);
	buffer = get_next_line(fd);
	while (buffer)
	{
		find_texture(buffer, textures);
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	return (0);
}

int	parser(t_map *map, char *map_dir)
{
	if (get_texture(map->texture, map_dir) != 0)
		return (1);
	return (0);
}
