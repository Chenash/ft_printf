/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:38:36 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:37:34 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** %[flags][width][.precision][length]specifier
*/

int					parse_conversion(t_conversion *conversion
										, va_list arguments
										, t_format *format)
{
	if (parse_flags(conversion, format) == 0
		&& parse_width(conversion, arguments, format) == 0
		&& parse_precision(conversion, arguments, format) == 0
		&& parse_length(conversion, format) == 0
		&& parse_specifier(conversion, format) == 0)
		return (0);
	return (1);
}
