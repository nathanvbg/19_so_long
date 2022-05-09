/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naverbru <naverbru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:10:06 by naverbru          #+#    #+#             */
/*   Updated: 2022/05/09 17:21:52 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_free(char **str)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

void	ft_putchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

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
