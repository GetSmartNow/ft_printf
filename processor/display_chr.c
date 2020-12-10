/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_chr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 01:22:49 by ctycho            #+#    #+#             */
/*   Updated: 2020/12/10 01:22:53 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			no_flag(t_list *list)
{
	int m;

	m = 0;
	list->type = va_arg(list->ap, int);
	if (list->width)
		list->width_res = list->width - 1;
	while (m++ < list->width_res)
		ft_putchr(' ', list);
	ft_putchr(list->type, list);
	list->i++;
}

static void			flag_minus(t_list *list)
{
	int m;

	m = 0;
	list->type = va_arg(list->ap, int);
	if (list->width)
		list->width_res = list->width - 1;
	ft_putchr(list->type, list);
	list->i++;
	while (m++ < list->width_res)
		ft_putchr(' ', list);
}

void				display_chr(t_list *list)
{
	if (!list->minus && !list->zero)
		no_flag(list);
	else if (list->minus)
		flag_minus(list);
}
