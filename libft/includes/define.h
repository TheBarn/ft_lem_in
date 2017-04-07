/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:42:49 by barnout           #+#    #+#             */
/*   Updated: 2017/02/24 14:45:05 by barnout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define IS_LONG (value.modifier == 'l')
# define AS_LONG (value->modifier == 'l')
# define IS_LLONG (value.modifier == 'L')
# define IS_CHAR (value.modifier == 'H')
# define IS_INTMAX (value.modifier == 'j')
# define AS_INTMAX (value->modifier == 'j')
# define IS_SIZE_T (value.modifier == 'z')
# define AS_SIZE_T (value->modifier == 'z')
# define IS_SHRT (value.modifier == 'h')
# define IS_PTR (value.conversion == 'p')
# define IS_INT (value.conversion == 'i' || value.conversion == 'd')
# define IS_O (value.conversion == 'o')
# define AS_O (value->conversion == 'o')
# define IS_HEX (value.conversion == 'x' || value.conversion == 'X')
# define AS_HEX (value->conversion == 'x' || value->conversion == 'X')
# define IS_UNSG (value.conversion == 'u' || value.conversion == 'U')
# define AS_UNSG (value->conversion == 'u' || value->conversion == 'U')
# define IS_OCT (value.conversion == 'o' || value.conversion == 'O')
# define AS_OCT (value->conversion == 'o' || value->conversion == 'O')
# define IS_U (value.conversion == 'u')
# define AS_U (value->conversion == 'u')
# define IS_S (value.conversion == 's')
# define AS_S (value->conversion == 's')
# define IS_WS (value.conversion == 'S')
# define AS_WS (value->conversion == 'S')
# define IS_C (value.conversion == 'c')
# define AS_C (value->conversion == 'c')
# define IS_WC (value.conversion == 'C')
# define AS_WC (value->conversion == 'C')
# define IS_LD (value.conversion == 'D')
# define IS_LO (value.conversion == 'O')
# define IS_LU (value.conversion == 'U')
# define IS_WSTR (value.conversion == 'S' || value.conversion == 'C')
# define AS_WSTR (value->conversion == 'S' || value->conversion == 'C')
# define IS_STR (value.conversion == 'c' || value.conversion == 's')
# define GO_NEXT (format[i + 1] == '%' || format[i+ 1] == ' ')

#endif
