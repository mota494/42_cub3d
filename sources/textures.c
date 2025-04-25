/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:25:14 by mloureir          #+#    #+#             */
/*   Updated: 2025/04/25 22:25:42 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_path(char *buffer)
{
	if (buffer + 3)
		return (ft_strdup(buffer + 3));
	else
		return (ft_strdup("\0"));
}

void	find_texture(char *buffer, t_textures *t_txt)
{
	if (ft_strnstr(buffer, "NO", ft_strlen(buffer)))
	{
		t_txt[0].identifier = ft_strdup("NO");
		t_txt[0].path = get_path(buffer);
	}
	else if (ft_strnstr(buffer, "EA", ft_strlen(buffer)))
	{
		t_txt[1].identifier = ft_strdup("EA");
		t_txt[1].path = get_path(buffer);
	}
	else if (ft_strnstr(buffer, "WE", ft_strlen(buffer)))
	{
		t_txt[2].identifier = ft_strdup("WE");
		t_txt[2].path = get_path(buffer);
	}
	else if (ft_strnstr(buffer, "SO", ft_strlen(buffer)))
	{
		t_txt[3].identifier = ft_strdup("SO");
		t_txt[3].path = get_path(buffer);
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
