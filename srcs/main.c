/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:17:16 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/10 12:19:53 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	red_cross(t_all *d)
{
	mlx_destroy_window(d->ptr.mlx, d->ptr.win);
	ft_exit(d, "");
	return (1);
}

void	ft_processus(t_all *d)
{
	d->ptr.mlx = mlx_init();
	if (d->ptr.mlx == NULL)
		ft_exit(d, "Error\nmlx Error\n");
	d->ptr.win = mlx_new_window(d->ptr.mlx, d->ptr.win_height * 40,
			d->ptr.win_width * 40, "so_long");
	if (d->ptr.win == NULL)
		ft_exit(d, "Error\nmlx Error\n");
	init_texture(d);
	print_screen(d);
	mlx_hook(d->ptr.win, 2, 1L << 0, ft_key, d);
	mlx_hook(d->ptr.win, 17, 0, red_cross, d);
	mlx_loop(d->ptr.mlx);
}

char	*ft_parsing(char *path, t_all *d)
{
	int		fd;
	char	*line;
	char	*temp;
	char	*gnl;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit(d, "Error\nWrong .ber file\n");
	line = ft_strdup("");
	if (line == NULL)
		ft_exit(d, "Error\nMalloc Error\n");
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		temp = line;
		line = ft_strjoin(line, gnl);
		free(gnl);
		free(temp);
		if (line == NULL)
			ft_exit(d, "Error\nMalloc error\n");
	}
	return (line);
}

int	main(int ac, char **av)
{
	t_all	d;
	char	*line;

	if (ac != 2)
	{
		ft_putchar("Error\nWrong number of arguments\n");
		return (1);
	}
	ft_init(&d);
	line = ft_parsing(av[1], &d);
	d.map.map = ft_split(line, '\n');
	free(line);
	if (d.map.map == NULL)
		ft_exit(&d, "Error\nEmpty map\n");
	check_map(&d);
	ft_processus(&d);
	system("leaks so_long");
	return (0);
}
