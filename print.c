/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:43:09 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/03 17:36:45 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"
/*
void	print_texture(char* path, int i, int j, t_all d)
{
	mlx_put_image_to_window(d->ptr.mlx, d->ptr.win, d->text.ptr, 0, 0);
}
*/

void	select_char(char c, int i, int j, t_all *d)
{
	if (c == '0')
		mlx_put_image_to_window(d->ptr.mlx, d->ptr.win, d->text_floor.ptr, j * 16, i * 16);
	if (c == '1')
		mlx_put_image_to_window(d->ptr.mlx, d->ptr.win, d->text_wall.ptr, j * 16, i * 16);
}

void	print_screen(t_all *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			select_char(d->map[i][j], i, j, d);
			j++;
		}
		i++;
	}
}