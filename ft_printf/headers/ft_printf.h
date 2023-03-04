/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcha <mcha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:46:00 by mcha              #+#    #+#             */
/*   Updated: 2021/12/06 12:05:17 by mcha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef unsigned long long	t_ull;

typedef struct s_pack
{
	va_list				args;
	char				*target;
	long long			t_num;
	t_ull				h_num;
	long long			width;
	long long			dash;
	long long			plus;
	long long			space;
	long long			hash;
	long long			zero;
	long long			prec;
	long long			percent;
	long long			dot;
	long long			tot_len;
	long long			sign;
	long long			fin;
	long long			base;
	char				o_t;
	char				prev;
}	t_pack;

int					ft_get_pow(int i);
int					ft_is_type(char c);
int					ft_char_max(int widths);
int					ft_printf(const char *s, ...);
int					ft_do_print(char *str, va_list ap);
int					ft_print_char(t_pack *pack, int ele);
int					ft_print_percent(t_pack *pack, char c);
int					ft_do_convert(t_pack *pack, va_list ap);
int					ft_print_string(t_pack *pack, char *ele);
int					ft_print_dori(t_pack *pack, long long i);
int					ft_str_max(t_pack *pack, int widths, int precs, char *arg);
int					ft_nbrlen(t_pack *pack, t_ull nbr);
int					ft_print_hex(t_pack *pack, t_ull i);
int					ft_dori_max(t_pack *pack, t_ull nbr);
int					ft_hex_max(t_pack *pack, t_ull nbr);
int					ft_bind_nbr(t_pack *pack \
	, char **buf, t_ull i);

t_pack				*ft_init_struct(t_pack *pack);

void				ft_do_check(t_pack *pack, char c);
void				ft_check_prec(t_pack *pack, char c);
void				ft_check_flag(t_pack *pack, char c);
void				ft_check_type(t_pack *pack, char c);
void				ft_check_outr(t_pack *pack);
void				ft_check_width(t_pack *pack, char c);
void				ft_check_whole(t_pack *pack, char c, int *ret);
void				ft_bind_str_nd(t_pack *pack \
	, char *buf, char *ele, int get_m);
void				ft_bind_str_yd(t_pack *pack \
	, char *buf, char *ele, int get_m);
void				ft_bind_nbr_yd(t_pack *pack, char *buf \
	, t_ull i, int get_m);
void				ft_bind_nbr_nd(t_pack *pack, char *buf \
	, t_ull i, int get_m);
void				ft_bind_hex_yd(t_pack *pack, char *buf \
	, t_ull i, int get_m);
void				ft_bind_hex_nd(t_pack *pack, char *buf \
	, t_ull i, int get_m);

t_ull				ft_get_hex_pow(t_ull i);

#endif