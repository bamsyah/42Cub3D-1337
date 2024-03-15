/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 04:48:37 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/15 02:27:52 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_count(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	long	nb;

	nb = n;
	i = ft_count(nb);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = 0;
	i--;
	if (nb == 0)
		str[i] = 48;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	return (str);
}
