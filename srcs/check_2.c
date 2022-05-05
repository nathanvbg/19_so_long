/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:13:03 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/05 13:15:33 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_collectible(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_window_size(t_all *d)
{
	int	i;

	i = 0;
	while (d->map.map[i])
		i++;
	d->ptr.win_width = i * 40;
	d->ptr.win_height = ft_strlen(d->map.map[0]) * 40;
	return (1);
}

int	init_pos(t_all *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map.map[i])
	{
		j = 0;
		while (d->map.map[i][j])
		{
			if (d->map.map[i][j] == 'P')
			{
				d->map.pos_x = j;
				d->map.pos_y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
