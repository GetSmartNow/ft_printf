/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 21:55:24 by ctycho            #+#    #+#             */
/*   Updated: 2020/12/10 01:20:53 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_atoi(const char *s, t_list *list)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	res = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (res > INT_MAX)
			return (-1);
		else if (res < INT_MIN)
			return (0);
		res = (res * 10) + (s[i++] - '0');
		list->i++;
	}
	return (res * sign);
}
