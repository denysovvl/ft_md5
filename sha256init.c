/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:17:05 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/18 13:17:06 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

unsigned int			rotr(unsigned int x, int n)
{
	return (x >> n) | (x << (32 - n));
}

unsigned int			reverseendian(unsigned int value)
{
	return (value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 | \
	(value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24;
}

static inline void		sha224init2(t_sha256 *sha)
{
	sha->a = 0xC1059ED8;
	sha->b = 0x367CD507;
	sha->c = 0x3070DD17;
	sha->d = 0xF70E5939;
	sha->e = 0xFFC00B31;
	sha->f = 0x68581511;
	sha->g = 0x64F98FA7;
	sha->h = 0xBEFA4FA4;
}

void					sha256init(t_sha256 *sha, char *input, int shanum)
{
	ft_bzero(sha->buf, 64 * sizeof(int));
	if (shanum == 256)
	{
		sha->a = 0x6A09E667;
		sha->b = 0xBB67AE85;
		sha->c = 0x3C6EF372;
		sha->d = 0xA54FF53A;
		sha->e = 0x510E527F;
		sha->f = 0x9B05688C;
		sha->g = 0x1F83D9AB;
		sha->h = 0x5BE0CD19;
	}
	else
		sha224init2(sha);
	sha->input = input;
	sha->inputlen = ft_strlen(input);
	sha->len = sha->inputlen;
	sha->flag = 0;
	sha->sha = shanum;
	sha->isstr = 0;
	sha->mdname = input;
}

void					sha256loop(t_sha256 *sha)
{
	int ptr;

	ptr = 0;
	while (sha->inputlen >= 64)
	{
		sha256update(sha, sha->input + ptr);
		sha->inputlen -= 64;
		ptr += 64;
	}
	if (sha->inputlen >= 56)
	{
		sha256update(sha, sha->input + ptr);
		ptr += sha->inputlen;
		sha->inputlen = 0;
	}
	sha256update(sha, sha->input + ptr);
}
