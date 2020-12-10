/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:30:34 by ctycho            #+#    #+#             */
/*   Updated: 2020/12/10 01:39:27 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr(int n, t_list *list)
{
	int		res;
	long	i;

	res = 0;
	i = n;
	if (i < 0)
		i = -i;
	if (i <= 9)
	{
		res = i + '0';
		write(1, &res, 1);
		list->total++;
	}
	else
	{
		ft_putnbr(i / 10, list);
		ft_putnbr(i % 10, list);
	}
}

void		ft_putnbr_u(unsigned int n, t_list *list)
{
	int		res;
	long	i;

	res = 0;
	i = n;
	if (i < 0)
		i = -i;
	if (i <= 9)
	{
		res = i + '0';
		write(1, &res, 1);
		list->total++;
	}
	else
	{
		ft_putnbr(i / 10, list);
		ft_putnbr(i % 10, list);
	}
}

void		ft_putnbr_hex_p(unsigned long n, unsigned int base, t_list *list)
{
	int		res;

	res = 0;
	if (n < base)
	{
		res = n + '0';
		if (n > 9)
			res = n + 87;
		write(1, &res, 1);
		list->total++;
	}
	else
	{
		ft_putnbr_hex_p(n / base, base, list);
		ft_putnbr_hex_p(n % base, base, list);
	}
}

void		ft_putnbr_hex(unsigned int n, unsigned int base, \
			t_list *list, char c)
{
	int		res;

	res = 0;
	if (n < base)
	{
		res = n + '0';
		if (n > 9)
			res = n + c - 10;
		write(1, &res, 1);
		list->total++;
	}
	else
	{
		ft_putnbr_hex(n / base, base, list, c);
		ft_putnbr_hex(n % base, base, list, c);
	}
}

void		ft_putchr(char c, t_list *list)
{
	write(1, &c, 1);
	list->total++;
}
