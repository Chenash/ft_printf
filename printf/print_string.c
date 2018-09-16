/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochenash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:42:56 by ochenash          #+#    #+#             */
/*   Updated: 2018/09/04 16:05:54 by ochenash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_chars(t_conversion *conv, char *str, int size)
{
	if (conv->prec_set && conv->type == 's')
		size = (size < conv->precision ? size : conv->precision);
	if (conv->flags->minus)
	{
		tally_print(str, size);
		print_spacing(size, conv->min_width, ' ');
		return ;
	}
	if (conv->flags->zero)
		print_spacing(size, conv->min_width, '0');
	else
		print_spacing(size, conv->min_width, ' ');
	tally_print(str, size);
}

void			print_char(t_conversion *conv, char c)
{
	print_chars(conv, &c, 1);
}

void			print_str(t_conversion *conv, char *str)
{
	if (!str)
		str = "(null)";
	print_chars(conv, str, ft_strlen(str));
}
