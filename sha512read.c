/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:57:07 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/22 12:57:08 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha512.h"

void	sha512read(t_sha512 *sha, char *input, int fd, t_flags *f)
{
	int		ret;
	char	buf[128];

	sha->mdname = input;
	while ((ret = read(fd, buf, 128)) > 0)
	{
		buf[ret] = '\0';
		sha->input = buf;
		sha->inputlen = ret;
		sha->len += ret;
		if (ret < 125 && ret > 111)
		{
			sha512update(sha, buf);
			sha->inputlen = 0;
		}
		sha512update(sha, buf);
	}
	sha->inputlen = 0;
	if (sha->len == 128 || sha->len == 0)
		sha512update(sha, buf);
	sha512print(sha, f);
}

void	sha512string(t_sha512 *sha, char *av, int shanum, t_flags *f)
{
	sha512init(sha, av, shanum);
	sha->isstr = 1;
	sha512loop(sha);
	sha512print(sha, f);
}
