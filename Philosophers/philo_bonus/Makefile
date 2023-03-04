# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 23:08:39 by mcha              #+#    #+#              #
#    Updated: 2022/03/03 19:38:28 by mcha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
RM		= rm -rf
CFLAGS	= -I $(HEAD_ROOT) -Wall -Werror -Wextra

NAME	= philo_bonus

HEAD_ROOT	= includes
OBJS_ROOT	= objs
SRCS_ROOT	= srcs

vpath %.c $(SRCS_ROOT)

OBJS := action_bonus.o main_bonus.o philo_bonus.o progress_bonus.o time_bonus.o util_free_bonus.o util_one_bonus.o util_sema_bonus.o
OBJS := $(addprefix $(OBJS_ROOT)/, $(OBJS))

all : $(NAME)

$(OBJS_ROOT)/%.o : %.c
		@echo "[~] Bonus Linking $<"
		@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
		@echo "[+] Create philo_bonus"
		@$(CC) $(CFLAGS) -o $@ $(OBJS)

clean :
		@$(RM) $(OBJS)
		@echo "[-] Delete bonus object files"

fclean : clean
		@$(RM) $(NAME)
		@echo "[-] Delete bonus run files"

re : fclean all

.PHONY : all clean fclean re