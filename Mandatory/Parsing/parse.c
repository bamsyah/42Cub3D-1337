/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 02:38:54 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/16 04:41:57 by bkaztaou         ###   ########.fr       */
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

int	parse_elements(t_cub_pars *cub, char *line)
{
	char	*trim_line;
	char	**split_line;

	trim_line = ft_strtrim(line, " \t\n");
	split_line = ft_split(trim_line, ' ');
	if (!is_cardinal_direction(line))
		return (save_cardinal_direction(cub, line), 0);
	else if ((split_line[0][0] == 'F' || split_line[0][0] == 'C'))
		return (save_rgb(cub, line), 0);
	else if (!is_map(trim_line) && !is_graphics(*cub))
	{
		cub->map = ft_strjoin(cub->map, line);
		return (0);
	}
	return (1);
}

void	parse(t_cub_pars *cub)
{
	char	*line;

	cub->map = ft_strdup("");
	while (1)
	{
		line = get_next_line(cub->fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		if (parse_elements(cub, line))
			ft_putendl_fd("Invalide Map", 2);
		free(line);
	}
	check_map(cub);
}
