/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:15:52 by vdenysov          #+#    #+#             */
/*   Updated: 2017/11/02 14:15:53 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		s1[i] = f(i, s[i]);
		i++;
	}
	return (s1);
}
