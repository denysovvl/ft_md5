/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:12:59 by vdenysov          #+#    #+#             */
/*   Updated: 2018/01/19 12:13:00 by vdenysov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include "../../libft.h"

typedef struct			s_modifiers
{
	int					total_l;
	int					length;
	int					prc;
	int					pdg;
	int					str_in;
	char				str[32];
	char				*fm;
	short				f;
}						t_modifiers;

typedef struct			s_vars
{
	int					out;
	unsigned			c;
	va_list				ap;
	int					iter;
	short				n;
}						t_vars;

t_modifiers				g_m;
t_vars					g_v;

enum					e_flags
{
	SHP = 1,
	SP = 2,
	PL = 4,
	MN = 8,
	ZR = 16,
	WC = 32,
	UL = 64,
	SH = 128,
	SH2 = 256,
	LN = 512,
	LN2 = 1024,
	IM = 2048,
	ST = 4096,
	ML = 8192,
	PRC = 16384,
	PO = 32768,
};
typedef enum e_flags	t_flag;

int						ft_printf(const char *fm, ...);
int						char_all_iterator(char *s, int c, int i);
int						char_iterator(char *s, int c, int i);
int						max(int a, int b);
int						min(int a, int b);

void					print_char(unsigned c);
void					print_w_string(void);
void					print_string_h(void);
void					print_string(char *s);
void					get_width(int n);
void					print_writer(void *elem, size_t size);
void					print_w_char(unsigned int wc, int wlen, int blen);
void					print_nbr(void);
void					nb_to_base(int base);
void					int_to_base(uintmax_t n, int b);
void					if_not_spec(void);
void					get_prc(void);
void					get_spec(void);
void					get_ptr(void);
void					itoa_printf(intmax_t n, int len);
void					itoa_base_fill(uintmax_t tmp, int b, char s[32]);

size_t					w_char_l(unsigned wc);
size_t					w_string_l(unsigned *s);

# define ABS(a)		(a < 0) ? -a : a

#endif
