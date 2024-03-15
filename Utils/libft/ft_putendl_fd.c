/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:18:52 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/15 05:57:33 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	exit(1);
}

void	ft_putendl_free(char *s, int fd, char *str)
{
	free(str);
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	exit(1);
}
