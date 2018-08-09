/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_flags_ignored.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 20:54:31 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/28 21:00:59 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				begin_blank_show_sign(t_conversion *conversion)
{
	if (conversion->flags.positive_values_begin_blank
		&& conversion->flags.show_sign)
		conversion->flags.positive_values_begin_blank = 0;
}

void				pad_zeros_general(t_conversion *conversion)
{
	if (conversion->flags.pad_with_zeros)
	{
		if (conversion->flags.left_justify)
			conversion->flags.pad_with_zeros = 0;
		else if (conversion->precision_set)
			conversion->flags.pad_with_zeros = 0;
	}
}

void				validate_flags_ignored(t_conversion *conversion)
{
	begin_blank_show_sign(conversion);
	pad_zeros_general(conversion);
}
