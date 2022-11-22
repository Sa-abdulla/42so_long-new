/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdulla <sabdulla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:58:10 by sabdulla          #+#    #+#             */
/*   Updated: 2022/02/23 20:42:59 by sabdulla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*m;
	t_list	*p;

	if (!lst)
		return (NULL);
	p = ft_lstnew(f(lst->content));
	if (p == NULL)
		return (NULL);
	m = p;
	while (lst->next)
	{
		lst = lst->next;
		p->next = ft_lstnew(f(lst->content));
		if (p->next == NULL)
		{
			ft_lstclear(&m, del);
			return (NULL);
		}
		p = p->next;
	}
	return (m);
}
