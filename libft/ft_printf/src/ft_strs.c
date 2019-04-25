/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:43:12 by vdenysov          #+#    #+#             */
/*   Updated: 2018/01/19 11:43:13 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_writer(void *elem, size_t size)
{
	int			diff;
	long long	i;

	i = 0;
	while (32 - g_m.str_in < (int)size)
	{
		diff = 32 - g_m.str_in;
		ft_memcpy(&(g_m.str[g_m.str_in]), &(elem[i]), diff);
		size -= diff;
		i += diff;
		g_m.str_in += diff;
		g_m.total_l += diff;
		write(1, g_m.str, g_m.str_in);
		g_m.str_in = 0;
	}
	ft_memcpy(&(g_m.str[g_m.str_in]), &(elem[i]), size);
	g_m.str_in += size;
	g_m.total_l += size;
}

void	print_string(char *s)
{
	if (!s)
	{
		if (!(g_m.f & ZR))
			print_writer("(null)", 6);
		else
			while (g_m.length--)
				print_writer("0", 1);
	}
	else
		print_writer(s, (int)ft_strlen(s));
}

void	print_char(unsigned c)
{
	g_v.out = (g_m.f & LN || g_m.f & LN2) ? w_char_l(c) : 1;
	if ((g_m.pdg = g_m.length - g_v.out) < 0)
		g_m.pdg = 0;
	get_width(0);
	print_w_char(c, g_v.out, g_v.out);
	get_width(1);
}
