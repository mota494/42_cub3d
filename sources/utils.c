/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:19:32 by mloureir          #+#    #+#             */
/*   Updated: 2025/04/30 15:34:44 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_counters(t_counters *counters)
{
	counters->no = 0;
	counters->ea = 0;
	counters->so = 0;
	counters->we = 0;
	counters->c = 0;
	counters->f = 0;
}

char	*rm_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	str[i] = '\0';
	return (str);
}
