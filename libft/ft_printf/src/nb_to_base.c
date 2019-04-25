/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_to_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:18:39 by vdenysov          #+#    #+#             */
/*   Updated: 2018/01/29 15:18:40 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		nb_to_base(int base)
{
	uintmax_t	n;

	if (g_m.f & LN || g_m.f & LN2)
		n = (g_m.f & LN2) ? ((intmax_t)va_arg(g_v.ap, unsigned long long)) :
			((intmax_t)va_arg(g_v.ap, unsigned long));
	else if (g_m.f & SH || g_m.f & SH2)
		n = (g_m.f & SH2) ? (uintmax_t)((unsigned char)va_arg(g_v.ap, int))
			: (uintmax_t)((unsigned short)va_arg(g_v.ap, int));
	else if (g_m.f & IM)
		n = (va_arg(g_v.ap, uintmax_t));
	else if (g_m.f & ST)
		n = ((uintmax_t)va_arg(g_v.ap, size_t));
	else
		n = (uintmax_t)va_arg(g_v.ap, unsigned int);
	int_to_base(n, base);
}
