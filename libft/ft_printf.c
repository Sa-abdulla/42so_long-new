/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:44:48 by sabdulla          #+#    #+#             */
/*   Updated: 2022/11/22 02:47:46 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_parse(va_list ptr, char c)
{
	if (c == 'c')
		return (ft_putchar_pt (va_arg (ptr, int)));
	if (c == 's')
		return (ft_putstr_pt (va_arg (ptr, char *)));
	if (c == 'd' || c == 'i')
		return (ft_print_number_pt (va_arg (ptr, int)));
	if (c == 'x' || c == 'X')
		return (ft_hex_pt (va_arg (ptr, unsigned long int), c));
	if (c == 'u')
		return (ft_putuint_pt (va_arg (ptr, unsigned int)));
	if (c == 'p')
		return (ft_ptr_pt (va_arg (ptr, unsigned long long)));
	if (c == '%')
		return (ft_putchar_pt ('%'));
	return (0);
}

int	ft_printf(char *str, ...)
{
	int		i;
	int		counter;
	va_list	ptr;

	i = 0;
	counter = 0;
	va_start (ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar_pt (str[i]);
			counter++;
		}
		else
		{
			counter += ft_parse (ptr, str[i + 1]);
			i += 1;
		}
		i++;
	}
	va_end (ptr);
	return (counter);
}
