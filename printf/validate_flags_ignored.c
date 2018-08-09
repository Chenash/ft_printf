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

void				validate_flags_ignored(t_conversion *conversion)
{
	if (conversion->flags.positive_values_begin_blank
		&& conversion->flags.show_sign)
		conversion->flags.positive_values_begin_blank = 0;
	if (conversion->flags.pad_with_zeros)
	{
		if (conversion->flags.left_justify || conversion->precision_set)
			conversion->flags.pad_with_zeros = 0;
	}
}
