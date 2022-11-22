/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:32:32 by sabdulla          #+#    #+#             */
/*   Updated: 2022/11/22 02:48:12 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_pt(int num, int *counter)
{
	if (num == -2147483648)
	{
		ft_putnbr_pt(num / 10, counter);
		ft_putchar_pt('8');
		(*counter)++;
	}
	else if (num < 0)
	{
		ft_putchar_pt('-');
		(*counter)++;
		ft_putnbr_pt(-num, counter);
	}
	else
	{
		if (num > 9)
		{
			ft_putnbr_pt(num / 10, counter);
		}
		ft_putchar_pt((num % 10) + 48);
		(*counter)++;
	}
}

int	ft_print_number_pt(int num)
{
	int	counter;

	counter = 0;
	ft_putnbr_pt(num, &counter);
	return (counter);
}
