/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochenash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:42:56 by ochenash          #+#    #+#             */
/*   Updated: 2018/09/04 16:05:54 by ochenash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parse_flags(char *str, t_flags *flags)
{
	while (ft_strchr("#0-+ ", *str))
	{
		if (*str == '#')
			flags->pound = 1;
		else if (*str == '0')
			flags->zero = 1;
		else if (*str == '-')
			flags->minus = 1;
		else if (*str == '+')
			flags->plus = 1;
		else if (*str == ' ')
			flags->space = 1;
		else if (*str == '\0')
			break ;
		str++;
	}
	return (str);
}

static char	*parse_min_width(char *str, t_conversion *conv)
{
	conv->min_width = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	return (str);
}

static char	*parse_precision(char *str, t_conversion *conv)
{
	if (*str != '.')
		return (str);
	str++;
	conv->precision = ft_atoi(str);
	conv->prec_set = 1;
	while (ft_isdigit(*str))
		str++;
	return (str);
}

static char	*parse_modifier(char *str, t_conversion *conv)
{
	if (!ft_strchr("hljz", *str))
		return (str);
	if (ft_strncmp(str, "hh", 2) == 0)
	{
		conv->modif = HH;
		return (str + 2);
	}
	if (ft_strncmp(str, "ll", 2) == 0)
	{
		conv->modif = LL;
		return (str + 2);
	}
	else if (*str == 'h')
		conv->modif = H;
	else if (*str == 'l')
		conv->modif = L;
	else if (*str == 'j')
		conv->modif = J;
	else if (*str == 'z')
		conv->modif = Z;
	return (str + 1);
}

char		*parse_conversion(char *str, t_conversion *conv)
{
	str = parse_flags(str, conv->flags);
	if (ft_strchr(",;:_", *str))
	{
		conv->sep = *str;
		str++;
	}
	str = parse_min_width(str, conv);
	str = parse_precision(str, conv);
	str = parse_modifier(str, conv);
	conv->type = *str;
	return (str + 1);
}
