#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yserkez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 14:47:18 by yserkez           #+#    #+#              #
#    Updated: 2019/02/02 10:45:59 by yserkez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** # 
NAME = minishell
SRC = *.c
OBJ = $(SRC:.c=.o)
SRC_PATH = srcs/
SRC_POS = $(addprefix $(SRC_PATH),$(SRC))
FLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a
HEADER = includes

all: makelib $(NAME) clean

makelib:
	make all -C libft/

$(NAME):
	gcc $(FLAGS) -I $(HEADER) -o $(NAME) $(SRC_POS) $(LIB);

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all 

.PHONY : all, re, clean, fclean
