/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mloureir <mloureir@42porto.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:37:02 by mloureir          #+#    #+#             */
/*   Updated: 2025/05/16 14:16:33 by mloureir         ###   ########.pt       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "defines.h"

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
	char		**map_ff;
	int			map_y;
	int			map_fpos;
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

/* parser - colors */

char	*get_c_path(char *buffer);
void	find_color(char *buffer, t_colors *colors);
int		startup_check(char *str);
int		check_coloms(char *str, t_colors *colors, int i);
int		seperate_colors(t_colors *colors);

/* parser - map */

int		get_map(t_map *map, char *map_dir);
int		copy_map(t_map *map, char *map_dir);

/* parser - verify values */

int		verify_values(t_map *map);

/* utils */

void	start_counters(t_counters *counters);
char	*rm_nl(char *str);
int		ft_n_atoi(const char *nptr, int n, int s);
int		is_a_param(char *buffer);
int		if_space(int c);
int		is_line_empty(char *str);
char	*jump_empty(int fd);
void	print_debug(t_map *map);
int		map_chars(int c);
void	change_spaces(t_map *map);

#endif
