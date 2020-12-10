/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:43:30 by ctycho            #+#    #+#             */
/*   Updated: 2020/12/10 01:20:39 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_reinit(t_list *list)
{
	list->count = 0;
	list->sign = 0;
	list->minus = 0;
	list->zero = 0;
	list->width = 0;
	list->width_res = 0;
	list->precision = -1;
	list->precision_res = 0;
	list->dot = 0;
	list->type = 0;
	list->s = "\0";
	list->str_len = 0;
}
