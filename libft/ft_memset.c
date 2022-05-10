/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 08:50:01 by naverbru          #+#    #+#             */
/*   Updated: 2022/01/05 08:50:57 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t len)
{
	size_t			i;
	char			*str;

	i = 0;
	str = (char *)src;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (src);
}
