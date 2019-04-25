/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:12:13 by vdenysov          #+#    #+#             */
/*   Updated: 2017/11/16 18:12:14 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	if ((*alst)->next == NULL)
	{
		ft_lstdelone(alst, del);
		return ;
	}
	ft_lstdel(&(*alst)->next, del);
	ft_lstdelone(alst, del);
}
