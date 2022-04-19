/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:17:16 by naverbru          #+#    #+#             */
/*   Updated: 2022/04/19 19:02:53 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	my_pixel_put(t_data *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bbp / 8));
	*(unsigned int*)dst = color;
}

void	lets_go(t_data *img)
{
	int i;
	int j;

	i = 100;
	j = 100;
	while (i < 400)
	{
		my_pixel_put(img, i, j, 0x00FF0000);
		i++;
	}
	while (j < 400)
	{
		my_pixel_put(img, i, j, 0x00FF0000);
		j++;
	}
}

int	ft_key(int key, t_ptr *ptr)
{
	printf("%d\n", key);
	if (key == 53)
		mlx_destroy_window(ptr->mlx, ptr->win);
	return (0);
}

int	main(void)
{
	t_ptr 	ptr;
	t_data	img;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 1000, 800, "yes");
	img.img = mlx_new_image(ptr.mlx, 1000, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bbp, &img.line_length, &img.endian);
	lets_go(&img);
	mlx_put_image_to_window(ptr.mlx, ptr.win, img.img, 0, 0);
	mlx_hook(ptr.win, 2, 1L<<0, ft_key, &ptr);
	mlx_loop(ptr.mlx);
}