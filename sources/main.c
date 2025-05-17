/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:36:09 by mloureir          #+#    #+#             */
/*   Updated: 2025/05/16 14:43:58 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_vars(t_map *info)
{
	int	i;

	i = 0;
	info->map_y = 0;
	info->map_ff_y = 0;
	while (i < MAX_TEXTURE)
	{
		info->texture[i].identifier = NULL;
		info->texture[i].count = 0;
		info->texture[i].path = NULL;
		i++;
	}
	i = 0;
	while (i < COLOR)
	{
		info->texture[i].path = NULL;
		i++;
	}
}

void	free_maps(t_map *info)
{
	int	i;

	i = 0;
	while (i <= info->map_y && info->map_y > 0)
	{
		free(info->map[i]);
		i++;
	}
	if (info->map_y > 0)
		free(info->map);
	i = 0;
	while (i <= info->map_ff_y && info->map_ff_y > 0)
	{
		free(info->map_ff[i]);
		i++;
	}
	if (info->map_ff_y > 0)
		free(info->map_ff);
}

void	free_all(t_map *info)
{
	int	i;

	i = 0;
	while (i < MAX_TEXTURE)
	{
		if (info->texture[i].identifier)
			free(info->texture[i].identifier);
		if (info->texture[i].path)
			free(info->texture[i].path);
		i++;
	}
	free_maps(info);
}

int	main(int argc, char **argv)
{
	t_map	info;

	start_vars(&info);
	if (argc != 2)
	{
		ft_putstr_fd("Error on arguments\n", STDERR_FILENO);
		return (1);
	}
	if (parser(&info, argv[1]) != 0)
	{
		ft_putstr_fd("Map error\n", STDERR_FILENO);
		free_all(&info);
		return (1);
	}
	//print_debug(&info);
	free_all(&info);
}
