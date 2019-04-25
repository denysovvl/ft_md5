/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:35:57 by vdenysov          #+#    #+#             */
/*   Updated: 2017/11/02 19:35:59 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_cwords(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static	size_t	ft_lword(char const *s, char c, size_t n)
{
	size_t	i;
	size_t	count;
	size_t	k;

	i = 0;
	k = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		if (count == n)
		{
			while (s[i] != c)
			{
				k++;
				if (i == 0)
					return (k);
				i--;
			}
			return (k);
		}
		i++;
	}
	return (0);
}

static	char	**ft_fill(char const *s, char c, char **res)
{
	size_t	i;
	size_t	j;
	size_t	count;
	size_t	word;

	i = 0;
	word = 1;
	count = 0;
	while (word <= ft_cwords(s, c))
	{
		j = 0;
		while (s[i] == c)
			i++;
		count++;
		if (count == word)
		{
			while (j < ft_lword(s, c, word))
				res[word - 1][j++] = s[i++];
		}
		res[word - 1][j] = '\0';
		word++;
	}
	res[word - 1] = NULL;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	res = (char **)malloc(sizeof(char *) * (ft_cwords(s, c) + 1));
	if (res == NULL)
		return (NULL);
	while (i < ft_cwords(s, c))
	{
		res[i] = (char *)malloc(sizeof(char) * (ft_lword(s, c, i + 1) + 1));
		if (res[i] == NULL)
			return (NULL);
		i++;
	}
	res = ft_fill(s, c, res);
	return (res);
}
