/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strt_clos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:28:02 by sabdulla          #+#    #+#             */
/*   Updated: 2022/11/22 16:28:32 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	close_win(t_maps *map)
{
	ft_printf("map was too hard for you:)\n");
	mlx_destroy_image(map->mlx, map->coin);
	mlx_destroy_image(map->mlx, map->exit);
	mlx_destroy_image(map->mlx, map->space);
	mlx_destroy_image(map->mlx, map->wall_p);
	mlx_destroy_window(map->mlx, map->win);
	my_free(map);
	exit(0);
}

void	start_game(t_maps *map)
{
	int	w;
	int	h;

	w = map->w * 64;
	h = map->h * 64;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, w, h, "so_long");
	open_xpm(map);
	print_map(map);
	mlx_hook(map->win, 2, 1L << 0, exit_game, map);
	mlx_hook(map->win, 17, 1L << 17, close_win, map);
	mlx_loop(map->mlx);
}
