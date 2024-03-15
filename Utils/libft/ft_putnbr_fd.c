/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:22:18 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/15 02:28:14 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	x;

	x = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		x = x * -1;
	}
	if (x >= 10)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
	else
	{
		ft_putchar_fd(x + '0', fd);
	}
}