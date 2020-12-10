/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:58:54 by ctycho            #+#    #+#             */
/*   Updated: 2020/12/09 22:02:28 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		parser_flag(t_list *list)
{
	while (list->print[list->i] == '-' || list->print[list->i] == '0')
	{
		if (list->print[list->i] == '-')
			list->minus = 1;
		if (list->print[list->i] == '0')
			list->zero = 1;
		list->i++;
	}
	return ;
}

static void		parser_width(t_list *list)
{
	if (list->print[list->i] == '*')
	{
		list->width = va_arg(list->ap, int);
		if (list->width < 0)
		{
			list->minus = 1;
			list->width *= -1;
		}
		list->i++;
	}
	else if (list->print[list->i] >= '0' && list->print[list->i] <= '9')
		list->width = ft_atoi(&list->print[list->i], list);
	return ;
}

void			parser_precision(t_list *list)
{
	if (list->print[list->i] == '.')
	{
		list->i++;
		list->dot = 1;
		if (list->print[list->i] == '*')
		{
			list->dot = 2;
			list->precision = va_arg(list->ap, int);
			list->i++;
		}
		else if (list->print[list->i] >= '0' && list->print[list->i] <= '9')
		{
			list->precision = 0;
			list->precision = ft_atoi(&list->print[list->i], list);
		}
	}
}

void			parser_type(t_list *list)
{
	if (list->print[list->i] == 'd' || list->print[list->i] == 'i')
		display_int(list);
	else if (list->print[list->i] == 'c')
		display_chr(list);
	else if (list->print[list->i] == 's')
		display_str(list);
	else if (list->print[list->i] == 'p')
		display_pointer(list);
	else if (list->print[list->i] == 'u')
		display_u(list);
	else if (list->print[list->i] == 'x')
		display_x(list);
	else if (list->print[list->i] == 'X')
		display_x_cap(list);
	else if (list->print[list->i] == '%')
		display_percent(list);
}

void			ft_parser(t_list *list)
{
	while (list->print[list->i] != '\0')
	{
		while (list->print[list->i] != '%' && list->print[list->i])
		{
			ft_putchr(list->print[list->i], list);
			list->i++;
		}
		if (list->print[list->i] == '%')
		{
			list->i++;
			ft_reinit(list);
			parser_flag(list);
			parser_width(list);
			parser_precision(list);
			parser_type(list);
		}
	}
}
