/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 06:18:42 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/15 16:37:59 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_texture_dir(t_cub_pars cub)
{
	if (!cub.directions.north)
		return (1);
	if (!cub.directions.south)
		return (1);
	if (!cub.directions.east)
		return (1);
	if (!cub.directions.west)
		return (1);
	return (0);
}

int	is_rgb(t_cub_pars cub)
{
	if (cub.celling.r == -1 || cub.celling.g == -1 || cub.celling.b == -1)
		return (1);
	if (cub.floor.r == -1 || cub.floor.g == -1 || cub.floor.b == -1)
		return (1);
	return (0);
}

void	is_map_elements(t_cub_pars cub)
{
	if (check_texture_dir(cub) == 1)
		ft_putendl_fd("Error Invalid Map", 2);
	if (is_rgb(cub) == 1)
		ft_putendl_fd("Error Invalid Map", 2);
}

void	check_rgb(t_cub_pars cub)
{
	if (cub.celling.r > 255 || cub.celling.r < 0)
		ft_putendl_fd("Error Invalid Map", 2);
	if (cub.celling.g > 255 || cub.celling.g < 0)
		ft_putendl_fd("Error Invalid Map", 2);
	if (cub.celling.b > 255 || cub.celling.b < 0)
		ft_putendl_fd("Error Invalid Map", 2);
	if (cub.floor.r > 255 || cub.floor.r < 0)
		ft_putendl_fd("Error Invalid Map", 2);
	if (cub.floor.g > 255 || cub.floor.g < 0)
		ft_putendl_fd("Error Invalid Map", 2);
	if (cub.floor.b > 255 || cub.floor.b < 0)
		ft_putendl_fd("Error Invalid Map", 2);
}

void	check_texture(t_cub_pars cub)
{
	if (!cub.directions.north)
		ft_putendl_fd("Error Invalid Map", 2);
	if (!cub.directions.south)
		ft_putendl_fd("Error Invalid Map", 2);
	if (!cub.directions.east)
		ft_putendl_fd("Error Invalid Map", 2);
	if (!cub.directions.west)
		ft_putendl_fd("Error Invalid Map", 2);
}

void	is_graphics(t_cub_pars cub)
{
	is_map_elements(cub);
	check_rgb(cub);
	check_texture(cub);
}
