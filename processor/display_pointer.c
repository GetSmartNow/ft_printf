/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:44:16 by ctycho            #+#    #+#             */
/*   Updated: 2020/12/10 04:38:14 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		count_num_p(t_list *list, unsigned long base)
{
	unsigned long	res;

	res = list->six;
	if (res == 0 && list->precision < 0 && list->dot != 1)
		list->count++;
	while (res)
	{
		res /= base;
		list->count++;
	}
	list->count += 2;
}

static void		no_flag(t_list *list)
{
	int			m;

	m = 0;
	count_num_p(list, 16);
	if (list->precision > list->count)
		list->precision_res = list->precision - list->count + 2;
	if (list->width)
		list->width_res = list->width - list->precision_res - list->count;
	while (m++ < list->width_res)
		ft_putchr(' ', list);
	ft_putchr('0', list);
	ft_putchr('x', list);
	m = 0;
	if (list->precision_res)
		while (m++ < list->precision_res)
			ft_putchr('0', list);
	if (list->count > 2)
		ft_putnbr_hex_p(list->six, 16, list);
	list->i++;
}

static void		flag_minus(t_list *list)
{
	int			m;

	m = 0;
	count_num_p(list, 16);
	if (list->precision > list->count)
		list->precision_res = list->precision - list->count + 2;
	if (list->width)
		list->width_res = list->width - list->precision_res - list->count;
	ft_putchr('0', list);
	ft_putchr('x', list);
	m = 0;
	if (list->precision_res)
		while (m++ < list->precision_res)
			ft_putchr('0', list);
	if (list->count > 2)
		ft_putnbr_hex_p(list->six, 16, list);
	list->i++;
	m = 0;
	while (m++ < list->width_res)
		ft_putchr(' ', list);
}

static void		flag_zero(t_list *list)
{
	int			m;

	count_num_p(list, 16);
	if (list->precision > list->count && !(m = 0))
		list->precision_res = list->precision - list->count + 2;
	if (list->width)
		list->width_res = list->width - list->precision_res - list->count;
	if (list->width && list->precision >= 0)
	{
		while (m++ < list->width_res)
			ft_putchr(' ', list);
		ft_putchr('0', list);
		ft_putchr('x', list);
	}
	else
	{
		ft_putchr('0', list);
		ft_putchr('x', list);
		while (m++ < list->width_res)
			ft_putchr('0', list);
	}
	m = 0;
	while (m++ < list->precision_res)
		ft_putchr('0', list);
	list->count > 2 && list->i++ ? ft_putnbr_hex_p(list->six, 16, list) : 0;
}

void			display_pointer(t_list *list)
{
	list->six = va_arg(list->ap, unsigned long);
	if (!list->minus && !list->zero)
		no_flag(list);
	else if (list->minus)
		flag_minus(list);
	else if (list->zero)
		flag_zero(list);
}
