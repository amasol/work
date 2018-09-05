# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amasol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/21 16:06:31 by amasol            #+#    #+#              #
#    Updated: 2018/08/21 16:06:32 by amasol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = gcc
flgS = -Wall -Wextra -Werror

OBJ_DIR		= ./obj
SRC_DIR 	= ./srcs
INCL_DIR 	= ./includes
OBJ 		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
SRC 		=	ft_printf.c \
				ft_qualifier.c find.c cast.c ft_putnbr_long.c \
				itoa_b_uintmax.c parsing.c cast_flag_di.c cast_flag_u.c \
				cast_flag_c.c cast_flag_o.c cast_flag_s.c cast_flag_p.c \
				cast_flag_x.c ft_strlen_uintmax.c help.c cast_flag_ss.c\
				ft_strlen.c ft_strsub.c ft_strdel.c ft_atoi.c ft_bzero.c\
				ft_isdigit.c ft_strnew.c ft_isspace.c help_2.c help_flag.c\
				ft_putchar.c ft_putstr.c ft_lenwchar.c ft_putwchar.c \
				ft_putnbr.c no_spec.c ft_putstr_len.c help_flag_2.c \
				help_3.c

all: $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(flgS) -I $(INCL_DIR) -o $@ -c $<

$(NAME):
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all