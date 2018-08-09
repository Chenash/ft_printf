/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:13:50 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:28:46 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			show_positive_flags(t_conversion *conversion)
{
	if (conversion->flags.positive_values_begin_blank
		|| conversion->flags.show_sign)
		if (conversion->specifier != S_DECIMAL)
			return (ERROR);
	return (OKAY);
}

static int			zero_flag(t_conversion *conversion)
{
	if (conversion->flags.pad_with_zeros)
		if (conversion->specifier == CHAR
			|| conversion->specifier == STRING
			|| conversion->specifier == POINTER)
			return (ERROR);
	return (OKAY);
}

static int			hashtag_flag(t_conversion *conversion)
{
	if (conversion->flags.hashtag)
		if (!(conversion->specifier == HEX_LOWER
				|| conversion->specifier == HEX_UPPER
				|| conversion->specifier == OCTAL))
			return (ERROR);
	return (OKAY);
}

int					validate_flags(t_conversion *conversion)
{
	if (show_positive_flags(conversion) == OKAY
		&& zero_flag(conversion) == OKAY
		&& hashtag_flag(conversion) == OKAY)
	{
		validate_flags_ignored(conversion);
		return (OKAY);
	}
	return (ERROR);
}
