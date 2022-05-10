/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:34:53 by naverbru          #+#    #+#             */
/*   Updated: 2022/01/05 13:36:03 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;
	char	*needle;

	i = 0;
	hay = (char *)str;
	needle = (char *)to_find;
	if (needle[0] == '\0')
		return (hay);
	while (hay[i] && i < len)
	{
		j = 0;
		while ((hay[i + j] == needle[j]) && hay[i] && (i + j) < len)
		{
			j++;
			if (needle[j] == '\0')
				return (&hay[i]);
		}
		i++;
	}
	return (NULL);
}
