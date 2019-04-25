/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256rounds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:30:09 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/18 13:30:11 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha256.h"

static inline void		sha256round(t_sha256 *sha)
{
	int				i;
	unsigned int	s[6];

	i = -1;
	while (++i < 64)
	{
		s[0] = rotr(sha->a, 2) ^ rotr(sha->a, 13) ^ rotr(sha->a, 22);
		s[1] = (sha->a & sha->b) ^ (sha->a & sha->c) ^ (sha->b & sha->c);
		s[2] = s[0] + s[1];
		s[3] = rotr(sha->e, 6) ^ rotr(sha->e, 11) ^ rotr(sha->e, 25);
		s[4] = (sha->e & sha->f) ^ ((~sha->e) & sha->g);
		s[5] = sha->h + s[3] + s[4] + g_k[i] + sha->x[i];
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

static inline void		sha256words(t_sha256 *sha)
{
	int				i;
	unsigned int	s[8];

	i = 15;
	while (++i < 64)
	{
		s[0] = rotr(sha->x[i - 15], 7) ^ rotr(sha->x[i - 15], 18);
		s[0] = s[0] ^ (sha->x[i - 15] >> 3);
		s[1] = rotr(sha->x[i - 2], 17) ^ rotr(sha->x[i - 2], 19);
		s[1] = s[1] ^ (sha->x[i - 2] >> 10);
		sha->x[i] = sha->x[i - 16] + s[0] + sha->x[i - 7] + s[1];
	}
	sha256round(sha);
}

static inline void		sha256rounds(t_sha256 *sha)
{
	unsigned int	copy[8];

	copy[0] = sha->a;
	copy[1] = sha->b;
	copy[2] = sha->c;
	copy[3] = sha->d;
	copy[4] = sha->e;
	copy[5] = sha->f;
	copy[6] = sha->g;
	copy[7] = sha->h;
	sha256words(sha);
	sha->a += copy[0];
	sha->b += copy[1];
	sha->c += copy[2];
	sha->d += copy[3];
	sha->e += copy[4];
	sha->f += copy[5];
	sha->g += copy[6];
	sha->h += copy[7];
}

static inline void		sha256update2(t_sha256 *sha, char *input)
{
	int				i;

	i = -1;
	ft_bzero(sha->buf, 64 * sizeof(int));
	if (sha->inputlen >= 64)
		ft_memcpy(sha->buf, input, 64);
	else
	{
		ft_memcpy(sha->buf, input, sha->inputlen);
		ft_memset(sha->buf + sha->inputlen, 0x80, 1);
		sha->flag = 1;
	}
	sha->x = (unsigned int *)sha->buf;
	while (++i < 16)
		sha->x[i] = reverseendian(sha->x[i]);
	sha256rounds(sha);
}

void					sha256update(t_sha256 *sha, char *input)
{
	int				i;

	i = -1;
	if (sha->inputlen < 56)
	{
		ft_bzero(sha->buf, 64 * sizeof(int));
		ft_memcpy(sha->buf, input, sha->inputlen);
		if (!sha->flag)
			ft_memset(sha->buf + sha->inputlen, 0x80, 1);
		sha->x = (unsigned int *)sha->buf;
		while (++i < 16)
			sha->x[i] = reverseendian(sha->x[i]);
		sha->x[15] = sha->len * 8;
		sha256rounds(sha);
	}
	else
		sha256update2(sha, input);
}
