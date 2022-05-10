/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:43:09 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/10 13:02:23 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	select_char(char c, int i, int j, t_all *d)
{
	if (i == d->map.pos_y && j == d->map.pos_x)
		mlx_put_image_to_window(d->ptr.mlx, d->ptr.win, d->text_player.ptr,
			j * 40, i * 40);
	else if (c == '0' || c == 'P')
		mlx_put_image_to_window(d->ptr.mlx, d->ptr.win, d->text_floor.ptr,
			j * 40, i * 40);
	else if (c == '1')
		mlx_put_image_to_window(d->ptr.mlx, d->ptr.win, d->text_wall.ptr,
			j * 40, i * 40);
	else if (c == 'C')
		mlx_put_image_to_window(d->ptr.mlx, d->ptr.win, d->text_col.ptr,
			j * 40, i * 40);
	else if (c == 'E')
		mlx_put_image_to_window(d->ptr.mlx, d->ptr.win, d->text_exit.ptr,
			j * 40, i * 40);
}

void	init_texture(t_all *d)
{
	d->text_floor.ptr = mlx_xpm_file_to_image(d->ptr.mlx,
			"./text/sand.xpm",
			&d->text_floor.width, &d->text_floor.height);
	d->text_wall.ptr = mlx_xpm_file_to_image(d->ptr.mlx,
			"./text/wall.xpm",
			&d->text_wall.width, &d->text_wall.height);
	d->text_col.ptr = mlx_xpm_file_to_image(d->ptr.mlx,
			"./text/helicopter.xpm",
			&d->text_wall.width, &d->text_wall.height);
	d->text_exit.ptr = mlx_xpm_file_to_image(d->ptr.mlx,
			"./text/gas.xpm",
			&d->text_wall.width, &d->text_wall.height);
	d->text_player.ptr = mlx_xpm_file_to_image(d->ptr.mlx,
			"./text/player.xpm",
			&d->text_wall.width, &d->text_wall.height);
}

void	print_screen(t_all *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d->map.map[i])
	{
		j = 0;
		while (d->map.map[i][j])
		{
			select_char(d->map.map[i][j], i, j, d);
			j++;
		}
		i++;
	}
}
