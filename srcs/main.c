/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:17:16 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/09 17:32:44 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	red_cross(t_all *d)
{
	mlx_destroy_window(d->ptr.mlx, d->ptr.win);
	ft_exit(d, "");
	return (1);
}

int	ft_processus(t_all *d)
{
	d->ptr.mlx = mlx_init();
	d->ptr.win = mlx_new_window(d->ptr.mlx, d->ptr.win_height * 40,
			d->ptr.win_width * 40, "so_long");
	init_texture(d);
	print_screen(d);
	mlx_hook(d->ptr.win, 2, 1L << 0, ft_key, d);
	mlx_hook(d->ptr.win, 17, 0, red_cross, d);
	mlx_loop(d->ptr.mlx);
	return (1);
}

void	ft_parsing(char *path, t_all *d)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*gnl;

	d->map.map = NULL;
	fd = open(path, O_RDONLY);
	line = ft_strdup("");
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		temp = line;
		line = ft_strjoin(line, gnl);
		free(gnl);
		free(temp);
	}
	d->map.map = ft_split(line, '\n');
	free(line);
}

int	main(int ac, char **av)
{
	t_all	d;

	if (ac != 2)
	{
		ft_putchar("Wrong number of arguments.");
		return (1);
	}
	ft_init(&d);
	ft_parsing(av[1], &d);
	check_map(&d);
	d.ptr.mlx = mlx_init();
	ft_processus(&d);
	system("leaks so_long");
	return (0);
}
