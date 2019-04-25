/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:37:25 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/18 13:37:26 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

void	sha256read(t_sha256 *sha, char *input, int fd, t_flags *f)
{
	int		ret;
	char	buf[64];

	sha->mdname = input;
	while ((ret = read(fd, buf, 64)) > 0)
	{
		buf[ret] = '\0';
		sha->input = buf;
		sha->inputlen = ret;
		sha->len += ret;
		if (ret < 64 && ret > 55)
		{
			sha256update(sha, buf);
			sha->inputlen = 0;
		}
		sha256update(sha, buf);
	}
	sha->inputlen = 0;
	if (sha->len == 64 || sha->len == 0)
		sha256update(sha, buf);
	sha256print(sha, f);
}

void	sha256string(t_sha256 *sha, char *av, int shanum, t_flags *f)
{
	sha256init(sha, av, shanum);
	sha->isstr = 1;
	sha256loop(sha);
	sha256print(sha, f);
}
