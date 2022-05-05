/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:43:21 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/05 13:28:56 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_exit(t_all *d, char *str)
{
	ft_putchar(str);
	int	i;

	i = 0;
	while (d->map.map[i])
	{
		ft_free(&d->map.map[i]);
		i++;
	}
	free(d->map.map);
	ft_free(&d->data.addr);
	ft_free(&d->text_floor.path);
	ft_free(&d->text_wall.path);
	ft_free(&d->text_col.path);
	ft_free(&d->text_exit.path);
	ft_free(&d->text_player.path);
	exit(0);
}

void	ft_init(t_all *d)
{
	d->compteur = 0;
	d->data.addr = NULL;
	d->map.map = NULL;
	d->text_floor.path = NULL;
	d->text_wall.path = NULL;
	d->text_col.path = NULL;
	d->text_exit.path = NULL;
	d->text_player.path = NULL;
}
