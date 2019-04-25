/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:16:09 by vdenysov          #+#    #+#             */
/*   Updated: 2018/10/14 13:16:11 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE64_H
# define FT_BASE64_H

# include "libft/libft.h"
# include "ft_sha256.h"
# include "libft/ft_printf/include/ft_printf.h"
# include <stdio.h>
# define DEC 1
# define ENC 0

void	base64(t_flags *flag, int ac, char **av);
void	printbase(int num);
void	padding(char *str, int len, int ptr);
void	strdelim(char *str, int len);

char	*dectobin(unsigned int n);
char	*dectobin(unsigned int n);
char	*join(unsigned char *inp, int len, int mode);

#endif

