/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:14:00 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/05 12:35:35 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

typedef struct s_data {
	void 	*img;
	char 	*addr;
	int 	bbp;
	int		line_length;
	int 	endian;
}				t_data;

typedef struct	s_ptr {
	void	*mlx;
	void 	*win;
	int		win_width;
	int		win_height;
}				t_ptr;

typedef struct s_text {
	void	*ptr;
	void	*addr;
	int		width;
	int		height;
	char	*path;
	int		bbp;
	int		line_length;
	int		endian;
}			t_text;

typedef struct 	s_map {
	char	**map;
	int		pos_x;
	int		pos_y;
}				t_map;

typedef struct	s_all {
	t_ptr 	ptr;
	t_text 	text_floor;
	t_text 	text_wall;
	t_text 	text_col;
	t_text 	text_exit;
	t_text 	text_player;
	t_data 	data;
	t_map	map;
} 				t_all;

//parsing.c
char	**ft_parsing(char *path);
int		check_map(char **map, t_all *d);
int		check_collectible(char **map);

//main.c
void	ft_putchar(char *str);

//print.c
void	print_screen(t_all *d);
void	init_texture(t_all *d);

//key.c
int	ft_key(int key, t_all *d);

#endif