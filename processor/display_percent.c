/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:22:40 by ctycho            #+#    #+#             */
/*   Updated: 2020/12/10 01:42:17 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		no_flag(t_list *list)
{
	int			m;

	m = 0;
	if (list->width)
		while (m++ < list->width - 1)
			ft_putchr(' ', list);
	ft_putchr('%', list);
	list->i++;
}

static void		flag_minus(t_list *list)
{
	int			m;

	m = 0;
	ft_putchr('%', list);
	list->i++;
	if (list->width)
		while (m++ < list->width - 1)
			ft_putchr(' ', list);
}

static void		flag_zero(t_list *list)
{
	int			m;

	m = 0;
	if (list->width)
		while (m++ < list->width - 1)
			ft_putchr('0', list);
	ft_putchr('%', list);
	list->i++;
}

void			display_percent(t_list *list)
{
	if (!list->minus && !list->zero)
		no_flag(list);
	else if (list->minus)
		flag_minus(list);
	else if (list->zero)
		flag_zero(list);
}
