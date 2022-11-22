/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:08:54 by sabdulla          #+#    #+#             */
/*   Updated: 2022/11/22 02:16:50 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	go_left(t_maps *map)
{
	if (map->map[(map->py) / 64][(map->px - 64) / 64] == '1')
		return ;
	if (map->map[(map->py) / 64][(map->px - 64) / 64] == 'E'
			&& !map->nu_coin)
		exit_me_please(map);
	else if (map->map[(map->py) / 64][(map->px - 64) / 64] == 'E')
		return ;
	map->map[map->py / 64][map->px / 64] = '0';
	mlx_put_image_to_window(map->mlx, map->win,
		map->space, map->px, map->py);
	map->px = map->px - 64;
	if (map->map[map->py / 64][map->px / 64] == 'C')
		map->nu_coin--;
	map->map[map->py / 64][map->px / 64] = 'P';
	mlx_put_image_to_window(map->mlx, map->win,
		map->space, map->px, map->py);
	mlx_put_image_to_window(map->mlx, map->win,
		map->player, map->px, map->py);
	map->p_move++;
	ft_printf("%d\n", map->p_move);
}

void	go_down(t_maps *map)
{
	if (map->map[(map->py + 64) / 64][(map->px) / 64] == '1')
		return ;
	if (map->map[(map->py + 64) / 64][(map->px) / 64] == 'E'
			&& !map->nu_coin)
		exit_me_please(map);
	else if (map->map[(map->py + 64) / 64][(map->px) / 64] == 'E')
		return ;
	map->map[map->py / 64][map->px / 64] = '0';
	mlx_put_image_to_window(map->mlx, map->win,
		map->space, map->px, map->py);
	map->py = map->py + 64;
	if (map->map[map->py / 64][map->px / 64] == 'C')
		map->nu_coin--;
	map->map[map->py / 64][map->px / 64] = 'P';
	mlx_put_image_to_window(map->mlx, map->win,
		map->space, map->px, map->py);
	mlx_put_image_to_window(map->mlx, map->win,
		map->player, map->px, map->py);
	map->p_move++;
	ft_printf("%d\n", map->p_move);
}

void	go_right(t_maps *map)
{
	if (map->map[(map->py) / 64][(map->px + 64) / 64] == '1')
		return ;
	if (map->map[(map->py) / 64][(map->px + 64) / 64] == 'E'
			&& !map->nu_coin)
		exit_me_please(map);
	else if (map->map[(map->py) / 64][(map->px + 64) / 64] == 'E')
		return ;
	map->map[map->py / 64][map->px / 64] = '0';
	mlx_put_image_to_window(map->mlx, map->win,
		map->space, map->px, map->py);
	map->px = map->px + 64;
	if (map->map[map->py / 64][map->px / 64] == 'C')
		map->nu_coin--;
	map->map[map->py / 64][map->px / 64] = 'P';
	mlx_put_image_to_window(map->mlx, map->win,
		map->space, map->px, map->py);
	mlx_put_image_to_window(map->mlx, map->win,
		map->player, map->px, map->py);
	map->p_move++;
	ft_printf("%d\n", map->p_move);
}

void	go_up(t_maps *map)
{
	if (map->map[(map->py - 64) / 64][(map->px) / 64] == '1')
		return ;
	if (map->map[(map->py - 64) / 64][(map->px) / 64] == 'E' && !map->nu_coin)
		exit_me_please(map);
	else if (map->map[(map->py - 64) / 64][(map->px) / 64] == 'E')
		return ;
	map->map[map->py / 64][map->px / 64] = '0';
	mlx_put_image_to_window(map->mlx, map->win, map->space, map->px, map->py);
	map->py = map->py - 64;
	if (map->map[map->py / 64][map->px / 64] == 'C')
		map->nu_coin--;
	map->map[map->py / 64][map->px / 64] = 'P';
	mlx_put_image_to_window(map->mlx, map->win, map->space, map->px, map->py);
	mlx_put_image_to_window(map->mlx, map->win, map->player, map->px, map->py);
	map->p_move++;
	ft_printf("%d\n", map->p_move);
}

int	exit_game(int key, t_maps *map)
{
	if (key == 53)
		exit_me_please(map);
	if (key == 0)
		go_left(map);
	if (key == 1)
		go_down(map);
	if (key == 2)
		go_right(map);
	if (key == 13)
		go_up(map);
	return (0);
}
