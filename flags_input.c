/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:58:44 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/22 12:58:45 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "ft_sha256.h"
#include "ft_sha512.h"

void	flaginit(t_flags *flag, int ac, char **av)
{
	flag->q = 0;
	flag->r = 0;
	flag->p = 0;
	flag->string = NULL;
	parse_flags(flag, ac, av, 1);
}

void	parse_flags(t_flags *flag, int ac, char **av, int i)
{
	while ((++i < ac) && av[i][0] == '-')
	{
		if (!ft_strcmp(av[i], "-q"))
			flag->q = 1;
		else if (!ft_strcmp(av[i], "-r"))
			flag->r = 1;
		else if (!ft_strcmp(av[i], "-p"))
			flag->p += 1;
		else if (!ft_strcmp(av[i], "-s"))
		{
			if (av[i + 1])
			{
				if (!ft_strcmp(av[i + 1], "-p"))
					flag->p = -1;
				break ;
			}
			else
				printserror();
		}
		else
			printferror(av[i][1]);
	}
}

void	stdinput(t_sha256 *sha, t_md5 *md, int shanum, t_flags *flag)
{
	char	buff[43];
	char	*input;
	char	*tmp;
	int		ret;

	input = ft_strnew(0);
	while ((ret = read(0, buff, 42)) > 0)
	{
		buff[ret] = '\0';
		tmp = input;
		if (!(input = ft_strjoin(input, buff)))
			return ;
		ft_strdel(&tmp);
	}
	if (sha)
		sha256string(sha, input, shanum, flag);
	else
		md5string(md, input, flag);
	flag->p = 0;
	free(input);
}

void	stdinput512(t_sha512 *sha, int shanum, t_flags *flag)
{
	char	buff[43];
	char	*input;
	char	*tmp;
	int		ret;

	input = ft_strnew(0);
	while ((ret = read(0, buff, 42)) > 0)
	{
		buff[ret] = '\0';
		tmp = input;
		if (!(input = ft_strjoin(input, buff)))
			return ;
		ft_strdel(&tmp);
	}
	sha512string(sha, input, shanum, flag);
	flag->p = 0;
	free(input);
}
