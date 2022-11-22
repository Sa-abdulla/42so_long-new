/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:38:48 by sabdulla          #+#    #+#             */
/*   Updated: 2022/11/21 23:33:38 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	check_tops(t_maps *map)
{
	int	i;

	i = 0;
	while (i < map->w)
	{
		if (map->map[0][i] != '1')
			return (0);
		if (map->map[map->h - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_sides(t_maps *map)
{
	int	i;

	i = 0;
	while (i < map->h)
	{
		if (map->map[i][0] != '1')
			return (0);
		if (map->map[i][map->w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_char(char c)
{
	if (c == 'P' || c == 'C' || c == 'E' || c == '0' || c == '1')
		return (0);
	return (1);
}

void	player_p(t_maps *map, int i, int j)
{
	map->px = j;
	map->py = i;
	map->p++;
}

int	check_char(t_maps *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i] != 0)
	{
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
				player_p(map, i, j);
			if (map->map[i][j] == 'C')
				map->c++;
			if (map->map[i][j] == 'E')
				map->e++;
			if (valid_char(map->map[i][j]) == 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (map->e != 1 || map->p != 1 || map->c < 1)
		return (0);
	return (1);
}
