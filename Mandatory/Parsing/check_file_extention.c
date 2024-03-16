/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extention.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:28:24 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/16 17:07:13 by bkaztaou         ###   ########.fr       */
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
		return (clean_map(file_split), 1);
	return (clean_map(file_split), 0);
}
