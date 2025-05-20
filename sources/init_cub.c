/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:10:02 by fde-jesu          #+#    #+#             */
/*   Updated: 2025/05/20 15:20:24 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_keys(t_cub *cub)
{
	cub->k_up = false;
	cub->k_down = false;
	cub->k_left = false;
	cub->k_right = false;
	cub->k_plus = false;
	cub->k_less = false;
	cub->left_r = false;
	cub->right_r = false;
}

void	set_player_atributes(t_cub *cub)
{
	cub->px = WIDTH / 2;
	cub->py = HEIGH / 2;
	cub->angle = PI / 2;
	cub->speed = 1.3;
}

void	init_cub(t_cub *cub)
{
	set_null(cub);
	init_keys(cub);
	cub->rays = (t_rays *)malloc(sizeof(t_rays));
	set_player_atributes(cub);
	start_cub(cub);
}
