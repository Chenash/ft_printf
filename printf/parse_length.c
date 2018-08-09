/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 19:23:16 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 15:36:45 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_length		get_length(char current, char next)
{
	if (current == 'h')
	{
		if (next == 'h')
			return (HH);
		return (H);
	}
	if (current == 'l')
	{
		if (next == 'l')
			return (LL);
		return (L);
	}
	if (current == 'j')
		return (J);
	if (current == 'z')
		return (Z);
	return (DEFAULT_LENGTH);
}

int					parse_length(t_conversion *conversion, t_format *format)
{
	char			current;
	char			next;

	if (!((current = *get_current(format)))
			|| !((next = *(get_current(format) + 1))))
		return (0);
	conversion->length = get_length(current, next);
	if (conversion->length != DEFAULT_LENGTH)
		format->location++;
	if (conversion->length == HH || conversion->length == LL)
		format->location++;
	return (0);
}
