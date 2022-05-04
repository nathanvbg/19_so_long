/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:17:16 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/04 16:27:16 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_putchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	my_pixel_put(t_data *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bbp / 8));
	*(unsigned int*)dst = color;
}



int	ft_processus(t_all *d)
{
	int x;
	int y;

	d->ptr.mlx = mlx_init();
	d->ptr.win = mlx_new_window(d->ptr.mlx, 1000, 800, "yes");
	init_texture(d);
	print_screen(d);
	if (mlx_hook(d->ptr.win, 2, 1L<<0, ft_key, d) == 0)
		return (0);
	mlx_loop(d->ptr.mlx);
	return (1);
}

int	main(int ac, char **av)
{
	t_all	d;
	
	ac = 3;
	d.map.map = ft_parsing(av[1]);
	if (check_map(d.map.map, &d) == -1)
		return (1);
	ft_processus(&d);
	return (0);
}