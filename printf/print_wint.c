/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochenash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:42:56 by ochenash          #+#    #+#             */
/*   Updated: 2018/09/04 16:05:54 by ochenash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_wint(wint_t wint)
{
	char	str[4];

	if (wint <= 127)
		tally_print(&wint, 1);
	else if (wint <= 2047)
	{
		str[0] = (((wint & 1984) >> 6) + 192);
		str[1] = ((wint & 63) + 128);
		tally_print(str, 2);
	}
	else if (wint <= 65535)
	{
		str[0] = (((wint & 61440) >> 12) + 224);
		str[1] = (((wint & 4032) >> 6) + 128);
		str[2] = ((wint & 63) + 128);
		tally_print(str, 3);
	}
	else if (wint <= 1114111)
	{
		str[0] = (((wint & 1835008) >> 18) + 240);
		str[1] = (((wint & 258048) >> 12) + 128);
		str[2] = (((wint & 4032) >> 6) + 128);
		str[3] = ((wint & 63) + 128);
		tally_print(str, 4);
	}
}
