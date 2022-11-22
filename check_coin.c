/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:09:48 by sabdulla          #+#    #+#             */
/*   Updated: 2022/11/21 23:33:25 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	exist_coin(t_maps *map, int y, int x)
{
	if (map->map[y][x] == '1' || map->hash_map[y][x] == 1)
		return (0);
	return (1);
}

int	check_ncoin(t_maps *map, int y, int x)
{
	if (map->map[y][x] == 'C')
	{
		map->nu_coin++;
		if (map->nu_coin == map->c)
			return (1);
	}
	map->hash_map[y][x] = 1;
	if (exist_coin(map, y, x - 1) == 1)
		if (check_ncoin(map, y, x - 1) == 1)
			return (1);
	if (exist_coin(map, y, x + 1) == 1)
		if (check_ncoin(map, y, x + 1) == 1)
			return (1);
	if (exist_coin(map, y + 1, x) == 1)
		if (check_ncoin(map, y + 1, x) == 1)
			return (1);
	if (exist_coin(map, y - 1, x) == 1)
		if (check_ncoin(map, y - 1, x) == 1)
			return (1);
	return (0);
}

int	check_valid_coin(t_maps *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < 254)
	{
		x = 0;
		while (x < 254)
		{
			map->hash_map[y][x] = 0;
			x++;
		}
		y++;
	}
	map->nu_coin = 0;
	if (check_ncoin(map, map->py, map->px) == 0)
		return (0);
	return (1);
}
