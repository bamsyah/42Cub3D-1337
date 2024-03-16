/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extention.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:28:24 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/16 04:37:20 by bkaztaou         ###   ########.fr       */
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

int	check_file_extention(char *file_name)
{
	char	**file_split;
	int		len;

	file_split = ft_split(file_name, '.');
	len = ft_file_len(file_split);
	if (ft_strncmp(file_split[len - 1], "cub", 3) != 0)
	{
		clean_map(file_split);
		return (1);
	}
	return (0);
}
