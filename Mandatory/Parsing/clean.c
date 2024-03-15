/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:14:58 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/14 17:15:58 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clean_map(char **file_split)
{
	int	i;

	i = 0;
	if (!file_split)
		return ;
	while (file_split[i])
	{
		free(file_split[i]);
		i++;
	}
	free(file_split);
}
