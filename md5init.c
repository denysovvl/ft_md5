/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 14:08:25 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/14 14:08:26 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

unsigned int	md5rotate(unsigned int x, int n)
{
	return (x << n) | (x >> (32 - n));
}

void			md5init(t_md5 *md, char *input)
{
	ft_bzero(md->buf, 64);
	md->mdname = input;
	md->input = input;
	md->inputlen = ft_strlen(input);
	md->len = md->inputlen;
	md->a = 0x67452301;
	md->b = 0xefcdab89;
	md->c = 0x98badcfe;
	md->d = 0x10325476;
	md->flag = 0;
	md->isstr = 0;
}

int				check_func(char *av)
{
	int				ok;
	int				i;

	ok = 0;
	i = -1;
	while (++i < FNUM)
		if (!ft_strcmp(av, g_funclist[i].name))
			ok = 1;
	if (!ok)
	{
		ft_printf("Error: invalid command.\nStandard commands:\n");
		ft_printf("md5\nsha224\nsha256\nsha384\nsha512\n");
		return (0);
	}
	return (1);
}
