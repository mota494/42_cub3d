/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:15:40 by mloureir          #+#    #+#             */
/*   Updated: 2025/05/13 16:29:45 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_line_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (if_space(str[i]) == 1)
			break ;
		i++;
	}
	if (i == ft_strlen(str))
		return (1);
	else
		return (0);
}
