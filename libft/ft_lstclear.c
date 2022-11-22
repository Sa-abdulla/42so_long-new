/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:56:23 by sabdulla          #+#    #+#             */
/*   Updated: 2022/02/23 20:42:39 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ls;

	if (!*lst)
		return ;
	while (*lst)
	{
		ls = *lst;
		*lst = (*lst)->next;
		del(ls->content);
		free(ls);
	}
	*lst = NULL;
}
