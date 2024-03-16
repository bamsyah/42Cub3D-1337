/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:58:22 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/16 04:40:00 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parsing(t_cub_pars *cub, char **av)
{
	cub->file_name = av[1];
	cub->fd = open(cub->file_name, O_RDONLY);
	if (check_file_extention(cub->file_name))
		ft_putendl_fd("Error Invalid File", 2);
	parse(cub);
}
