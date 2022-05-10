/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:00:55 by naverbru          #+#    #+#             */
/*   Updated: 2022/01/05 08:33:54 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_nb(long int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int nb)
{
	char		*str;
	int			len;
	long int	n;
	int			neg;

	neg = 0;
	n = (long int) nb;
	len = ft_size_nb(n);
	str = malloc(len + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	while (--len >= 0)
	{
		str[len] = n % 10 + 48;
		n /= 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
