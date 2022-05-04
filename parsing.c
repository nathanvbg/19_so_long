/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:20:13 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/04 17:13:46 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

int	ft_exit(char *str)
{
	ft_putchar(str);
	printf("TESST\n");
	return (-1);
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
	while (map[i])
	{
		printf("map = %s\n", map[i]);
		i++;
	}
	return (map);
}

int	check_map_ouverte_2(char **map, int x_length, int y_length)
{
	int i;

	i = 0;
	while(i < y_length)//gauche
	{
		if (map[i][0] != '1')
			return (ft_exit("Error\nMap ouverte\n"));
		i++;
	}
	i = 0;
	while(i < y_length)//droite
	{
		if (map[i][x_length - 1] != '1')
			return (ft_exit("Error\nMap ouverte\n"));
		i++;
	}
	return (1);
}

int	check_map_ouverte_1(char **map)
{
	int	j;
	int	x_length;
	int	y_length;

	j = 0;
	x_length = ft_strlen(map[0]);
	while (map[y_length])
		y_length++;
	while (j < x_length)//haut
	{
		if (map[0][j] != '1')
			return (ft_exit("Error\nMap ouverte\n"));
		j++;
	}
	j = 0;
	while (j < x_length)//bas
	{
		if (map[y_length - 1][j] != '1')
			return (ft_exit("Error\nMap ouverte\n"));
		j++;
	}
	if (check_map_ouverte_2(map, x_length, y_length) == -1)
		return (-1);
	return (1);
}

int	check_map_2(char **map)
{
	int	i;
	int	j;
	int	check_e;
	int	check_p;
	int	check_c;

	i = 0;
	check_e = 0;
	check_p = 0;
	check_c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				check_e++;
			if (map[i][j] == 'P')
				check_p++;
			if (map[i][j] == 'C')
				check_c++;
			j++;
		}
		i++;
	}
	if (check_e != 1 || check_p != 1 || check_c < 1)
	{
		ft_putchar("Error\nStart/end position error or collectible error\n");
		return(-1);
	}
	return (1);
}

int	check_map_1(char **map)
{
	int	i;
	int	j;
	int	line_length;

	i = 0;
	line_length = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != line_length)
		{
			ft_putchar("Error\nNot a rectangle\n");
			return (-1);
		}
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E' 
				&& map[i][j] != 'C' && map[i][j] != 'P')
			{
				ft_putchar("Error\nWrong character\n");
				return(-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

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

int	check_map(char **map, t_all *d)
{
	if (check_map_1(map) == -1)
		return (-1);
	if (check_map_2(map) == -1)
		return (-1);
	if (check_map_ouverte_1(map) == -1)
		return (-1);
	init_pos(d);
	return (1);
}