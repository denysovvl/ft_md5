/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:16:09 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/14 13:16:11 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# include "libft/libft.h"

typedef struct s_sha256	t_sha256;
typedef struct s_func	t_func;
typedef struct s_flags	t_flags;

struct					s_flags
{
	int					q;
	int					r;
	int					p;
	char				*string;
};

struct					s_func
{
	char				*name;
	int					num;
	void				(*fptr)(t_flags *, int, char **);
};

struct					s_sha256
{
	int					flag;
	int					sha;
	int					isstr;
	unsigned int		a;
	unsigned int		b;
	unsigned int		c;
	unsigned int		d;
	unsigned int		e;
	unsigned int		f;
	unsigned int		g;
	unsigned int		h;
	unsigned int		word[8];
	unsigned int		*x;
	unsigned char		buf[64 * sizeof(int)];
	unsigned int		inputlen;
	unsigned int		len;
	char				*input;
	char				*mdname;
};

static unsigned int		g_k[64] =
{
	0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
	0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
	0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3,
	0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
	0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC,
	0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
	0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7,
	0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
	0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13,
	0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
	0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3,
	0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
	0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5,
	0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
	0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208,
	0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
};

unsigned int			rotr(unsigned int x, int n);
unsigned int			reverseendian(unsigned int value);
void					sha256init(t_sha256 *sha, char *input, int shanum);
void					sha256loop(t_sha256 *sha);
void					sha256print(t_sha256 *sha, t_flags *flag);
void					sha256update(t_sha256 *sha, char *input);
void					sha256read(t_sha256 *sha, char *in, int fd, t_flags *f);
void					sha256_start(t_flags *flag, int ac, char **av);
void					sha256string(t_sha256 *s, char *a, int sn, t_flags *f);

void					sha224_start(t_flags *flag, int ac, char **av);

#endif
