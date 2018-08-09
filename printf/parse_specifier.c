/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 19:48:22 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 16:23:11 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** di		signed		decimal
** D		signed		decimal			l
** u		unsigned	decimal
** U		unsigned	decimal			l
** o		unsigned	octal
** O		unsigned	octal			l
** x		unsigned	hex (lowercase)
** X		unsigned	hex (uppercase)
** c		int
** C		wint_t						l
** s		char
** S		char*						l
** p		pointer
*/

static t_specifier	get_specifier(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (S_DECIMAL);
	if (c == 'u' || c == 'U')
		return (U_DECIMAL);
	if (c == 'o' || c == 'O')
		return (OCTAL);
	if (c == 'x')
		return (HEX_LOWER);
	if (c == 'X')
		return (HEX_UPPER);
	if (c == 'c' || c == 'C')
		return (CHAR);
	if (c == 's' || c == 'S')
		return (STRING);
	if (c == 'p')
		return (POINTER);
	return (INVALID_SPECIFIER);
}

int					parse_specifier(t_conversion *conversion
									, t_format *format)
{
	char			current;

	if (!((current = *get_current(format))))
		return (1);
	conversion->specifier = get_specifier(current);
	if (conversion->specifier == INVALID_SPECIFIER)
		return (1);
	if (current == 'D' || current == 'U' || current == 'O'
		|| current == 'S')
		conversion->length = L;
	format->location++;
	return (0);
}

//current == 'C' || 