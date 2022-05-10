/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:58:46 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/09 14:04:20 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 10

char	*ft_endfree(char **str, char **buf)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	if (buf != NULL)
	{
		free(*buf);
		*str = NULL;
	}
	return (NULL);
}

char	*ft_free_gnl(char **str)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*ft_process(char **rest, int fd, int ret)
{
	char	*line;
	char	*buf;
	char	*tmp;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (ft_free_gnl(rest));
	line = ft_strjoin_gnl("", *rest);
	if (!line)
		return (ft_endfree(rest, &buf));
	ft_free_gnl(rest);
	while (ret > 0 && is_charset(line) != 1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0 && ft_strlen_gnl(line) == 0)
			return (ft_endfree(&line, &buf));
		buf[ret] = '\0';
		tmp = line;
		line = ft_strjoin_gnl(line, buf);
		if (!line)
			return (ft_endfree(&tmp, &buf));
		free(tmp);
	}
	return (ft_endprocess(&line, &buf, &rest));
}

char	*ft_endprocess(char **line, char **buf, char ***rest)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strndup_gnl(*line, '\n');
	if (*line == NULL)
		return (ft_endfree(&tmp, buf));
	**rest = ft_strndup_gnl(ft_strchr_gnl(tmp, '\n'), '\0');
	free(tmp);
	if (**rest == NULL)
		return (ft_endfree(line, buf));
	ft_free_gnl(buf);
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*line;
	int			ret;

	ret = 1;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (rest[fd] == NULL)
		rest[fd] = ft_strndup_gnl("", '\0');
	if (rest[fd] == NULL)
		return (NULL);
	line = ft_process(&rest[fd], fd, ret);
	return (line);
}

/*
#include <stdio.h>
int	main()
{
	char	*line;
	int		fd;

	fd = open("alternate_line_nl_with_nl", O_RDONLY);
	printf("%s", get_next_line(fd));
	while ((line = get_next_line(fd)))
		printf("%s", line);
	close(fd);
	return (0);
}
*/
