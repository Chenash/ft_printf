/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochenash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:42:56 by ochenash          #+#    #+#             */
/*   Updated: 2018/09/04 16:05:54 by ochenash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	*new_flags(void)
{
	t_flags		*neoflags;

	neoflags = malloc(sizeof(t_flags));
	ft_bzero(neoflags, sizeof(t_flags));
	return (neoflags);
}

t_conversion	*new_conversion(char *str)
{
	t_conversion	*neoconvert;

	neoconvert = malloc(sizeof(t_conversion));
	ft_bzero(neoconvert, sizeof(t_conversion));
	neoconvert->start = str;
	neoconvert->flags = new_flags();
	neoconvert->modif = NONE;
	return (neoconvert);
}
