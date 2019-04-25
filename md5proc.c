/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5proc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 16:41:54 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/16 16:41:56 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void	md52hex(unsigned int data)
{
	int dec[4];
	int i;

	i = 4;
	dec[0] = ((data & 0xFF000000) >> 24);
	dec[1] = ((data & 0xFF0000) >> 16);
	dec[2] = ((data & 0xFF00) >> 8);
	dec[3] = ((data & 0xFF));
	while (--i >= 0)
		ft_printf("%02x", dec[i]);
}

void	md5update(t_md5 *md, char *input)
{
	if (md->inputlen < 56)
	{
		ft_bzero(md->buf, 64);
		ft_memcpy(md->buf, input, md->inputlen);
		if (!md->flag)
			ft_memset(md->buf + md->inputlen, 0x80, 1);
		md->x = (unsigned int *)md->buf;
		*(md->x + 14) = md->len * 8;
		md5rounds(md);
	}
	else
	{
		ft_bzero(md->buf, 64);
		if (md->inputlen >= 64)
			ft_memcpy(md->buf, input, 64);
		else
		{
			ft_memcpy(md->buf, input, md->inputlen);
			ft_memset(md->buf + md->inputlen, 0x80, 1);
			md->flag = 1;
		}
		md->x = (unsigned int *)md->buf;
		md5rounds(md);
	}
}

void	md5loop(t_md5 *md)
{
	int ptr;

	ptr = 0;
	while (md->inputlen >= 64)
	{
		md5update(md, md->input + ptr);
		md->inputlen -= 64;
		ptr += 64;
	}
	if (md->inputlen >= 56)
	{
		md5update(md, md->input + ptr);
		ptr += md->inputlen;
		md->inputlen = 0;
	}
	md5update(md, md->input + ptr);
}
