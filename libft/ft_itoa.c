/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:36:35 by vdenysov          #+#    #+#             */
/*   Updated: 2017/11/06 15:36:37 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			i;
	long long	c;

	i = 0;
	len = ft_count(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	c = (long long)n;
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (c < 0)
	{
		str[i++] = '-';
		c *= -1;
	}
	while (len > i)
	{
		str[len - 1] = ((c % 10) + '0');
		c /= 10;
		len--;
	}
	return (str);
}
