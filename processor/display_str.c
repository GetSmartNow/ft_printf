/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:30:34 by ctycho            #+#    #+#             */
/*   Updated: 2020/12/10 01:44:51 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		check_str(t_list *list)
{
	if (list->precision == -1 && list->dot == 1)
		list->str_len = 0;
	if (list->precision < list->str_len && list->precision != -1)
		list->str_len = list->precision;
	if (list->precision < 0 && list->dot == 2)
		list->str_len = ft_strlen(list->s);
	if (list->width)
		list->width_res = list->width - list->str_len;
}

static void		no_flag(t_list *list)
{
	int m;

	m = 0;
	list->str_len = ft_strlen(list->s);
	check_str(list);
	while (m++ < list->width_res)
		ft_putchr(' ', list);
	ft_putstr(list);
	list->i++;
}

static void		flag_minus(t_list *list)
{
	int m;

	m = 0;
	list->str_len = ft_strlen(list->s);
	check_str(list);
	ft_putstr(list);
	list->i++;
	while (m++ < list->width_res)
		ft_putchr(' ', list);
}

static void		flag_zero(t_list *list)
{
	int m;

	m = 0;
	list->str_len = ft_strlen(list->s);
	check_str(list);
	while (m++ < list->width_res)
		ft_putchr('0', list);
	ft_putstr(list);
	list->i++;
}

void			display_str(t_list *list)
{
	list->s = va_arg(list->ap, char *);
	if (list->s == NULL)
		list->s = "(null)";
	if (!list->minus && !list->zero)
		no_flag(list);
	else if (list->minus)
		flag_minus(list);
	else if (list->zero)
		flag_zero(list);
}
