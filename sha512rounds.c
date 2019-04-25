/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512rounds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:56:32 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/22 12:56:34 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"
#include "ft_sha512.h"

static inline void		sha512round(t_sha512 *sha)
{
	int	i;
	U64	s[6];

	i = -1;
	while (++i < 80)
	{
		s[0] = rotr64(sha->a, 28) ^ rotr64(sha->a, 34) ^ rotr64(sha->a, 39);
		s[1] = (sha->a & sha->b) ^ (sha->a & sha->c) ^ (sha->b & sha->c);
		s[2] = s[0] + s[1];
		s[3] = rotr64(sha->e, 14) ^ rotr64(sha->e, 18) ^ rotr64(sha->e, 41);
		s[4] = (sha->e & sha->f) ^ ((~sha->e) & sha->g);
		s[5] = sha->h + s[3] + s[4] + g_k2[i] + sha->x[i];
		sha->h = sha->g;
		sha->g = sha->f;
		sha->f = sha->e;
		sha->e = sha->d + s[5];
		sha->d = sha->c;
		sha->c = sha->b;
		sha->b = sha->a;
		sha->a = s[5] + s[2];
	}
}

static inline void		sha512words(t_sha512 *sha)
{
	int	i;
	U64	s[8];

	i = 15;
	while (++i < 80)
	{
		s[0] = rotr64(sha->x[i - 15], 1) ^ rotr64(sha->x[i - 15], 8);
		s[0] = s[0] ^ (sha->x[i - 15] >> 7);
		s[1] = rotr64(sha->x[i - 2], 19) ^ rotr64(sha->x[i - 2], 61);
		s[1] = s[1] ^ (sha->x[i - 2] >> 6);
		sha->x[i] = sha->x[i - 16] + s[0] + sha->x[i - 7] + s[1];
	}
	sha512round(sha);
}

static inline void		sha512rounds(t_sha512 *sha)
{
	unsigned long int copy[8];

	copy[0] = sha->a;
	copy[1] = sha->b;
	copy[2] = sha->c;
	copy[3] = sha->d;
	copy[4] = sha->e;
	copy[5] = sha->f;
	copy[6] = sha->g;
	copy[7] = sha->h;
	sha512words(sha);
	sha->a += copy[0];
	sha->b += copy[1];
	sha->c += copy[2];
	sha->d += copy[3];
	sha->e += copy[4];
	sha->f += copy[5];
	sha->g += copy[6];
	sha->h += copy[7];
}

static inline void		sha512update2(t_sha512 *sha, char *input)
{
	int	i;

	i = -1;
	ft_bzero(sha->buf, 80 * sizeof(unsigned long int));
	if (sha->inputlen >= 128)
		ft_memcpy(sha->buf, input, 128);
	else
	{
		ft_memcpy(sha->buf, input, sha->inputlen);
		ft_memset(sha->buf + sha->inputlen, 0x80, 1);
		sha->flag = 1;
	}
	sha->x = (unsigned long int *)sha->buf;
	while (++i < 16)
		sha->x[i] = convertendian(sha->x[i]);
	sha512rounds(sha);
}

void					sha512update(t_sha512 *sha, char *input)
{
	int	i;

	i = -1;
	if (sha->inputlen < 112)
	{
		ft_bzero(sha->buf, 80 * sizeof(unsigned long int));
		ft_memcpy(sha->buf, input, sha->inputlen);
		if (!sha->flag)
			ft_memset(sha->buf + sha->inputlen, 0x80, 1);
		sha->x = (unsigned long int *)sha->buf;
		while (++i < 16)
			sha->x[i] = convertendian(sha->x[i]);
		sha->x[15] = sha->len * 8;
		sha512rounds(sha);
	}
	else
		sha512update2(sha, input);
}
