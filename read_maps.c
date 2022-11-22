/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:41:08 by sabdulla          #+#    #+#             */
/*   Updated: 2022/11/22 16:29:32 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	init_struct(t_maps *map)
{
	map->files = 0;
	map->p = 0;
	map->e = 0;
	map->c = 0;
	map->map = 0;
}

int	map_split(char *st, t_maps *map)
{
	int	i;

	i = 0;
	map->map = ft_split(st, '\n');
	map->w = ft_strlen(map->map[0]);
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != map->w)
			return (0);
		i++;
	}
	map->h = i;
	return (1);
}

int	check_all(char *st, t_maps *map)
{
	if (!*st)
		return (0);
	if (!map_split(st, map) || !check_tops(map)
		|| !check_sides(map) || !check_char(map) || !check_valid_map(map))
		return (0);
	return (1);
}

int	ft_check_exten(char *st, t_maps *map)
{
	int	i;

	i = 0;
	map->files = st;
	if (map->files[0] == '.' || ft_strlen(map->files) < 5)
		return (0);
	while (st[i] != '\0')
		i++;
	i--;
	if (!(map->files[i] == 'r' && map->files[i - 1] == 'e'
			&& map->files[i - 2] == 'b' && map->files[i - 3] == '.'))
		return (0);
	return (1);
}

int	ft_read_maps(char *str, t_maps *map)
{
	int		fd;
	char	*st;
	int		err;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	st = ft_strdup("");
	str = get_next_line(fd);
	while (str)
	{
		st = ft_strjoin_mod(st, str);
		free(str);
		str = get_next_line(fd);
	}
	err = check_all(st, map);
	if (map->w >= 100 || map->h >= 100)
	{
		ft_printf ("ERROR: big map \n");
		my_free(map);
		exit(EXIT_FAILURE);
	}
	return (err);
}
