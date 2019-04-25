/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:43:22 by vdenysov          #+#    #+#             */
/*   Updated: 2018/01/19 11:43:24 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	itoa_printf(intmax_t n, int len)
{
	char		s[21];
	uintmax_t	tmp;

	tmp = ABS(n);
	while (tmp)
	{
		tmp /= 10;
		++len;
	}
	if ((n < 0 || g_m.f & PL || g_m.f & SP) && g_m.f & ZR)
		--g_m.prc;
	g_v.out = max(len, g_m.prc);
	if (n < 0 || g_m.f & PL || g_m.f & SP)
		++g_v.out;
	g_m.pdg = (g_v.out > g_m.length) ? 0 : g_m.length - g_v.out;
	get_width(0);
	tmp = ABS(n);
	itoa_base_fill(tmp, 10, s);
	(g_m.f & SP) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(g_m.f & PL && n >= 0) ? s[0] = '+' : 0;
	print_writer(s, g_v.out);
	get_width(1);
}

void	print_nbr(void)
{
	intmax_t	n;

	if (g_m.f & LN || g_m.f & LN2)
		n = (g_m.f & LN2) ? ((intmax_t)va_arg(g_v.ap, long long)) :
			((intmax_t)va_arg(g_v.ap, long));
	else if (g_m.f & SH || g_m.f & SH2)
		n = (g_m.f & SH2) ? (intmax_t)((char)va_arg(g_v.ap, int)) :
			(intmax_t)((short)va_arg(g_v.ap, int));
	else if (g_m.f & IM)
		n = (va_arg(g_v.ap, intmax_t));
	else if (g_m.f & ST)
		n = ((intmax_t)va_arg(g_v.ap, ssize_t));
	else
		n = ((intmax_t)va_arg(g_v.ap, int));
	(g_m.f & ZR) ? g_m.prc = g_m.length : 0;
	itoa_printf(n, 0);
}
