/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:22:58 by vdenysov          #+#    #+#             */
/*   Updated: 2018/01/29 15:22:59 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		int_to_base(uintmax_t n, int b)
{
	uintmax_t	tmp;
	char		s[21];
	int			ext;

	g_v.out = 0;
	tmp = n;
	while (tmp && ++g_v.out)
		tmp /= b;
	(g_m.f & ZR) ? g_m.prc = g_m.length : 0;
	ext = (g_v.out >= g_m.prc) ? 0 : 1;
	g_v.out = max(g_m.prc, g_v.out);
	((g_m.f & SHP) && b == 8 && !ext) ? --g_m.length : 0;
	((g_m.f & SHP) && b == 8 && !n && (g_m.f & PRC)) ?
	++g_v.out : 0;
	((g_m.f & SHP) && b == 16 && !(g_m.f & ZR)) ? g_m.length -= 2 : 0;
	g_m.pdg = max(0, (g_m.length - g_v.out));
	get_width(0);
	if ((n || (g_m.f & PO))
		&& (g_m.f & SHP) && ((b == 8 && !ext) || (b == 16)))
		print_writer("0", 1);
	if ((n || (g_m.f & PO)) && (g_m.f & SHP) && b == 16)
		print_writer((g_m.f & UL) ? "X" : "x", 1);
	itoa_base_fill(n, b, s);
	print_writer(s, g_v.out);
	get_width(1);
}
