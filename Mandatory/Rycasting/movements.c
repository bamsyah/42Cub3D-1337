/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:34:39 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/03/15 15:35:08 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	look_left_right(t_mlx *mlx)
{
	mlx->cub3d.player.rotation_angle += mlx->cub3d.player.look
		* mlx->cub3d.player.turn_speed;
	render(mlx);
}

void	move_down_up(t_mlx *mlx)
{
	float	movestep;
	float	newplayerx;
	float	newplayery;

	movestep = mlx->cub3d.player.walk_direction * mlx->cub3d.player.walk_speed;
	newplayerx = mlx->cub3d.player.x + cos(mlx->cub3d.player.rotation_angle)
		* movestep;
	newplayery = mlx->cub3d.player.y + sin(mlx->cub3d.player.rotation_angle)
		* movestep;
	if (check_wall(mlx, newplayerx, mlx->cub3d.player.y) == 0)
		mlx->cub3d.player.x = newplayerx;
	if (check_wall(mlx, mlx->cub3d.player.x, newplayery) == 0)
		mlx->cub3d.player.y = newplayery;
	render(mlx);
}

void	move_left_right(t_mlx *mlx)
{
	float	movestep;
	float	newplayerx;
	float	newplayery;

	movestep = mlx->cub3d.player.walk_speed * mlx->cub3d.player.turn_direction;
	newplayerx = mlx->cub3d.player.x + cos(mlx->cub3d.player.rotation_angle
			+ M_PI_2) * movestep;
	newplayery = mlx->cub3d.player.y + sin(mlx->cub3d.player.rotation_angle
			+ M_PI_2) * movestep;
	if (check_wall(mlx, newplayerx, mlx->cub3d.player.y) == 0)
		mlx->cub3d.player.x = newplayerx;
	if (check_wall(mlx, mlx->cub3d.player.x, newplayery) == 0)
		mlx->cub3d.player.y = newplayery;
	render(mlx);
}