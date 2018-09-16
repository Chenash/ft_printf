/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochenash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:42:56 by ochenash          #+#    #+#             */
/*   Updated: 2018/09/04 16:05:54 by ochenash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*print_until(char *str, char c)
{
	while (*str != '\0' && *str != c)
		tally_print(str++, 1);
	return (str);
}

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	char			*str;

	va_start(ap, format);
	str = (char *)format;
	while (*str != '\0')
	{
		str = print_until(str, '%');
		if (*str == '%')
			str++;
		if (*str != '\0')
			str = print_conversion(str, ap);
	}
	va_end(ap);
	return (tally_get(0, 0));
}
