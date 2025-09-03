#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: weast <weast@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 10:31:24 by weast             #+#    #+#              #
#    Updated: 2025/08/19 11:49:17 by weast            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
CPP = c++
FLAGS = -Wall -Wextra -Werror --std=c++98
DEPS = $(HEADERS) Makefile

all: $(NAME)

%.o: %.cpp $(DEPS)
		$(CPP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(CPP) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
