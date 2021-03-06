/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:57:58 by vdenysov          #+#    #+#             */
/*   Updated: 2017/11/14 13:58:38 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int *arr)
{
	int i;
	int num;

	i = 0;
	num = arr[i];
	while (arr[i])
	{
		if (num > arr[i])
			num = arr[i];
		i++;
	}
	return (num);
}
