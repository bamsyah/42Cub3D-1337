/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 02:38:54 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/15 18:36:46 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	is_invalid_element(char *line)
{
	if (line[0] == '\n' && line[0] == '\0'
		&& line[0] == '\t')
		ft_putendl_fd("Error Invalid Map", 2);
}

void	save_map(t_cub_pars *cub, char *line)
{
	char	*copy;

	is_invalid_element(line);
	copy = ft_strdup(line);
	while (copy)
	{
		cub->map = ft_strjoin(cub->map, copy);
		free(copy);
		copy = get_next_line(cub->fd);
	}
	check_newline(cub->map);
	check_map(cub);
	check_newline(cub->map);
}

void	parse_elements(t_cub_pars *cub, char *line)
{
	if (is_cardinal_direction(line) == 1)
		ft_putendl_fd("Invalid Elements --", 2);
	save_cardinal_direction(cub, line);
	if (line[0] == 'F' || line[0] == 'C')
		save_rgb(cub, line);
	else
	{
		is_map(line);
		is_graphics(*cub);
		save_map(cub, line);
	}
}

void	parse(t_cub_pars *cub)
{
	char	*line;

	while (1)
	{
		line = get_next_line(cub->fd);
		if (!line)
			break;
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		parse_elements(cub, line);
		free(line);
	}
}
