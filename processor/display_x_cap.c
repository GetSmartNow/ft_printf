/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x_cap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:18:34 by ctycho            #+#    #+#             */
/*   Updated: 2020/12/10 01:32:40 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_num(t_list *list, int base)
{
	unsigned long res;

	res = list->six;
	if (res < 0)
		list->sign = 1;
	if (res == 0 && list->precision < 0 && list->dot != 1)
		list->count++;
	while (res)
	{
		res = res / base;
		list->count++;
	}
	return (list->count);
}

static void		no_flag(t_list *list)
{
	int m;

	m = 0;
	count_num(list, 16);
	if (list->precision > list->count)
		list->precision_res = list->precision - list->count;
	if (list->width)
		list->width_res = list->width - list->precision_res - list->count;
	while (m++ < list->width_res)
		ft_putchr(' ', list);
	m = 0;
	while (m++ < list->precision_res)
		ft_putchr('0', list);
	if (list->count > 0)
		ft_putnbr_hex(list->six, 16, list, 'A');
	list->i++;
}

static void		flag_minus(t_list *list)
{
	int m;

	m = 0;
	count_num(list, 16);
	if (list->precision > list->count)
		list->precision_res = list->precision - list->count;
	if (list->width)
		list->width_res = list->width - list->precision_res - list->count;
	while (m++ < list->precision_res)
		ft_putchr('0', list);
	if (list->count > 0)
		ft_putnbr_hex(list->six, 16, list, 'A');
	list->i++;
	m = 0;
	while (m++ < list->width_res)
		ft_putchr(' ', list);
}

static void		flag_zero(t_list *list)
{
	int m;

	m = 0;
	count_num(list, 16);
	if (list->precision > list->count)
		list->precision_res = list->precision - list->count;
	if (list->width)
		list->width_res = list->width - list->precision_res - list->count;
	if (list->width && list->precision != -1)
		while (m++ < list->width_res)
			ft_putchr(' ', list);
	else
		while (m++ < list->width_res)
			ft_putchr('0', list);
	m = 0;
	while (m++ < list->precision_res)
		ft_putchr('0', list);
	if (list->count > 0)
		ft_putnbr_hex(list->six, 16, list, 'A');
	list->i++;
}

void			display_x_cap(t_list *list)
{
	list->six = (unsigned int)va_arg(list->ap, int);
	if (!list->minus && !list->zero)
		no_flag(list);
	else if (list->minus)
		flag_minus(list);
	else if (list->zero)
		flag_zero(list);
}
