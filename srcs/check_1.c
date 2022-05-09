/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:20:13 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/09 15:08:35 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_map_ouverte_2(t_all *d, int x_length, int y_length)
{
	int	i;

	i = 0;
	while (i < y_length)
	{
		if (d->map.map[i][0] != '1')
			ft_exit(d, "Error\nMap not closed");
		i++;
	}
	i = 0;
	while (i < y_length)
	{
		if (d->map.map[i][x_length - 1] != '1')
			ft_exit(d, "Error\nMap not closed");
		i++;
	}
}

void	check_map_ouverte_1(t_all *d)
{
	int	j;
	int	x_length;
	int	y_length;

	j = 0;
	y_length = 0;
	x_length = ft_strlen(d->map.map[0]);
	while (d->map.map[y_length])
		y_length++;
	while (j < x_length)
	{
		if (d->map.map[0][j] != '1')
			ft_exit(d, "Error\nMap not closed");
		j++;
	}
	j = 0;
	while (j < x_length)
	{
		if (d->map.map[y_length - 1][j] != '1')
			ft_exit(d, "Error\nMap not closed");
		j++;
	}
	check_map_ouverte_2(d, x_length, y_length);
}

void	check_map_2(t_all *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map.map[i])
	{
		j = 0;
		while (d->map.map[i][j])
		{
			if (d->map.map[i][j] == 'E')
				d->check.e += 1;
			if (d->map.map[i][j] == 'P')
				d->check.p += 1;
			if (d->map.map[i][j] == 'C')
				d->check.c += 1;
			j++;
		}
		i++;
	}
	if (d->check.e != 1 || d->check.p != 1 || d->check.c < 1)
		ft_exit(d, "Error\nStart/end position error or collectible error\n");
}

void	check_map_1(t_all *d)
{
	int		i;
	int		j;
	size_t	line_length;

	i = 0;
	line_length = ft_strlen(d->map.map[0]);
	while (d->map.map[i])
	{
		if (ft_strlen(d->map.map[i]) != line_length)
			ft_exit(d, "Error\nNot a rectangle\n");
		j = 0;
		while (d->map.map[i][j])
		{
			if (d->map.map[i][j] != '1' && d->map.map[i][j] != '0'
				&& d->map.map[i][j] != 'E' && d->map.map[i][j] != 'C'
				&& d->map.map[i][j] != 'P')
				ft_exit(d, "Error\nWrong character\n");
			j++;
		}
		i++;
	}
}

void	check_map(t_all *d)
{
	get_window_size(d);
	check_map_1(d);
	check_map_2(d);
	check_map_ouverte_1(d);
	init_pos(d);
}
