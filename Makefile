# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdenysov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 19:43:02 by vdenysov          #+#    #+#              #
#    Updated: 2018/10/04 19:43:03 by vdenysov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
HEADER = -I.
FOLDERLIB = libft
FOLDERPRINT = libft/ft_printf
FILEPRINT = libft/ft_printf/libftprintf.a
SRC = main.c flags_input.c \
		ssl_start.c ssl_print.c \
		md5rounds.c md5init.c md5proc.c md5read.c \
		sha256init.c sha256rounds.c sha256read.c \
		sha512init.c sha512rounds.c sha512read.c \
		base64.c

FLAGS = -Wall -Wextra 

OBJ = $(SRC:.c=.o)

all:		$(NAME)

%.o:		%.c
	@gcc -c -g $? $(FLAGS) $(HEADER)

$(NAME):	$(OBJ)
	@make -C $(FOLDERLIB)
	@make -C $(FOLDERPRINT)
	@gcc -o $(NAME) $(OBJ) $(FILEPRINT) -L $(FOLDERLIB) -lft
	@echo Make: ft_ssl "\033[92mOK\033[0m"

clean:
	@make clean -C $(FOLDERLIB)
	@make clean -C $(FOLDERPRINT)
	@rm -f $(OBJ)

fclean:		clean
	@make fclean -C $(FOLDERLIB)
	@make fclean -C $(FOLDERPRINT)
	@rm -f $(NAME)

re:			fclean	all
