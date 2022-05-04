/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:23:36 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/04 17:19:18 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	key_up(t_all *d)
{
	if (d->map.map[d->map.pos_y - 1][d->map.pos_x] != '1')
		d->map.pos_y -= 1;
	if (d->map.map[d->map.pos_y][d->map.pos_x] == 'C')
		d->map.map[d->map.pos_y][d->map.pos_x] = '0';
	if (d->map.map[d->map.pos_y][d->map.pos_x] == 'E')
	{
		if (check_collectible(d->map.map) == 1)
			mlx_destroy_window(d->ptr.mlx, d->ptr.win);
	}
}

void	key_down(t_all *d)
{
	if (d->map.map[d->map.pos_y + 1][d->map.pos_x] != '1')
		d->map.pos_y += 1;
	if (d->map.map[d->map.pos_y][d->map.pos_x] == 'C')
		d->map.map[d->map.pos_y][d->map.pos_x] = '0';
	if (d->map.map[d->map.pos_y][d->map.pos_x] == 'E')
	{
		if (check_collectible(d->map.map) == 1)
			mlx_destroy_window(d->ptr.mlx, d->ptr.win);
	}
}

void	key_left(t_all *d)
{
	if (d->map.map[d->map.pos_y][d->map.pos_x - 1] != '1')
		d->map.pos_x -= 1;
	if (d->map.map[d->map.pos_y][d->map.pos_x] == 'C')
		d->map.map[d->map.pos_y][d->map.pos_x] = '0';
	if (d->map.map[d->map.pos_y][d->map.pos_x] == 'E')
	{
		if (check_collectible(d->map.map) == 1)
			mlx_destroy_window(d->ptr.mlx, d->ptr.win);
	}
}

void	key_right(t_all *d)
{
	if (d->map.map[d->map.pos_y][d->map.pos_x + 1] != '1')
		d->map.pos_x += 1;
	if (d->map.map[d->map.pos_y][d->map.pos_x] == 'C')
		d->map.map[d->map.pos_y][d->map.pos_x] = '0';
	if (d->map.map[d->map.pos_y][d->map.pos_x] == 'E')
	{
		if (check_collectible(d->map.map) == 1)
			mlx_destroy_window(d->ptr.mlx, d->ptr.win);
	}
}

int	ft_key(int key, t_all *d)
{
	printf("%d\n", key);
	if (key == 53)
	{
		mlx_destroy_window(d->ptr.mlx, d->ptr.win);
		return (0);
	}
	if (key == 13)//haut
		key_up(d);
	if (key == 1)
		key_down(d);
	if (key == 0)
		key_left(d);
	if (key == 2)
		key_right(d);
	print_screen(d);
	return (1);
}