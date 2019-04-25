/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_char_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:15:44 by vdenysov          #+#    #+#             */
/*   Updated: 2018/01/29 15:15:45 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	w_char_l(unsigned wc)
{
	if (wc < 0x100)
		return (1);
	else if (wc < 0x1000)
		return (2);
	else if (wc < 0x10000)
		return (3);
	return (4);
}

size_t	w_string_l(unsigned *s)
{
	size_t	len;

	len = 0;
	while (*s != L'\0')
	{
		len += w_char_l(*s);
		++s;
	}
	return (len);
}
