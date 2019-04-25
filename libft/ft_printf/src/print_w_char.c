/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_w_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:32:05 by vdenysov          #+#    #+#             */
/*   Updated: 2018/01/29 15:32:08 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_w_char(unsigned int chr, int wlen, int blen)
{
	char	str[4];

	if (blen <= wlen && blen <= MB_CUR_MAX)
	{
		if (blen == 1)
			str[0] = chr;
		else
		{
			if (blen == 2)
				str[0] = ((chr & 1984) >> 6) | 192;
			else
			{
				if (blen == 3)
					str[0] = ((chr >> 12) & 15) | 224;
				else
				{
					str[0] = ((chr >> 18) & 7) | 240;
					str[1] = ((chr >> 12) & 63) | 128;
				}
				str[blen - 2] = ((chr >> 6) & 63) | 128;
			}
			str[blen - 1] = (chr & 63) | 128;
		}
		print_writer(str, blen);
	}
}
