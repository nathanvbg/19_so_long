/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:17:16 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/03 12:01:44 by naverbru         ###   ########.fr       */
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
/*
void	lets_go(t_ptr *ptr, t_data *img, t_img *xpm)
{

}
*/
int	ft_key(int key, t_ptr *ptr)
{
	printf("%d\n", key);
	if (key == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		return (0);
	}
	return (1);
}

int	ft_processus(t_ptr *ptr, t_data *img, t_img *xpm)
{
	void *xpm_text;
	int x;
	int y;

	xpm->ptr == NULL;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 1000, 800, "yes");
	xpm->ptr = mlx_xpm_file_to_image(ptr->mlx, "/Users/naverbru/Desktop/so_long/text/floor_1.xpm", &xpm->width, &xpm->height);
	printf("xpm = %X\n", xpm_text);
	img->img = mlx_new_image(ptr->mlx, 1000, 800);
	img->addr = mlx_get_data_addr(img->img, &img->bbp, &img->line_length, &img->endian);
	//lets_go(ptr, img, xpm);
	mlx_put_image_to_window(ptr->mlx, ptr->win, img->img, 0, 0);
	if (mlx_hook(ptr->win, 2, 1L<<0, ft_key, ptr) == 0)
		return (0);
	mlx_loop(ptr->mlx);
	return (1);
}

int	main(int ac, char **av)
{
	t_ptr 	ptr;
	t_data	img;
	t_img	xpm;
	char 	**map;
	
	ac = 3;
	map = ft_parsing(av[1]);
	if (check_map(map) == -1)
		return (1);
	ft_processus(&ptr, &img, &xpm);
	return (0);
}