# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rouali <rouali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 20:08:53 by rouali            #+#    #+#              #
#    Updated: 2023/07/29 20:08:57 by rouali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_malloc.a

FLAGS = -Wall -Werror -Wextra

CC = cc

SOURCES = $(addprefix ./, ft_malloc.c misc_functions.c misc_functions2.c)

INCLUDE = ft_malloc.h

all: $(NAME) $(SOURCES)

$(NAME): $(SOURCES:.c=.o) $(INCLUDE)
	ar -r $(NAME) $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -I $(INCLUDE) -c $<

clean:
	rm -rf $(SOURCES:.c=.o)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re