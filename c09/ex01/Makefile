# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maprunty <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 08:25:06 by maprunty          #+#    #+#              #
#    Updated: 2025/08/20 18:03:12 by maprunty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME := libft.a

INC_DIR := -Iincludes
SRC_DIR := srcs
OBJ_DIR := obj

SRC_FILES := ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c ft_putnbr.c ft_atoi.c
SRCS := $(SRC_FILES:%.c=$(SRC_DIR)/%.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

FLAGS := -Wall -Wextra -Werror
CC := cc 
AR := ar -rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(INC_DIR) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
