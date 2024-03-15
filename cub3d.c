/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:23:05 by bamsyah           #+#    #+#             */
/*   Updated: 2024/03/15 16:31:01 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	gameloop(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, MAP_W, MAP_H, "cub3d");
	player_init(&mlx->cub3d);
	textures_init(mlx);
	render(mlx);
	mlx_hook(mlx->mlx_win, 2, 0, key_press, mlx);
	mlx_hook(mlx->mlx_win, 3, 0, key_release, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, close_window, mlx);
	mlx_loop_hook(mlx->mlx_ptr, game, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	mlx = (t_mlx){0};
	if (ac == 2)
	{
		ft_initialize(&mlx.cub3d);
		parsing(&mlx.cub3d, av);
		printf("Parsing\n");
		gameloop(&mlx);
	}
	else
		ft_putendl_fd("Error Invalid Input", 2);
	return (1);
}
