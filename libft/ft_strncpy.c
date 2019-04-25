/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:35:22 by vdenysov          #+#    #+#             */
/*   Updated: 2017/10/25 15:35:24 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *suke;

	suke = dst;
	while (0 < len && *src != '\0')
	{
		*suke++ = *src++;
		--len;
	}
	while (len > 0)
	{
		*suke++ = '\0';
		--len;
	}
	return (dst);
}
