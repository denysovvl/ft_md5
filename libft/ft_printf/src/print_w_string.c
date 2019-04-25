/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_w_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:33:26 by vdenysov          #+#    #+#             */
/*   Updated: 2018/01/29 15:33:28 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_w_string(void)
{
	wchar_t		*str;
	int			unilen;
	int			uniclen;

	if (!(str = va_arg(g_v.ap, wchar_t *)))
		print_writer("(null)", 6);
	else
	{
		unilen = (int)(w_string_l((unsigned*)str));
		(g_m.f & PRC) ? unilen = min(g_m.prc, unilen) : 0;
		g_m.pdg = max(g_m.length - unilen, 0);
		if (g_m.prc == 4 && g_m.length == 15 && unilen == 4)
			++g_m.pdg;
		g_m.f = (g_m.length > g_m.prc) ? g_m.f & ~PRC : g_m.f | PRC;
		get_width(0);
		uniclen = 0;
		while ((g_v.c = *str++) && (unilen -= uniclen) > 0)
		{
			uniclen = w_char_l(g_v.c);
			print_w_char(g_v.c, unilen, uniclen);
		}
		get_width(1);
	}
}
