/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:54:21 by sabdulla          #+#    #+#             */
/*   Updated: 2022/11/22 02:45:39 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen_pt(int num)
{
	int	len;

	len = 0;
	if (!num)
		return (0);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_puthex_pt(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_puthex_pt(num / 16, format);
		ft_puthex_pt(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_pt(num + '0');
		else
		{
			if (format == 'x')
				ft_putchar_pt(num - 10 + 'a');
			else if (format == 'X')
				ft_putchar_pt(num + 10 + 'A');
		}
	}
}

int	ft_hex_pt(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_puthex_pt(num, format);
	return (ft_hexlen_pt(num));
}
