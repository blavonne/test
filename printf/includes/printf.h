/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:40:05 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:53:37 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

/*
** Secondary includes
*/
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "fractional.h"
# include "integral.h"
# include "xray.h"

/*
** Binary flags -+ 0#
*/
# define FLG_NONE		0b00000000u
# define FLG_SPACE		0b00000001u
# define FLG_ZERO		0b00000010u
# define FLG_MINUS		0b00000100u
# define FLG_NBRSIGN	0b00001000u
# define FLG_PLUS		0b00010000u

/*
** RADIX for itoa
*/
# define RADIX			"0123456789abcdef"

/*
** Numeral systems
*/
# define DECIMAL			10
# define OCTAL			8
# define HEX				16

/*
** Length of word, which means (null)
*/
# define STR_NULL_LEN 	6

/*
** This value means info.precision or info.width is star
*/
# define READ_ARG		-2

/*
** This value means exponent is 11...11
*/
# define INF				16384

/*
** Definitions
*/
typedef union				u_integer
{
	int						i;
	long int				l;
	long long int			ll;
	unsigned int			u;
	unsigned long int		lu;
	unsigned long long int	llu;
}							t_integer;

typedef struct				s_float
{
	char					mantissa[65];
	int						exponent;
	char					sign;
}							t_float;

typedef struct				s_format
{
	unsigned char			flags;
	int						width;
	int						precision;
	char					length[3];
	char					specifier;
	t_integer				z;
	t_float					r;
}							t_format;

/*
** libft functions
*/
void						ft_putchar(char c);
void						ft_bzero(void *s, size_t n);
void						*ft_memset(void *b, int c, size_t len);
int							ft_abs(int nbr);
int							ft_tolower(int c);
void						ft_str_tolower(char *str);
int							ft_toupper(int c);
void						ft_str_toupper(char *str);
void						ft_putstr(char const *s);
char						*ft_strnew(size_t size);
void						ft_putstr_fd(char const *s, int fd);
size_t						ft_strlen(const char *s);
char						*ft_strchr(const char *s, int c);
int							ft_isdigit(int c);
char						*ft_strcat(char *s1, const char *s2);
char						*ft_strjoin(char const *s1, char const *s2);
double						ft_pow(double basis, int exponent);
char						*ft_strcpy(char *dst, const char *src);

/*
** itoa and symbols count functions
*/
char						*itoa_i(int decimal);
char						*itoa_u(unsigned int decimal, int base);
char						*itoa_l(long int decimal);
char						*itoa_lu(unsigned long int decimal, int base);
char						*itoa_ll(long long int decimal);
char						*itoa_llu(unsigned long long int decimal, int base);
int							nbr_len(t_format *info);
int							nbr_len_int(t_format *info);
int							nbr_len_uint(t_format *info, int base);
int							nbr_len_int_l(t_format *info);
int							nbr_len_uint_l(t_format *info, int base);
int							nbr_len_int_ll(t_format *info);
int							nbr_len_uint_ll(t_format *info, int base);

/*
** PRINTF
*/
int							ft_printf(char *format, ...);
void						put_errmsg_and_exit(char type);

/*
** Parser
*/
void						parse_text(char *format, int *i, int *count);
void						parse_flags(char *format, int *i, t_format *info);
void						set_flag(char c, t_format *info);
void						parse_width(char *format, int *i, t_format *info);
void						parse_prec(char *format, int *i, t_format *info);
void						parse_length(char *format, int *i, t_format *info);
int							parse_type(char *format, int *i, t_format *info);
int							check_info(t_format *info, va_list *arg);
int							push_to_processor(t_format *info, va_list *arg);

/*
** Processor - integers
*/
int							integer(t_format *info, va_list *arg);
int							sign(t_format *info, char option);
int							print_arg(t_format *info);
int							flg_minus_case(t_format *info);
int							flg_zero_case(t_format *info);
int							flg_others_case(t_format *info);

/*
** Processor - chars
*/
int							chars(t_format *info, va_list *arg);
int							char_case(t_format *info, unsigned char arg);
int							string_case(t_format *info, char *arg);

/*
** Processor - others
*/
int							percent(t_format *info);
int							pointer(t_format *info, va_list *arg);

/*
** Processor - floats
*/
int							floats(t_format *info, va_list *arg);
t_float						initialize_float(long double arg);
char						*get_arg_f(t_format *info);
char						*check_inf_nan(t_format *info);
int							get_mant_len(char *mantissa);
char						*process_flags_f(t_format *info, char *arg);

#endif
