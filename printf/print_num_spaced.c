/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_spaced.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochenash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:42:56 by ochenash          #+#    #+#             */
/*   Updated: 2018/09/04 16:05:54 by ochenash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_left(t_conversion *conv, char *str)
{
	tally_str(str);
	print_spacing(ft_strlen(str), conv->min_width, ' ');
}

void		print_num_spaced(t_conversion *conv, char *str)
{
	if (conv->flags->minus)
		return (print_left(conv, str));
	if (conv->flags->zero)
		print_spacing(ft_strlen(str), conv->min_width, '0');
	else
		print_spacing(ft_strlen(str), conv->min_width, ' ');
	tally_str(str);
}
