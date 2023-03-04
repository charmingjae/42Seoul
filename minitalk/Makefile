# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 18:24:47 by mcha              #+#    #+#              #
#    Updated: 2022/01/21 18:30:23 by mcha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY_DIR	= mandatory
BONUS_DIR		= bonus

NAME			= $(addprefix $(MANDATORY_DIR)/, server client)
BONUS_NAME		= $(addprefix $(BONUS_DIR)/, server client)

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