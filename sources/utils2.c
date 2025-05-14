/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:15:40 by mloureir          #+#    #+#             */
/*   Updated: 2025/05/14 10:19:36 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_line_empty(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (if_space(str[i]) == 0)
			count++;
		i++;
	}
	if (count == ft_strlen(str))
		return (1);
	else
		return (0);
}

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

void	print_debug(t_map *map)
{
	t_counters	c;

	start_counters(&c);
	while (c.c < MAX_TEXTURE)
	{
		printf("[%s]", map->texture[c.c].identifier);
		printf("[%s]\n", map->texture[c.c].path);
		c.c++;
	}
	while (c.f < COLOR)
	{
		printf("[%c]", map->color[c.f].identifier);
		printf("[%d, %d,", map->color[c.f].red, map->color[c.f].green);
		printf(" %d]\n", map->color[c.f].blue);
		c.f++;
	}
	while (c.ea < map->map_y)
	{
		printf("%s\n", map->map[c.ea]);
		c.ea++;
	}
}
