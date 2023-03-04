# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 23:06:34 by mcha              #+#    #+#              #
#    Updated: 2022/02/03 00:11:45 by mcha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY_DIR	= mandatory
BONUS_DIR		= bonus

NAME			= $(addprefix $(MANDATORY_DIR)/, so_long)
BONUS_NAME		= $(addprefix $(BONUS_DIR)/, so_long)

$(NAME)	:
		@$(MAKE) -C $(MANDATORY_DIR) all

$(BONUS_NAME) :
		@$(MAKE) -C $(BONUS_DIR) all

all : $(NAME)

bonus : $(BONUS_NAME)

clean :
		@$(MAKE) -C $(MANDATORY_DIR) clean
		@$(MAKE) -C $(BONUS_DIR) clean

fclean :
		@$(MAKE) -C $(MANDATORY_DIR) fclean
		@$(MAKE) -C $(BONUS_DIR) fclean

re : fclean all

re_bonus : fclean bonus

.PHONY : all bonus clean fclean re re_bonus