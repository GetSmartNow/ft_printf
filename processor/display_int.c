/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:14:22 by ctycho            #+#    #+#             */
/*   Updated: 2020/12/10 01:39:13 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_num(t_list *list)
{
	int res;

	res = list->type;
	if (res < 0)
		list->sign = 1;
	if (res == 0 && list->precision < 0 && list->dot != 1)
		list->count++;
	while (res)
	{
		res = res / 10;
		list->count++;
	}
	return (list->sign);
}

static void		no_flag(t_list *list)
{
	int		m;

	m = 0;
	list->type = va_arg(list->ap, int);
	count_num(list);
	check_ft(list);
	while (m++ < list->width_res)
		ft_putchr(' ', list);
	if (list->sign)
		ft_putchr('-', list);
	m = 0;
	if (list->precision_res)
		while (m++ < list->precision_res)
			ft_putchr('0', list);
	if (list->type < 0)
		list->type = list->type * -1;
	if (list->count > 0)
		ft_putnbr(list->type, list);
	list->i++;
}

static void		flag_minus(t_list *list)
{
	int		m;

	m = 0;
	list->type = va_arg(list->ap, int);
	count_num(list);
	check_ft(list);
	if (list->sign)
		ft_putchr('-', list);
	if (list->precision_res)
		while (m++ < list->precision_res)
			ft_putchr('0', list);
	if (list->count > 0)
		ft_putnbr(list->type, list);
	list->i++;
	m = 0;
	while (m++ < list->width_res)
		ft_putchr(' ', list);
}

static void		flag_zero(t_list *list)
{
	int		m;

	m = 0;
	list->type = va_arg(list->ap, int);
	count_num(list);
	check_ft(list);
	if (list->width && list->precision >= 0)
	{
		while (m++ < list->width_res)
			ft_putchr(' ', list);
		(list->sign) ? ft_putchr('-', list) : 0;
	}
	else
	{
		if (list->sign)
			ft_putchr('-', list);
		while (m++ < list->width_res)
			ft_putchr('0', list);
	}
	m = 0;
	while (m++ < list->precision_res)
		ft_putchr('0', list);
	if (list->count > 0)
		ft_putnbr(list->type, list);
	list->i++;
}

void			display_int(t_list *list)
{
	if (!list->minus && !list->zero)
		no_flag(list);
	else if (list->minus)
		flag_minus(list);
	else if (list->zero)
		flag_zero(list);
}
