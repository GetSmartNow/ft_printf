/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 08:59:31 by ctycho            #+#    #+#             */
/*   Updated: 2020/12/09 21:53:12 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char *format, ...)
{
	t_list		*list;

	if (!format)
		return (-1);
	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	list->print = format;
	ft_init(list);
	va_start(list->ap, format);
	ft_parser(list);
	va_end(list->ap);
	free(list);
	return (list->total);
}
