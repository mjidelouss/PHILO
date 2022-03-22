# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 17:57:46 by aelousse          #+#    #+#              #
#    Updated: 2022/02/25 17:57:49 by aelousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
SRC = philo_bonus.c philo_bonus_utils.c philo_bonus_routine.c
OBJS = ${SRC:.c=.o}
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) philo_bonus.h
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "Compiling Successfull"

clean:
	@$(RM) $(OBJS)
	@echo "Object Files Removed Successfully"

fclean:clean
	@$(RM) all
	@echo "Clear"

re: fclean all
