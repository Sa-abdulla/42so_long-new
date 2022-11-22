# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 19:29:50 by sabdulla          #+#    #+#              #
#    Updated: 2022/11/22 14:29:29 by sabdulla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= so_long.c read_maps.c check_coin.c check_maps.c check_path.c \
		print_maps.c moves.c strt_clos.c

OBJS	= $(SRC:.c=.o)

NAME	= so_long

CFLAGS	= -Wall -Werror -Wextra -g3

RM		= rm -f

mlx		= ./mlx/libmlx.a

LIBFT	= cd libft && make

LIBFT_A	= libft/libft.a

$(NAME)	: $(OBJS)
		$(LIBFT)
		make -C ./mlx
		gcc $(CFLAGS) -o so_long $(OBJS) $(LIBFT_A) $(mlx) -framework OpenGL -framework AppKit

all	: $(NAME)

clean :
		$(RM) $(OBJS)
		$(RM) $(LIBFT_A)
		make clean -C mlx
		make clean -C libft

fclean : clean
		$(RM) $(NAME)

re : fclean all