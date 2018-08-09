/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 17:37:52 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 16:10:45 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** very much like parse_precision
*/

int					parse_width(t_conversion *conversion
								, va_list arguments, t_format *format)
{
	size_t			i;
	char			current;

	if (*get_current(format) == '*')
	{
		conversion->width = va_arg(arguments, unsigned int);
		if (conversion->width > LARGEST_STAR_ARGUMENT)
			conversion->width = 0;
		format->location++;
	}
	else
	{
		i = 0;
		while (((current = *(get_current(format) + i)))
				&& ft_isdigit(current))
		{
			ft_atoi_add_digit_u(current, &conversion->width);
			i++;
		}
		format->location += i;
	}
	return (OKAY);
}
