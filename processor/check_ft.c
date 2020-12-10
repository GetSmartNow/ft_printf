/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 23:02:15 by ilnurgumero       #+#    #+#             */
/*   Updated: 2020/12/10 01:21:43 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_ft(t_list *list)
{
	if (list->precision > list->count)
		list->precision_res = list->precision - list->count;
	if (list->width)
		list->width_res = list->width - list->precision_res - list->count;
	if (list->sign)
		list->width_res--;
}
