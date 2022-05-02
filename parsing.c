/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:20:13 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/02 16:05:19 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

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

int	check_map(char **map)
{
	if (check_map_1(map) == -1)
		return (-1);
	if (check_map_2(map) == -1)
		return (-1);
	return (1);
}