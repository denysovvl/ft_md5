/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 19:40:25 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/04 19:40:27 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"
#include "ft_sha256.h"
#include "ft_sha512.h"
#include "ft_base64.h"

static inline void	likessl(t_flags *flag, int ac, char *av[])
{
	char			buff[43];
	char			*tmp;
	int				ret;

	av[3] = ft_strnew(0);
	while ((ret = read(0, buff, 42)) > 0)
	{
		buff[ret] = '\0';
		tmp = av[3];
		if (!(av[3] = ft_strjoin(av[3], buff)))
			return ;
		ft_strdel(&tmp);
	}
	flag->p = 0;
	flag->q = 1;
	dispatcher(flag, ac, av, -1);
	free(av[3]);
}

static inline void	initssl(t_flags *flag, char *av, int f)
{
	char			*line[4];

	line[0] = NULL;
	line[1] = av;
	line[2] = "-s";
	line[3] = NULL;
	if (!f)
	{
		write(1, "ft_ssl> ", 8);
		while (get_next_line(0, &line[1]) > 0)
			if (line[1])
				break ;
	}
	if (check_func(line[1]))
		likessl(flag, 4, line);
}

t_func				g_funclist[FNUM] =
{
	{"md5", 0, md5_start},
	{"sha256", 1, sha256_start},
	{"sha224", 2, sha224_start},
	{"sha512", 3, sha512_start},
	{"sha384", 4, sha384_start},
	{"base64", 5, base64}
};

void				dispatcher(t_flags *flag, int ac, char **av, int i)
{
	while (++i < FNUM)
	{
		if (!ft_strcmp(av[1], g_funclist[i].name))
			(g_funclist[i].fptr)(flag, ac, av);
	}
}

int					main(int ac, char **av)
{
	t_flags	flag;

	if (ac < 2)
		initssl(&flag, NULL, 0);
	else if (ac == 2 || ((ac == 3) && (!ft_strcmp(av[2], "-q"))) || \
			((ac == 3) && (!ft_strcmp(av[2], "-r"))))
	{
		if (check_func(av[1]))
			initssl(&flag, av[1], 1);
	}
	else
	{
		flaginit(&flag, ac, av);
		dispatcher(&flag, ac, av, -1);
	}
	return (0);
}
