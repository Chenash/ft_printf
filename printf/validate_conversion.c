/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 16:58:37 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:29:00 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			pointer_has_specified_size(t_conversion *conversion)
{
	if (conversion->specifier == POINTER
		&& conversion->length != DEFAULT_LENGTH)
		return (1);
	return (0);
}

static int			precision_settable(t_conversion *conversion)
{
	if (conversion->precision_set
		&& ((conversion->specifier == CHAR && conversion->length >= L)
				|| conversion->specifier == POINTER))
		return (1);
	return (0);
}

static int			is_it_okay(t_conversion *conversion)
{
	if (pointer_has_specified_size(conversion) == 0
		&& validate_flags(conversion) == 0
		&& precision_settable(conversion) == 0)
		return (0);
	return (1);
}

int					validate_conversion(t_conversion *conversion
										, t_format *format)
{
	int				returned;

	format->location--;
	returned = is_it_okay(conversion);
	format->location++;
	return (returned);
}
