# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 18:17:44 by mcarrete          #+#    #+#              #
#    Updated: 2020/03/04 21:04:28 by mcarrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Cub3D
SRC				= main.c
SRC_LIB_PATH	= ./libft
MLX_PATH		= /usr/local/lib/
OBJ				= $(SRC:.c=.o)
OBJ_LIB 		= $(SRC_LIB_NAME:.c=.o)
CFLAG			= -Wall -Wextra -Werror
CC				= gcc
INCLUDES_LIB	= ./libft
INCLUDES_MLX	= /usr/local/include
FRAMEWORKS_MLX	= -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):	$(OBJ) $(OBJ_LIB)
	make -C $(SRC_LIB_PATH)
	$(CC) $(CFLAG) main.c -o $(NAME) -I$(INCLUDES_MLX) -L $(MLX_PATH) -lmlx -L $(SRC_LIB_PATH) -lft $(FRAMEWORKS_MLX)


%.o:%.c

%.o: %.c
	$(CC) -c $(CFLAG) -o $@ $<

clean:
	rm -f *.o
	make -C $(SRC_LIB_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(SRC_LIB_PATH) fclean

re: 		fclean all

.PHONY:		clean fclean
