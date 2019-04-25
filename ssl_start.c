/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:53:14 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/22 12:53:15 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "ft_sha256.h"
#include "ft_sha512.h"

void	md5_start(t_flags *flag, int ac, char **av)
{
	int			fd;
	int			i;
	t_md5		md;

	i = 1;
	if (flag->p)
		stdinput(NULL, &md, 0, flag);
	while ((++i < ac) && (av[i][0] == '-'))
		if (!ft_strcmp(av[i], "-s"))
			md5string(&md, av[i++ + 1], flag);
	while (i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
			ft_printf("md5: %s: No such file or directory\n", av[i]);
		else
			md5read(&md, av[i], fd, flag);
		i++;
	}
}

void	sha256_start(t_flags *flag, int ac, char **av)
{
	int			fd;
	int			i;
	t_sha256	sha;

	i = 1;
	if (flag->p)
		stdinput(&sha, NULL, 256, flag);
	while ((++i < ac) && (av[i][0] == '-'))
		if (!ft_strcmp(av[i], "-s"))
			sha256string(&sha, av[i++ + 1], 256, flag);
	while (i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
			ft_printf("%s: No such file or directory\n", av[i]);
		else
		{
			sha256init(&sha, "", 256);
			sha256read(&sha, av[i], fd, flag);
		}
		i++;
	}
}

void	sha224_start(t_flags *flag, int ac, char **av)
{
	int			fd;
	int			i;
	t_sha256	sha;

	i = 1;
	if (flag->p)
		stdinput(&sha, NULL, 224, flag);
	while ((++i < ac) && (av[i][0] == '-'))
		if (!ft_strcmp(av[i], "-s"))
			sha256string(&sha, av[i++ + 1], 224, flag);
	while (i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
			ft_printf("%s: No such file or directory\n", av[i]);
		else
		{
			sha256init(&sha, "", 224);
			sha256read(&sha, av[i], fd, flag);
		}
		i++;
	}
}

void	sha512_start(t_flags *flag, int ac, char **av)
{
	int			fd;
	int			i;
	t_sha512	sha;

	i = 1;
	if (flag->p)
		stdinput512(&sha, 512, flag);
	while ((++i < ac) && (av[i][0] == '-'))
		if (!ft_strcmp(av[i], "-s"))
			sha512string(&sha, av[i++ + 1], 512, flag);
	while (i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
			ft_printf("%s: No such file or directory\n", av[i]);
		else
		{
			sha512init(&sha, "", 512);
			sha512read(&sha, av[i], fd, flag);
		}
		i++;
	}
}

void	sha384_start(t_flags *flag, int ac, char **av)
{
	int			fd;
	int			i;
	t_sha512	sha;

	i = 1;
	if (flag->p)
		stdinput512(&sha, 384, flag);
	while ((++i < ac) && (av[i][0] == '-'))
		if (!ft_strcmp(av[i], "-s"))
			sha512string(&sha, av[i++ + 1], 384, flag);
	while (i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
			ft_printf("%s: No such file or directory\n", av[i]);
		else
		{
			sha512init(&sha, "", 384);
			sha512read(&sha, av[i], fd, flag);
		}
		i++;
	}
}
