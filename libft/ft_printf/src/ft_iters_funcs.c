/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:32:29 by vdenysov          #+#    #+#             */
/*   Updated: 2018/01/19 12:32:31 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	if_not_spec(void)
{
	if ((g_m.pdg = g_m.length - 1) > 0)
	{
		get_width(0);
		print_writer(g_m.fm, 1);
		get_width(1);
		return ;
	}
	print_writer(g_m.fm, 1);
}

int		char_iterator(char *s, int c, int i)
{
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}

int		char_all_iterator(char *s, int c, int i)
{
	while (s[++i])
		if (s[i] == c || s[i] == c + 32)
			return (i);
	return (-1);
}
