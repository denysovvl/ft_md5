/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:53:28 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/22 12:53:29 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "ft_sha256.h"
#include "ft_sha512.h"

void	printserror(void)
{
	ft_printf("md5: option requires an argument -- s\n");
	ft_printf("usage: md5 [-pqr] [-s string] [files ...]\n");
	exit(0);
}

void	printferror(char c)
{
	ft_printf("illegal option -- %c\n", c);
	ft_printf("usage: md5 [-pqr] [-s string] [files ...]\n");
	exit(0);
}

void	sha512print(t_sha512 *sha, t_flags *flag)
{
	char	s;

	s = '\0';
	if (flag && !flag->q && !flag->p)
	{
		if (sha->isstr == 1)
			s = '\"';
		if (sha->mdname && !flag->r && s == '\0')
			ft_printf("SHA%d(%s)= ", sha->sha, sha->mdname);
		else if (sha->mdname && !flag->r && s == '\"')
			ft_printf("SHA%d(%c%s%c)= ", sha->sha, s, sha->mdname, s);
	}
	else if (flag && flag->p)
		ft_printf("%s", sha->input);
	ft_printf("%016lx%016lx%016lx%016lx", sha->a, sha->b, sha->c, sha->d);
	ft_printf("%016lx%016lx", sha->e, sha->f);
	if (sha->sha == 512)
		ft_printf("%016lx%016lx", sha->g, sha->h);
	if (flag->r && !flag->q && !flag->p)
		ft_printf(" %c%s%c", s, sha->mdname, s);
	ft_printf("\n");
}

void	sha256print(t_sha256 *sha, t_flags *flag)
{
	char	s;

	s = '\0';
	if (flag && !flag->q && !flag->p)
	{
		if (sha->isstr == 1)
			s = '\"';
		if (sha->mdname && !flag->r && s == '\0')
			ft_printf("SHA%d(%s)= ", sha->sha, sha->mdname);
		else if (sha->mdname && !flag->r && s == '\"')
			ft_printf("SHA%d(%c%s%c)= ", sha->sha, s, sha->mdname, s);
	}
	else if (flag && flag->p)
		ft_printf("%s", sha->input);
	ft_printf("%x%x%x%x", sha->a, sha->b, sha->c, sha->d);
	ft_printf("%x%x%x", sha->e, sha->f, sha->g);
	if (sha->sha == 256)
		ft_printf("%x", sha->h);
	if (flag->r && !flag->q && !flag->p)
		ft_printf(" %c%s%c", s, sha->mdname, s);
	ft_printf("\n");
}

void	md5print(t_md5 *md, t_flags *flag)
{
	char	s;

	s = '\0';
	if (flag && !flag->q && !flag->p)
	{
		if (md->isstr == 1)
			s = '\"';
		if (md->mdname && !flag->r && s == '\0')
			ft_printf("MD5 (%s) = ", md->mdname);
		else if (md->mdname && !flag->r && s == '\"')
			ft_printf("MD5 (%c%s%c) = ", s, md->mdname, s);
	}
	else if (flag && flag->p)
		ft_printf("%s", md->input);
	md52hex(md->a);
	md52hex(md->b);
	md52hex(md->c);
	md52hex(md->d);
	if (flag->r && !flag->q && !flag->p)
		ft_printf(" %c%s%c", s, md->mdname, s);
	ft_printf("\n");
}
