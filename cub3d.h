/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:37:02 by mloureir          #+#    #+#             */
/*   Updated: 2025/04/30 15:40:25 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MAX_TEXTURE 4
# define COLOR 2

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/time.h>
# include "includes/libft/libft.h"

typedef struct s_textures
{
	char	*identifier;
	char	*path;
	int		count;
}	t_textures;

typedef struct s_colors
{
	char	identifier;
	char	*path;
	int		red;
	int		green;
	int		blue;
}	t_colors;

typedef struct s_counters
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_counters;

typedef struct s_map
{
	char		**map;
	t_colors	color[COLOR];
	t_textures	texture[MAX_TEXTURE];
}	t_map;

/* parser */

int		parser(t_map *map, char *map_dir);

/* parser - textures */

char	*get_path(char *buffer);
void	find_texture(char *buffer, t_textures *t_txt);
int		get_texture(t_textures *textures, char *map_dir);

/* parser - checker */

int		check_dotfile(char *map_dir);
int		analiser(char *buffer, t_counters *count);
int		check_content(char *map_dir);
int		check_errs(char *map_dir);

/* parser - value check */

int		check_values(char *map_dir);

/* utils */

void	start_counters(t_counters *counters);
char	*rm_nl(char *str);

#endif
