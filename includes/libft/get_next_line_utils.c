/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:25:28 by mloureir          #+#    #+#             */
/*   Updated: 2025/04/24 12:25:56 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hasnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*alocpy(char *str)
{
	char	*toret;
	int		i;

	i = 0;
	toret = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		toret[i] = str[i];
		i++;
	}
	toret[i] = '\0';
	return (toret);
}

char	*strjoinchr(char *oldtoret, char car)
{
	char	*newtoret;
	int		i;

	i = 0;
	newtoret = malloc(ft_strlen(oldtoret) + 2);
	while (oldtoret[i])
	{
		newtoret[i] = oldtoret[i];
		i++;
	}
	newtoret[i] = car;
	newtoret[i + 1] = '\0';
	free(oldtoret);
	return (newtoret);
}
