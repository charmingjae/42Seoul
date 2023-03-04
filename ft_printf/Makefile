# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 18:42:21 by mcha              #+#    #+#              #
#    Updated: 2021/12/06 18:43:30 by mcha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
AR		= ar rcs
CC		= gcc
LIBFT	= libft
SRC_F	= srcs
B_SRC_F	= bonus_srcs

SRC_FILES = ft_printf \
			ft_do_print \
			ft_do_check \
			ft_init_struct \
			ft_check_whole \
			ft_check_flag \
			ft_check_type \
			ft_check_prec \
			ft_check_width \
			ft_check_outr \
			ft_is_type \
			ft_do_convert \
			ft_char_max \
			ft_print_char \
			ft_print_string \
			ft_str_max \
			ft_bind_str_nd \
			ft_bind_str_yd \
			ft_print_percent \
			ft_print_dori \
			ft_dori_max \
			ft_bind_nbr_yd \
			ft_nbrlen \
			ft_get_pow \
			ft_bind_nbr_nd \
			ft_print_hex \
			ft_bind_hex_yd \
			ft_get_hex_pow \
			ft_bind_hex_nd \
			ft_hex_max \

B_SRC_FILES = ft_printf_bonus \
			ft_do_print_bonus \
			ft_do_check_bonus \
			ft_init_struct_bonus \
			ft_check_whole_bonus \
			ft_check_flag_bonus \
			ft_check_type_bonus \
			ft_check_prec_bonus \
			ft_check_width_bonus \
			ft_check_outr_bonus \
			ft_is_type_bonus \
			ft_do_convert_bonus \
			ft_char_max_bonus \
			ft_print_char_bonus \
			ft_print_string_bonus \
			ft_str_max_bonus \
			ft_bind_str_nd_bonus \
			ft_bind_str_yd_bonus \
			ft_print_percent_bonus \
			ft_print_dori_bonus \
			ft_dori_max_bonus \
			ft_bind_nbr_yd_bonus \
			ft_nbrlen_bonus \
			ft_get_pow_bonus \
			ft_bind_nbr_nd_bonus \
			ft_print_hex_bonus \
			ft_bind_hex_yd_bonus \
			ft_get_hex_pow_bonus \
			ft_bind_hex_nd_bonus \
			ft_hex_max_bonus \



SRCS = $(addprefix $(SRC_F)/, $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(SRC_F)/, $(addsuffix .o, $(SRC_FILES)))

B_SRCS = $(addprefix $(B_SRC_F)/, $(addsuffix .c, $(B_SRC_FILES)))
B_OBJS = $(addprefix $(B_SRC_F)/, $(addsuffix .o, $(B_SRC_FILES)))

ifdef WITH_BONUS
	OBJ = $(OBJS) $(B_OBJS)
else
	OBJ = $(OBJS)
endif

all: $(NAME)

$(NAME) : $(OBJ)
		@make -C $(LIBFT)
		@cp libft/libft.a .
		@mv libft.a $(NAME)
		@$(AR) $(NAME) $(OBJ)

bonus :
	make WITH_BONUS=1 all

*.o : *.c
		@$(CC) $(CFLAGS) -c $< -o $@

clean :
		@$(RM) -rf $(OBJS) $(B_OBJS)
		@make clean -C $(LIBFT)

fclean: clean
		@$(RM) -f $(NAME)
		@$(RM) -f $(LIBFT)/libft.a

re : fclean all

.PHONY : all clean fclean re bonus