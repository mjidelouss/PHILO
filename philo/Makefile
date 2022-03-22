# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 16:19:17 by aelousse          #+#    #+#              #
#    Updated: 2022/02/25 16:19:29 by aelousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = philo.c philo_utils.c philo_routine.c
OBJS = ${SRC:.c=.o}
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) philo.h
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "Compiling Successfull"

clean:
	@$(RM) $(OBJS)
	@echo "Object Files Removed Successfully"

fclean:clean
	@$(RM) all
	@echo "Clear"

re: fclean all
