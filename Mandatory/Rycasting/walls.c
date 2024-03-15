/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:30:24 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/03/15 15:31:06 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	help_wall(t_mlx *mlx)
{
	mlx->wall.ray_distance = mlx->distance * cos(mlx->rayangle
			- mlx->cub3d.player.rotation_angle);
	mlx->wall.distance_pjplane = (MAP_W / 2) / tan((FA * (M_PI / 180)) / 2);
	mlx->wall.wall_strip_height = (TILE_SIZE / mlx->wall.ray_distance)
		* mlx->wall.distance_pjplane;
	mlx->wall.walltp = (MAP_H / 2) - (mlx->wall.wall_strip_height / 2);
	if (mlx->wall.walltp <= 0)
		mlx->wall.walltp = 0;
	mlx->wall.wallbop = (MAP_H / 2) + (mlx->wall.wall_strip_height / 2);
	if (mlx->wall.wallbop > MAP_H)
		mlx->wall.wallbop = MAP_H;
}

unsigned int	render_wall(t_mlx *mlx, unsigned int color)
{
	if (mlx->x_offset == 0)
	{
		mlx->tex_y = mlx->wall.distance_fromtop * (mlx->so_texture->height
				/ mlx->wall.wall_strip_height);
		color = get_color(mlx->so_texture, mlx->tex_x, mlx->tex_y);
	}
	else if (mlx->x_offset == 1)
	{
		mlx->tex_y = mlx->wall.distance_fromtop * (mlx->no_texture->height
				/ mlx->wall.wall_strip_height);
		color = get_color(mlx->no_texture, mlx->tex_x, mlx->tex_y);
	}
	else if (mlx->x_offset == 2)
	{
		mlx->tex_y = mlx->wall.distance_fromtop * (mlx->ea_texture->height
				/ mlx->wall.wall_strip_height);
		color = get_color(mlx->ea_texture, mlx->tex_x, mlx->tex_y);
	}
	else if (mlx->x_offset == 3)
	{
		mlx->tex_y = mlx->wall.distance_fromtop * (mlx->we_texture->height
				/ mlx->wall.wall_strip_height);
		color = get_color(mlx->we_texture, mlx->tex_x, mlx->tex_y);
	}
	return (color);
}

void	render_3dwall(t_mlx *mlx, int *j)
{
	mlx->wall.distance_fromtop = (*j) + (mlx->wall.wall_strip_height / 2)
		- (MAP_H / 2);
	mlx->tex_y = mlx->wall.distance_fromtop * (mlx->no_texture->height
			/ mlx->wall.wall_strip_height);
}

void	render_topwall(t_mlx *mlx, int *j, int nb)
{
	while ((*j) < mlx->wall.walltp)
	{
		my_mlx_pixel_put(&mlx->data, nb, (*j), rgb_to_int(mlx->cub3d.celling.r,
				mlx->cub3d.celling.g, mlx->cub3d.celling.b));
		(*j)++;
	}
}

void	render3dwalls(t_mlx *mlx, int nb)
{
	unsigned int	color;
	int				j;

	j = 0;
	mlx->tex_y = 0;
	mlx->tex_x = get_x(mlx);
	help_wall(mlx);
	render_topwall(mlx, &j, nb);
	while (j < mlx->wall.wallbop)
	{
		render_3dwall(mlx, &j);
		getdirection(mlx);
		color = render_wall(mlx, color);
		if (mlx->is_vertical == 0 && mlx->is_horizontal == 0)
			my_mlx_pixel_put(&mlx->data, nb, j, 0);
		my_mlx_pixel_put(&mlx->data, nb, j, color);
		j++;
	}
	while (j < MAP_H)
	{
		my_mlx_pixel_put(&mlx->data, nb, j, rgb_to_int(mlx->cub3d.floor.r,
				mlx->cub3d.floor.g, mlx->cub3d.floor.b));
		j++;
	}
}