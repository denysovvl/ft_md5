/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:57:30 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/22 12:57:32 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void	md5read(t_md5 *md, char *input, int fd, t_flags *flag)
{
	int		ret;
	char	buf[64];

	md5init(md, "");
	md->mdname = input;
	while ((ret = read(fd, buf, 64)) > 0)
	{
		buf[ret] = '\0';
		md->input = buf;
		md->inputlen = ret;
		md->len += ret;
		if (ret < 64 && ret > 55)
		{
			md5update(md, buf);
			md->inputlen = 0;
		}
		md5update(md, buf);
	}
	md->inputlen = 0;
	if (md->len == 64 || md->len == 0)
		md5update(md, buf);
	md5print(md, flag);
}

void	md5string(t_md5 *md, char *av, t_flags *flag)
{
	md5init(md, av);
	md->isstr = 1;
	md5loop(md);
	md5print(md, flag);
}
