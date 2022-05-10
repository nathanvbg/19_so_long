/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:45:28 by naverbru          #+#    #+#             */
/*   Updated: 2022/01/05 08:47:37 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str;
	char	*src2;
	size_t	i;

	if (src == NULL && dst == NULL)
		return (NULL);
	str = (char *)dst;
	src2 = (char *)src;
	i = 0;
	while (i < n)
	{
		str[i] = src2[i];
		i++;
	}
	return (str);
}
