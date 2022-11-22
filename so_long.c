/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:28:47 by sabdulla          #+#    #+#             */
/*   Updated: 2022/11/22 16:35:50 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	my_free(t_maps *map)
{
	int	i;

	i = 0;
	if (map->map[i])
	{
		while (map->map[i])
		{
			free(map->map[i]);
			map->map[i] = NULL;
			i++;
		}
		free(map->map);
	}
}

void	open_xpm(t_maps *map)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	map->player = NULL;
	map->wall_p = NULL;
	map->coin = NULL;
	map->exit = NULL;
	map->space = NULL;
	map->player = mlx_xpm_file_to_image(map->mlx, "./img/mario.xpm", &w, &h);
	map->wall_p = mlx_xpm_file_to_image(map->mlx, "./img/wall.xpm", &w, &h);
	map->coin = mlx_xpm_file_to_image(map->mlx, "./img/collect.xpm", &w, &h);
	map->exit = mlx_xpm_file_to_image(map->mlx, "./img/exit.xpm", &w, &h);
	map->space = mlx_xpm_file_to_image(map->mlx, "./img/bg.xpm", &w, &h);
	if (!map->player || !map->wall_p || !map->coin || !map->exit || !map->space)
	{
		exit(0);
	}
}

void	exit_me_please(t_maps *map)
{
	mlx_destroy_image(map->mlx, map->coin);
	mlx_destroy_image(map->mlx, map->exit);
	mlx_destroy_image(map->mlx, map->space);
	mlx_destroy_image(map->mlx, map->wall_p);
	mlx_destroy_window(map->mlx, map->win);
	my_free(map);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_maps	map;

	if (ac != 2)
	{
		ft_printf ("ERROR: wrong number of arguments \n");
		return (EXIT_FAILURE);
	}
	init_struct(&map);
	if (ft_check_exten(av[1], &map) == 0)
	{
		ft_printf ("ERROR: wrong extension file \n");
		return (EXIT_FAILURE);
	}
	if (ft_read_maps(av[1], &map) == 0
		|| check_valid_map(&map) == 0 || check_valid_coin(&map) == 0)
	{
		ft_printf ("ERROR: invalid map/path \n");
		return (EXIT_FAILURE);
	}
	start_game(&map);
	return (0);
}
