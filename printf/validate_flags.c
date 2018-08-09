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
			return (1);
	return (0);
}

static int			zero_flag(t_conversion *conversion)
{
	if (conversion->flags.pad_with_zeros)
		if (conversion->specifier == CHAR
			|| conversion->specifier == STRING
			|| conversion->specifier == POINTER)
			return (1);
	return (0);
}

static int			hashtag_flag(t_conversion *conversion)
{
	if (conversion->flags.hashtag)
		if (!(conversion->specifier == HEX_LOWER
				|| conversion->specifier == HEX_UPPER
				|| conversion->specifier == OCTAL))
			return (1);
	return (0);
}

int					validate_flags(t_conversion *conversion)
{
	if (show_positive_flags(conversion) == 0
		&& zero_flag(conversion) == 0
		&& hashtag_flag(conversion) == 0)
	{
		validate_flags_ignored(conversion);
		return (0);
	}
	return (1);
}
