/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:28:52 by vdenysov          #+#    #+#             */
/*   Updated: 2017/11/02 13:28:54 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*s1;
	size_t	i;

	i = 0;
	if (s == NULL || *f == NULL)
		return (NULL);
	len = ft_strlen(s);
	s1 = ft_strnew(len);
	if (s1 == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		s1[i] = f(s[i]);
		i++;
	}
	return (s1);
}
