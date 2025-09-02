# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maprunty <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 08:24:10 by maprunty          #+#    #+#              #
#    Updated: 2025/08/20 08:24:28 by maprunty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
#https://stackoverflow.com/questions/72744277/script-to-create-a-static-library-from-all-c-file-in-my-working-directory
gcc -Wall -pedantic -Werror -Wextra -c \
ft_putchar.c \
ft_swap.c \
ft_putstr.c \
ft_strlen.c \
ft_strcmp.c \

ar -rc libwork.a *.o
rm *.o
