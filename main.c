/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:17:16 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/03 14:40:01 by naverbru         ###   ########.fr       */
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

void	lets_go(t_all *d)
{
	int i;

	i = 0;
	while (i < 10)
	{
		d->xpm.ptr = mlx_xpm_file_to_image(d->ptr.mlx, "./floor_1.xpm", &d->xpm.width, &d->xpm.height);
		i++;
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
	return (1);
}

int	ft_processus(t_all *d)
{
	int x;
	int y;

	d->xpm.ptr = NULL;
	d->ptr.mlx = mlx_init();
	d->ptr.win = mlx_new_window(d->ptr.mlx, 1000, 800, "yes");
	//printf("xpm = %X\n", xpm_text);
	//d->data.img = mlx_new_image(d->ptr.mlx, 1000, 800);
	//d->data.addr = mlx_get_data_addr(d->data.img, &d->data.bbp, &d->data.line_length, &d->data.endian);
	d->xpm.ptr = mlx_xpm_file_to_image(d->ptr.mlx, "/Users/naverbru/Desktop/so_long/text/floor_1.xpm", &d->xpm.width, &d->xpm.height);
	//lets_go(d);
	printf("hello\n");
	mlx_put_image_to_window(d->ptr.mlx, d->ptr.win, d->xpm.ptr, 0, 0);
	//if (mlx_hook(d->ptr.win, 2, 1L<<0, ft_key, d) == 0)
	//	return (0);
	mlx_loop(d->ptr.mlx);
	return (1);
}

int	main(int ac, char **av)
{
	t_all	d;
	
	ac = 3;
	d.map = ft_parsing(av[1]);
	if (check_map(d.map) == -1)
		return (1);
	ft_processus(&d);
	return (0);
}