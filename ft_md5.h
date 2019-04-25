/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 19:41:02 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/04 19:42:31 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# include "libft/libft.h"
# include "ft_sha256.h"
# include "libft/ft_printf/include/ft_printf.h"

# include <unistd.h>
# include <fcntl.h>

# define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
# define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
# define H(x, y, z) ((x) ^ (y) ^ (z))
# define I(x, y, z) ((y) ^ ((x) | (~z)))
# define FNUM 6

typedef struct s_md5	t_md5;

struct					s_md5
{
	int					flag;
	int					isstr;
	char				*input;
	unsigned int		a;
	unsigned int		b;
	unsigned int		c;
	unsigned int		d;
	unsigned int		*x;
	unsigned int		len;
	unsigned char		buf[64];
	unsigned int		inputlen;
	char				*mdname;
};

unsigned int			md5rotate(unsigned int x, int n);
void					dispatcher(t_flags *flag, int ac, char **av, int i);
void					md5rounds(t_md5 *md);
void					md5init(t_md5 *md, char *input);
void					md5read(t_md5 *md, char *input, int fd, t_flags *flag);
void					md5loop(t_md5 *md);
void					md5print(t_md5 *md, t_flags *flag);
void					md5_start(t_flags *flag, int ac, char **av);
void					md5string(t_md5 *md, char *av, t_flags *flag);
void					md52hex(unsigned int data);
void					md5update(t_md5 *md, char *input);

void					parse_flags(t_flags *flag, int ac, char **av, int i);
void					stdinput(t_sha256 *s, t_md5 *m, int sn, t_flags *flag);
void					flaginit(t_flags *flag, int ac, char **av);

void					printserror(void);
void					printferror(char c);

int						check_func(char *av);

extern t_func					g_funclist[FNUM];

static unsigned long long	g_rounds1[16] =
{
	7, 12, 17, 22,
	7, 12, 17, 22,
	7, 12, 17, 22,
	7, 12, 17, 22
};

static unsigned long long	g_rounds2[16] =
{
	5, 9, 14, 20,
	5, 9, 14, 20,
	5, 9, 14, 20,
	5, 9, 14, 20
};

static unsigned long long	g_rounds3[16] =
{
	4, 11, 16, 23,
	4, 11, 16, 23,
	4, 11, 16, 23,
	4, 11, 16, 23
};

static unsigned long long	g_rounds4[16] =
{
	6, 10, 15, 21,
	6, 10, 15, 21,
	6, 10, 15, 21,
	6, 10, 15, 21
};

static unsigned int g_r1[16] =
{
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821
};

static unsigned int g_r2[16] =
{
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a
};

static unsigned int g_r3[16] =
{
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665
};

static unsigned int g_r4[16] =
{
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

#endif
