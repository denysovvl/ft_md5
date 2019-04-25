/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:54:53 by vdenysov          #+#    #+#             */
/*   Updated: 2017/11/16 18:54:56 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (NULL);
	if (lst->next == NULL)
	{
		new = (*f)(lst);
		return (new);
	}
	new = (*f)(lst);
	new->next = ft_lstmap(lst->next, f);
	return (new);
}
