# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/20 19:51:44 by vdenysov          #+#    #+#              #
#    Updated: 2018/01/20 19:51:46 by vdenysov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -O3
LIBFT = ../
DIRSRC = src
DIROBJ = temp
HEADER = include
SOURCES = ft_printf.c ft_numbers_funcs.c ft_strings_fucns.c ft_iters_funcs.c \
			ft_parcers_fucns.c adds.c w_char_string.c nb_to_base.c \
			int_to_base.c itoa_base_fill.c print_w_char.c print_w_string.c 

OBJS = $(addprefix $(DIROBJ)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@cp ../libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIROBJ)/%.o: $(DIRSRC)/%.c
	@mkdir -p temp
	@gcc $(FLAGS) -I./$(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIROBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
