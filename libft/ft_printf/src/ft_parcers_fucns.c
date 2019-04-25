/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:33:23 by vdenysov          #+#    #+#             */
/*   Updated: 2018/01/19 12:33:25 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	get_prc(void)
{
	if (*g_m.fm > 48 && *g_m.fm < 58)
	{
		g_m.length = max(1, ft_atoi(g_m.fm));
		while (*g_m.fm > 47 && *g_m.fm < 58)
			++g_m.fm;
	}
	if (*g_m.fm == 46)
	{
		++g_m.fm;
		g_m.prc = max(ft_atoi(g_m.fm), 0);
		while (*g_m.fm > 47 && *g_m.fm < 58)
			++g_m.fm;
		g_m.f |= PRC;
	}
}

void	get_ptr(void)
{
	void	*pointer;

	pointer = va_arg(g_v.ap, void *);
	g_m.f &= ~SHP;
	g_m.length -= (g_m.f & ZR ? 2 : 0);
	g_m.pdg = (g_v.out > g_m.length - 3) ? 0 :
		g_m.length - 3 - g_v.out;
	g_m.f |= SHP;
	g_m.f |= PO;
	int_to_base((uintmax_t)pointer, 16);
}

void	get_spec(void)
{
	g_v.c = *g_m.fm;
	if (g_v.c == 's')
		(g_m.f & LN || g_m.f & LN2) ? \
		print_w_string() : print_string_h();
	else if (g_v.c == 'c' || g_v.c == 'C')
		print_char(va_arg(g_v.ap, unsigned));
	else if (ft_strchr("dDi", g_v.c))
		print_nbr();
	else if (g_v.c == 'S')
		print_w_string();
	else if (g_v.c == 'n')
		*va_arg(g_v.ap, int *) = g_m.total_l;
	else if (ft_strchr("oOuUbBxX", g_v.c))
		nb_to_base(char_all_iterator(".b..ou..x", g_v.c, -1) << 1);
	else if (g_v.c == 'p')
		get_ptr();
	else
		if_not_spec();
}

void	print_string_h(void)
{
	unsigned	*s;
	int			len;

	if (!(s = va_arg(g_v.ap, unsigned*)))
		print_string((char *)s);
	else
	{
		len = (int)(ft_strlen((char*)s));
		(g_m.f & PRC) ? len = min(g_m.prc, len) : 0;
		g_m.pdg = (g_m.length - len) > 0 ? (g_m.length - len) : 0;
		get_width(0);
		print_writer(s, len);
		get_width(1);
	}
}
