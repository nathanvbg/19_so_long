/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:17:16 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/05 13:17:08 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_processus(t_all *d)
{
	int x;
	int y;

	d->ptr.mlx = mlx_init();
	d->ptr.win = mlx_new_window(d->ptr.mlx, d->ptr.win_height, d->ptr.win_width, "yes");
	init_texture(d);
	print_screen(d);
	if (mlx_hook(d->ptr.win, 2, 1L<<0, ft_key, d) == 0)
		return (0);
	mlx_loop(d->ptr.mlx);
	return (1);
}

char	**ft_parsing(char *path)
{
	int		fd;
	char	**map;
	char	*line;
	char	*temp;
	char	*gnl;

	map = NULL;
	fd = open(path, O_RDONLY);
	line = "";
	while (1 > 0)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		line = ft_strjoin(line, gnl);
	}
	map = ft_split(line, '\n');
	int i = 0;
	return (map);
}

int	main(int ac, char **av)
{
	t_all	d;
	
	ac = 3;
	ft_init(&d);
	d.map.map = ft_parsing(av[1]);
	if (check_map(d.map.map, &d) == -1)
		return (1);
	ft_processus(&d);
	return (0);
}