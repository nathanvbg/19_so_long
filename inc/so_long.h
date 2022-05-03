/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:14:00 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/03 14:14:17 by naverbru         ###   ########.fr       */
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
	void *mlx;
	void *win;
}				t_ptr;

typedef struct s_img {
	void	*ptr;
	int		width;
	int		height;
	char	*path;
}			t_img;

typedef struct	s_all {
	t_ptr ptr;
	t_img xpm;
	t_data data;
	char **map;
} 				t_all;

//parsing.c
char	**ft_parsing(char *path);
int		check_map(char **map);

//main.c
void	ft_putchar(char *str);

#endif