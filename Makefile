# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/31 17:14:15 by mmokane           #+#    #+#              #
#    Updated: 2023/01/15 00:55:01 by mmokane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFlAGS = -Wall -Wextra -Werror

SRCS = ft_split.c ft_strjoin.c ft_strstr.c ft_strlen.c pipex.c check_the_path.c

OBJS = $(SRCS:.c=.o)

CC = gcc

$(NAME) : $(OBJS)
				cc $(CFlAGS) $(OBJS) -o $(NAME)
				
all : $(NAME)

clean :
				rm -fr $(OBJS)
		
fclean : clean	
				rm -fr $(NAME)
				
re : fclean all