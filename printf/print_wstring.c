/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochenash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:42:56 by ochenash          #+#    #+#             */
/*   Updated: 2018/09/04 16:05:54 by ochenash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_wchars(t_conversion *conv, wchar_t *wstr, int *size)
{
	int		i;
	int		add;
	int		total;

	i = 0;
	add = 0;
	total = 0;
	while (i < *size)
	{
		if (wstr[i] <= 127)
			add = 1;
		else if (wstr[i] <= 2047)
			add = 2;
		else if (wstr[i] <= 65535)
			add = 3;
		else if (wstr[i] <= 1114111)
			add = 4;
		if (conv->prec_set && conv->type == 's'
			&& (total + add) > conv->precision)
			break ;
		total += add;
		i++;
	}
	*size = i;
	return (total);
}

static void		print_wchars(t_conversion *conv, wchar_t *wstr, int size)
{
	int		i;
	int		total;

	total = count_wchars(conv, wstr, &size);
	if (!(conv->flags->minus) && conv->flags->zero)
		print_spacing(total, conv->min_width, '0');
	else if (!(conv->flags->minus))
		print_spacing(total, conv->min_width, ' ');
	i = 0;
	while (i < size)
	{
		print_wint(wstr[i]);
		i++;
	}
	if (conv->flags->minus)
		print_spacing(total, conv->min_width, ' ');
}

void			print_wchar(t_conversion *conv, wint_t wint)
{
	wchar_t	wchar;

	wchar = (wchar_t)wint;
	print_wchars(conv, &wchar, 1);
}

static size_t	ft_wstrlen(wchar_t *wstr)
{
	wchar_t	*temp;

	temp = wstr;
	while (*temp != L'\0')
		temp++;
	return (temp - wstr);
}

void			print_wstr(t_conversion *conv, wchar_t *wstr)
{
	if (!wstr)
		print_str(conv, NULL);
	else
		print_wchars(conv, wstr, ft_wstrlen(wstr));
}
