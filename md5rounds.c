/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5rounds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:05:10 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/14 13:05:11 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

int g_m1[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
int g_m2[16] = {1, 6, 11, 0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12};
int g_m3[16] = {5, 8, 11, 14, 1, 4, 7, 10, 13, 0, 3, 6, 9, 12, 15, 2};
int g_m4[16] = {0, 7, 14, 5, 12, 3, 10, 1, 8, 15, 6, 13, 4, 11, 2, 9};

static inline void	md5round1(t_md5 *md)
{
	int				i;
	unsigned int	t;

	i = -1;
	while (++i < 16)
	{
		t = (md->a + F(md->b, md->c, md->d) + md->x[g_m1[i]] + g_r1[i]);
		t = md5rotate(t, g_rounds1[i]) + md->b;
		md->a = md->d;
		md->d = md->c;
		md->c = md->b;
		md->b = t;
	}
}

static inline void	md5round2(t_md5 *md)
{
	int				i;
	unsigned int	t;

	i = -1;
	while (++i < 16)
	{
		t = (md->a + G(md->b, md->c, md->d) + md->x[g_m2[i]] + g_r2[i]);
		t = md5rotate(t, g_rounds2[i]) + md->b;
		md->a = md->d;
		md->d = md->c;
		md->c = md->b;
		md->b = t;
	}
}

static inline void	md5round3(t_md5 *md)
{
	int				i;
	unsigned int	t;

	i = -1;
	while (++i < 16)
	{
		t = (md->a + H(md->b, md->c, md->d) + md->x[g_m3[i]] + g_r3[i]);
		t = md5rotate(t, g_rounds3[i]) + md->b;
		md->a = md->d;
		md->d = md->c;
		md->c = md->b;
		md->b = t;
	}
}

static inline void	md5round4(t_md5 *md)
{
	int				i;
	unsigned int	t;

	i = -1;
	while (++i < 16)
	{
		t = (md->a + I(md->b, md->c, md->d) + md->x[g_m4[i]] + g_r4[i]);
		t = md5rotate(t, g_rounds4[i]) + md->b;
		md->a = md->d;
		md->d = md->c;
		md->c = md->b;
		md->b = t;
	}
}

void				md5rounds(t_md5 *md)
{
	unsigned int	copy[4];

	copy[0] = md->a;
	copy[1] = md->b;
	copy[2] = md->c;
	copy[3] = md->d;
	md5round1(md);
	md5round2(md);
	md5round3(md);
	md5round4(md);
	md->a += copy[0];
	md->b += copy[1];
	md->c += copy[2];
	md->d += copy[3];
}
