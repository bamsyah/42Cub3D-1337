/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:23:05 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/15 14:38:12 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	t_cub_pars	cub;

	if (ac == 2)
	{
		ft_initialize(&cub);
		parsing(&cub, av);
	}
	else
		ft_putendl_fd("Error Invalid Input", 2);
	return (1);
}
