# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 18:42:21 by mcha              #+#    #+#              #
#    Updated: 2022/01/11 11:06:47 by mcha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
NAMEB	= checker
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -rf
AR		= ar rcs
CC		= gcc

HEADER = -I header/mandatory
SRCS = $(wildcard ./srcs/*/*.c)
OBJS = $(SRCS:.c=.o)

HEADERB = -I header/bonus
SRCB = $(wildcard ./bonus/*/*.c)
OBJB = $(SRCB:.c=.o)

ifdef WITH_BONUS
		OBJF = $(OBJB)
		NAME = checker
else
		OBJF = $(OBJS)
		NAME = push_swap
endif

ifdef WITH_BONUS
%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@ $(HEADERB)
else
%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)
endif

$(NAME) : $(OBJF)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJF)

all: $(NAME)

bonus :
	make WITH_BONUS=1 all

clean :
		$(RM) $(OBJS) $(OBJB)

fclean: clean
		$(RM) $(NAME) $(NAMEB)

re : fclean all

.PHONY : all clean fclean re bonus
