# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 23:08:39 by mcha              #+#    #+#              #
#    Updated: 2022/03/03 19:48:06 by mcha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
RM		= rm -rf
CFLAGS	= -I $(HEAD_ROOT) -Wall -Werror -Wextra -g

NAME	= philo

HEAD_ROOT	= includes
OBJS_ROOT	= objs
SRCS_ROOT	= srcs

vpath %.c $(SRCS_ROOT)

OBJS := main.o util_one.o progress.o util_free.o philosophers.o mutex.o time.o action.o monitor.o
OBJS := $(addprefix $(OBJS_ROOT)/, $(OBJS))

all : $(NAME)

$(OBJS_ROOT)/%.o : %.c
		@echo "[~] Linking $<"
		@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
		@echo "[+] Create philo"
		@$(CC) $(CFLAGS) -o $@ $(OBJS)

clean :
		@$(RM) $(OBJS)
		@echo "[-] Delete object files"

fclean : clean
		@$(RM) $(NAME)
		@echo "[-] Delete run files"

re : fclean all

.PHONY : all clean fclean re