/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:10:32 by naverbru          #+#    #+#             */
/*   Updated: 2022/01/12 22:41:23 by nathanvbg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	x;

	x = (char) c;
	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == x)
			return (&str[i]);
		i++;
	}
	if (x == '\0')
		return (&str[i]);
	return (NULL);
}
