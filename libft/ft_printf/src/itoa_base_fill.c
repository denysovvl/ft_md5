/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:28:33 by vdenysov          #+#    #+#             */
/*   Updated: 2018/01/29 15:28:35 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	itoa_base_fill(uintmax_t tmp, int b, char s[32])
{
	int		len;

	if (tmp && !(g_m.f & PO) && (g_m.f & ZR) \
		&& (g_m.f & SHP) &&
	b == 16 && !(g_m.f & LN2) && g_v.out > 3)
		g_v.out -= 2;
	len = g_v.out;
	g_v.c = 'a' - 10 - ((g_m.f & UL) >> 1);
	while (len--)
	{
		s[len] = tmp % b + ((tmp % b < 10) ? '0' : g_v.c);
		tmp /= b;
	}
	(g_m.f & PRC && g_m.f & ZR) ? s[0] = ' ' : 0;
}
