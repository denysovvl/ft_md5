/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:36:47 by vdenysov          #+#    #+#             */
/*   Updated: 2017/10/25 20:36:53 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*nsrc;
	unsigned char	*ndst;

	nsrc = (unsigned char *)src;
	ndst = (unsigned char *)dst;
	while (n--)
		*ndst++ = *nsrc++;
	return (dst);
}
