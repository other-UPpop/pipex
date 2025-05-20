# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 06:33:59 by rohta             #+#    #+#              #
#    Updated: 2025/05/08 08:00:26 by rohta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
	ft_memchr.c ft_memcpy.c ft_memset.c ft_memmove.c ft_memcmp.c\
	ft_strlcat.c ft_strlcpy.c ft_strchr.c ft_strnstr.c ft_strrchr.c\
	ft_strlen.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c\
	ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_long_atoi.c\
	get_next_line.c get_next_line_bonus.c\
	ft_printf.c ft_printf_check.c ft_params_init.c ft_apply_csp.c\
	ft_apply_diuxX.c ft_write_string.c ft_write_number.c\
	ft_write_hexdecimal.c ft_write_unsigned.c ft_write_pointer.c\
	ft_write_number_sub.c ft_write_number_sub2.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
	ft_lstmap.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

ifeq ($(MAKECMDGOALS),bonus)
    OBJS = $(OBJ) $(BONUS_OBJ)
else
    OBJS = $(OBJ)
endif

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 

bonus : $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus
