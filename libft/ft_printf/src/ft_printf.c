/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:43:00 by vdenysov          #+#    #+#             */
/*   Updated: 2018/01/19 11:43:02 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		get_width(int n)
{
	if (!g_m.pdg)
		return ;
	g_v.c = 32 | (g_m.f & ZR);
	if (!n && !(g_m.f & MN))
		while (g_m.pdg--)
			print_writer(&g_v.c, 1);
	else if (n && (g_m.f & MN))
		while (g_m.pdg--)
			print_writer(&g_v.c, 1);
}

void		get_all_flags(void)
{
	while ((g_v.iter = char_iterator("# +-0*", *g_m.fm, -1)) \
		> -1 && ++g_m.fm)
		g_m.f |= (1 << g_v.iter);
	((g_m.f & MN) && !(g_m.f & WC)) ? g_m.f &= ~ZR : 0;
	(g_m.f & PL) ? g_m.f &= ~SP : 0;
	if (g_m.f & WC)
	{
		g_m.f &= ~WC;
		if ((g_v.n = (int)va_arg(g_v.ap, int)) < 0)
		{
			g_m.f |= MN;
			g_v.n = -g_v.n;
		}
		else
			g_m.f &= ~MN;
		if (!(g_m.f & PRC))
			g_m.length = g_v.n;
		else
		{
			g_m.prc = (!(g_m.f & MN)) ? g_v.n : 0;
			g_m.f = (!g_v.n) ? g_m.f | PRC : \
			g_m.f & ~PRC;
		}
	}
}

static void	get_format(void)
{
	g_m.f &= 0x0;
	g_m.length &= 0x0;
	g_m.prc &= 0x0;
	g_m.prc |= 0x1;
	get_all_flags();
	get_prc();
	while (1)
	{
		if (*g_m.fm == 'l')
			g_m.f |= (*(g_m.fm + 1) == 'l' && ++g_m.fm) ? LN2 : LN;
		else if (*g_m.fm == 'h')
			g_m.f |= (*(g_m.fm + 1) == 'h' && ++g_m.fm) ? SH2 : SH;
		else if (*g_m.fm == 'j')
			g_m.f |= IM;
		else if (*g_m.fm == 'z')
			g_m.f |= ST;
		else
			break ;
		++g_m.fm;
	}
	get_all_flags();
	(g_m.f & PL) ? g_m.f &= ~SP : 0;
	if (ft_strchr("CDSUOBX", *g_m.fm))
		g_m.f |= (*g_m.fm != 'X') ? LN : UL;
	get_spec();
}

int			ft_printf(const char *fm, ...)
{
	ft_bzero(&g_m, sizeof(g_m));
	g_m.fm = (char*)fm;
	va_start(g_v.ap, fm);
	while (*g_m.fm)
	{
		if (*g_m.fm == '%')
		{
			g_m.fm++;
			if (!*g_m.fm)
				break ;
			get_format();
		}
		else
			print_writer(g_m.fm, 1);
		++g_m.fm;
	}
	write(1, g_m.str, g_m.str_in);
	va_end(g_v.ap);
	return (g_m.total_l);
}
