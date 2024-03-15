/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extention.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:28:24 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/15 02:11:12 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_file_len(char **file_splite)
{
	int	i;

	i = 0;
	while (file_splite[i])
		i++;
	return (i);
}

void	check_file_extention(char *file_name)
{
    char	**file_split;
	int		len;

	file_split = ft_split(file_name, '.');
	len = ft_file_len(file_split);
	if (ft_strncmp(file_split[len - 1], "cub", 3) != 0)
	{
		clean_map(file_split);
		ft_putendl_fd("Invalid File", 2);
	}
	clean_map(file_split);
}
