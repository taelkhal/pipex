# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 17:16:17 by taelkhal          #+#    #+#              #
#    Updated: 2023/02/26 21:05:38 by taelkhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ft_putstr.c ft_split.c ft_strjoin.c pipex.c check_path_env.c ft_strlen.c \
		ft_strstr.c more_or_less_args.c close_and_wait.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all