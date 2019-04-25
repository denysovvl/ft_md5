/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:34:44 by vdenysov          #+#    #+#             */
/*   Updated: 2017/10/29 19:34:46 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int					i;
	int					negative;
	unsigned long long	number;

	i = 0;
	negative = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		negative = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		if (number * 10 + (str[i] - '0') < number)
			return ((negative == 1) ? -1 : 0);
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return ((int)number * negative);
}
