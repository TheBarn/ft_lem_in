/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:55:31 by barnout           #+#    #+#             */
/*   Updated: 2017/04/04 19:12:28 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "value.h"
# include "../libft.h"

int				ft_printf(const char *restrict format, ...);
char			*conversion(unsigned int nb, int base);
char			*add_to_the_left(char *str, char c);
char			*add_to_the_right(char *str, char c);
char			*add_0_to_the_left(char *str, t_value value);
char			*apply_precision(t_value value, char *str);
char			*conversion(unsigned int nb, int base);
char			*shrtconversion(unsigned short nb, int base);
char			*jconversion(uintmax_t nb, int base);
int				analyze_arg(const char *format, t_value *value, int i, \
		va_list argp);
int				next_arg(const char *format, int i);
int				put_flags(const char *format, t_value *value, int i);
int				put_width(const char *format, t_value *value, int i, \
		va_list argp);
int				put_precision(const char *format, t_value *value, int i, \
		va_list argp);
int				put_modifier(const char *format, t_value *value, int i);
int				is_flag(char c);
void			init_flags(t_value *value);
char			*apply_flags(t_value value, char *str);
void			apply_flag_p(t_value value, char **str, char padding, int len);
int				is_int_cv(char c);
int				str_is_neg(char *str);
int				is_str_cv(char c);
int				is_cv(char c);
char			*ft_utoa(unsigned int n);
char			*ft_uimaxtoa(uintmax_t n);
char			*ft_imaxtoa(intmax_t n);
char			*toupper_str(char *str);
int				get_long(t_value *value, va_list argp);
int				get_llong(t_value *value, va_list argp);
int				get_size_t(t_value *value, va_list argp);
int				get_imax(t_value *value, va_list argp);
int				get_int(t_value *value, va_list argp);
int				get_short(t_value *value, va_list argp);
int				get_char(t_value *value, va_list argp);
int				get_str(t_value *value, va_list argp);
int				get_wstr(t_value *value, va_list argp);
int				get_wchar(t_value *value, va_list argp);
int				get_char(t_value *value, va_list argp);
int				get_no(t_value *value);
int				get_ptr(t_value *value, va_list argp);
int				ft_wstrlen_t(wchar_t *wstr_t);
char			*int_conversion(t_value value);
char			*char_conversion(t_value value);
char			*short_conversion(t_value value);
char			*long_conversion(t_value value);
char			*llong_conversion(t_value value);
char			*size_t_conversion(t_value value);
char			*imax_conversion(t_value value);
char			*ptr_conversion(t_value value);
int				print_wchar(char *str, t_value value);
int				print_char(t_value value);
int				print_str(t_value value);
int				print_wstr(t_value value);
int				print_int(t_value value);
int				print_short(t_value value);
int				print_long(t_value value);
int				print_llong(t_value value);
int				print_size_t(t_value value);
int				print_imax(t_value value);
int				print_ptr(t_value value);
void			address_conversion(unsigned long ptr, char **str);
char			*fill_bits(char *big, char *small);
char			*add_zeros(char *small, int nb);
char			*justify_zeros(char *small);
int				ft_wstrlen_t(wchar_t *wstr_t);
unsigned char	str_to_hex(char *str);
char			*hex_to_binary(char h);
char			*binary_to_hex(char *bi);
char			*bits_canvas(int bits);
char			*swap_minus(char *str);
int				wchar_to_bytes(t_value value, int i, int count_bytes, \
		char **str);

#endif
