/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:48:54 by vdenysov          #+#    #+#             */
/*   Updated: 2017/10/27 17:48:56 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	i;
	int		j;
	size_t	s1_len;
	size_t	s2_len;

	i = ft_strlen(s1);
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (size < s1_len + 1)
		return (s2_len + size);
	if (size > s1_len + 1)
	{
		while (i < size - 1)
		{
			s1[i] = s2[j];
			i++;
			j++;
		}
		s1[i] = '\0';
	}
	return (s1_len + s2_len);
}
