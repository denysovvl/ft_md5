/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:55:41 by vdenysov          #+#    #+#             */
/*   Updated: 2017/10/27 19:55:43 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ndst;
	unsigned char	*nsrc;
	size_t			i;

	i = 0;
	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	while (i < n)
	{
		ndst[i] = nsrc[i];
		if ((unsigned char)c == nsrc[i])
			return (ndst + i + 1);
		i++;
	}
	return (NULL);
}
