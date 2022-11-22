/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:54:24 by sabdulla          #+#    #+#             */
/*   Updated: 2022/11/22 02:46:28 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptrlen_pt(int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_putptr_pt(unsigned long long num)
{
	if (num >= 16)
	{
		ft_putptr_pt(num / 16);
		ft_putptr_pt(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar_pt(num + '0');
		else
			ft_putchar_pt(num - 10 + 'a');
	}
}

int	ft_ptr_pt(unsigned long long ptr)
{
	int	print_ptr;

	print_ptr = 0;
	print_ptr += write(1, "0x", 2);
	if (ptr == 0)
		print_ptr += write(1, "0", 1);
	else
	{
		ft_putptr_pt(ptr);
		print_ptr += ft_ptrlen_pt(ptr);
	}
	return (print_ptr);
}
