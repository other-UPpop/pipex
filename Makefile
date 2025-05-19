# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rohta <rohta@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 20:34:14 by rohta             #+#    #+#              #
#    Updated: 2025/05/19 21:22:39 by rohta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = .
OBJ_DIR = .
LIBFT_DIR = ./libft

SRC = main.c get_arg.c file_open.c child_process.c \
	get_cmd_path.c pipe_util.c
	  
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDES = -I $(LIBFT_DIR)
LIBS = -L $(LIBFT_DIR) -lft

LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re