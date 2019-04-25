/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:57:16 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/22 12:57:18 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha512.h"

unsigned long int	rotr64(unsigned long int x, int n)
{
	return (x >> n) | (x << ((sizeof(x) << 3) - n));
}

unsigned long int	convertendian(unsigned long int val)
{
	return ((val & 0x00000000000000ff) << 56 |\
			(val & 0x000000000000ff00) << 40 |\
			(val & 0x0000000000ff0000) << 24 |\
			(val & 0x00000000ff000000) << 8 |\
			(val & 0x000000ff00000000) >> 8 |\
			(val & 0x0000ff0000000000) >> 24 |\
			(val & 0x00ff000000000000) >> 40 |\
			(val & 0xff00000000000000) >> 56);
}

static inline void	sha512init2(t_sha512 *sha)
{
	sha->a = 0xcbbb9d5dc1059ed8;
	sha->b = 0x629a292a367cd507;
	sha->c = 0x9159015a3070dd17;
	sha->d = 0x152fecd8f70e5939;
	sha->e = 0x67332667ffc00b31;
	sha->f = 0x8eb44a8768581511;
	sha->g = 0xdb0c2e0d64f98fa7;
	sha->h = 0x47b5481dbefa4fa4;
}

void				sha512init(t_sha512 *sha, char *input, int shanum)
{
	ft_bzero(sha->buf, 80 * sizeof(unsigned long int));
	if (shanum == 512)
	{
		sha->a = 0x6a09e667f3bcc908;
		sha->b = 0xbb67ae8584caa73b;
		sha->c = 0x3c6ef372fe94f82b;
		sha->d = 0xa54ff53a5f1d36f1;
		sha->e = 0x510e527fade682d1;
		sha->f = 0x9b05688c2b3e6c1f;
		sha->g = 0x1f83d9abfb41bd6b;
		sha->h = 0x5be0cd19137e2179;
	}
	else
		sha512init2(sha);
	sha->input = input;
	sha->inputlen = ft_strlen(input);
	sha->len = sha->inputlen;
	sha->flag = 0;
	sha->sha = shanum;
	sha->isstr = 0;
	sha->mdname = input;
}

void				sha512loop(t_sha512 *sha)
{
	int	ptr;

	ptr = 0;
	while (sha->inputlen >= 128)
	{
		sha512update(sha, sha->input + ptr);
		sha->inputlen -= 128;
		ptr += 128;
	}
	if (sha->inputlen >= 112)
	{
		sha512update(sha, sha->input + ptr);
		ptr += sha->inputlen;
		sha->inputlen = 0;
	}
	sha512update(sha, sha->input + ptr);
}
