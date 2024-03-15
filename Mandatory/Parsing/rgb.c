/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamsyah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 04:47:22 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/15 06:11:58 by bamsyah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_convert(char *color)
{
	char	*path;
	int		val;

	if (!color)
		ft_putendl_fd("Error Invalid File", 2);
	path = ft_strtrim(color, " ");
	if (path[0] == '\0')
		ft_putendl_free("Error Invalid File", 2, path);
	val = ft_atoi(path);
	free(path);
	return (val);
}

void	rgb_valid(char **rgb)
{
	char	*path;
	int		color;
	int		i;
	int		j;

	i = -1;
	if (ft_file_len(rgb) != 3)
		ft_putendl_fd("Invalid rgb", 2);
	while (rgb[++i])
	{
		j = -1;
		path = ft_strtrim(rgb[i], " ");
		while (path[++j])
			if (!ft_isdigit(path[j]) && path[j] != '\n')
				ft_putendl_free("Invalid rgb", 2, path);
		color = ft_atoi(path);
		if (color < 0 || color > 255)
			ft_putendl_free("Invalid rgb", 2, path);
		free(path);
	}
}

void	fill_rgbs(t_cub_pars *cub, char **rgb, char id)
{
	rgb_valid(rgb);
	if (id == 'F')
	{
		if (cub->floor.b != -1 || cub->floor.g != -1
			|| cub->floor.r != -1)
			ft_putendl_fd("Error Invalid File", 2);
		cub->floor.r = ft_convert(rgb[0]);
		cub->floor.g = ft_convert(rgb[1]);
		cub->floor.b = ft_convert(rgb[2]);
	}
	if (id == 'C')
	{
		if (cub->celling.b != -1 || cub->celling.g != -1
			|| cub->celling.r != -1)
			ft_putendl_fd("Error Invalid File", 2);
		cub->celling.r = ft_convert(rgb[0]);
		cub->celling.g = ft_convert(rgb[1]);
		cub->celling.b = ft_convert(rgb[2]);
	}
}

int	comma(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return 1;
	return 0;
}

void	save_rgb(t_cub_pars *cub, char *line)
{
	char	**rgb;
	char	*path;

	path = ft_strtrim(line, " ");
	if (comma(path) == 1)
		ft_putendl_free("Invalid Elements", 2, path);
	rgb = ft_split(path, ',');
	if (line[0] == 'F')
		fill_rgbs(cub, rgb, 'F');
	else if (line[0] == 'C')
		fill_rgbs(cub, rgb, 'C');
	else
	{
		clean_map(rgb);
		ft_putendl_free("Invalid Elements", 2, path);
	}
}
