/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:30:06 by sabdulla          #+#    #+#             */
/*   Updated: 2022/11/22 02:41:57 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct mp{
	char	**map;
	char	*files;
	int		weidth;
	int		height;
	int		p;
	int		px;
	int		py;
	int		e;
	int		c;
	int		nu_coin;
	int		path;
	int		wall;
	int		h;
	int		w;
	int		exit_flag;
	int		p_move;
	int		hash_map[255][255];
	void	*mlx;
	void	*win;
	void	*player;
	void	*wall_p;
	void	*coin;
	void	*exit;
	void	*space;
}	t_maps;

int		check_char(t_maps *map);
int		check_tops(t_maps *map);
int		check_sides(t_maps *map);
int		map_split(char *st, t_maps *map);
int		check_all(char *st, t_maps *map);
int		ft_check_exten(char *st, t_maps *map);
int		ft_read_maps(char *str, t_maps *map);
int		check_valid_coin(t_maps *map);
int		check_valid_map(t_maps *map);
int		check_nav(t_maps *map, int x, int y);
int		exit_game(int key, t_maps *map);
void	init_struct(t_maps *map);
void	go_up(t_maps *map);
void	go_right(t_maps *map);
void	go_down(t_maps *map);
void	go_left(t_maps *map);
void	start_game(t_maps *map);
void	print_map(t_maps *map);
void	put_player(t_maps *map, int i, int j);
void	put_exit(t_maps *map, int i, int j);
void	put_coin(t_maps *map, int i, int j);
void	exit_me_please(t_maps *map);
void	open_xpm(t_maps *map);
void	my_free(t_maps *map);
#endif