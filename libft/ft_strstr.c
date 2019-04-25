/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:50:05 by vdenysov          #+#    #+#             */
/*   Updated: 2017/10/29 14:50:08 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;
	size_t a;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = i;
		a = 0;
		while (haystack[j] == needle[a])
		{
			a++;
			j++;
			if (needle[a] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
