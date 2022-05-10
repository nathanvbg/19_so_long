/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:13:38 by naverbru          #+#    #+#             */
/*   Updated: 2022/01/05 13:22:43 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	return_value;

	return_value = ft_strlen(dest) + ft_strlen(src);
	i = 0;
	len = ft_strlen(dest);
	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	while (src[i] && (len + i) < size - 1)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[i + len] = '\0';
	return (return_value);
}
