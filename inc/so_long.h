/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:14:00 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/09 15:13:50 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_ptr {
	void	*mlx;
	void	*win;
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

typedef struct s_map {
	char	**map;
	int		pos_x;
	int		pos_y;
}				t_map;

typedef struct s_check {
	int	e;
	int	p;
	int	c;
}				t_check;

typedef struct s_all {
	t_ptr	ptr;
	t_text	text_floor;
	t_text	text_wall;
	t_text	text_col;
	t_text	text_exit;
	t_text	text_player;
	t_data	data;
	t_map	map;
	t_check	check;
	int		compteur;
}			t_all;

//check_1.c
void	check_map(t_all *d);
void	check_map_ouverte_2(t_all *d, int x, int y);
void	check_map_ouverte_1(t_all *d);
void	check_map_2(t_all *d);
void	check_map_1(t_all *d);

//check_2.c
int		check_collectible(char **map);
int		get_window_size(t_all *d);
int		init_pos(t_all *d);

//init.c
void	ft_init(t_all *d);
void	ft_exit(t_all *d, char *str);

//main.c
int		ft_processus(t_all *d);
char	**ft_parsing(char *path);
int		red_cross(t_all *d);

//utils.c
void	ft_putchar(char *str);
char	*ft_itoa(int nb);
void	ft_free(char **str);

//print.c
void	print_screen(t_all *d);
void	init_texture(t_all *d);
void	select_char(char c, int i, int j, t_all *d);

//key.c
int		ft_key(int key, t_all *d);
void	key_right(t_all *d);
void	key_left(t_all *d);
void	key_down(t_all *d);
void	key_up(t_all *d);

#endif