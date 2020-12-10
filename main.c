/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 03:41:16 by ctycho            #+#    #+#             */
/*   Updated: 2020/12/10 04:36:02 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int			main(void)
{
	// ft_printf("--------------------%%p--------------------\n");
	// printf("01) standart PRINTF : |%p|\n", "salut");
	// ft_printf("01) my       PRINTF : |%p|\n", "salut");
	// printf("03) standart PRINTF : |%---------p|\n", "test2");
	// ft_printf("03) my       PRINTF : |%----------p|\n", "test2");
	// printf("04) standart PRINTF : |%10p|\n", "42");
	// ft_printf("04) my       PRINTF : |%10p|\n", "42");
	// printf("05) standart PRINTF : |%-10p|\n", "42");
	// ft_printf("05) my       PRINTF : |%-10p|\n", "42");
	// printf("08) standart PRINTF : |%p|\n", "\0\0\0\0\0");
	// ft_printf("08) my       PRINTF : |%p|\n", "\0\0\0\0\0");
	// printf("09) standart PRINTF : |%20p|\n", "\0\0\0\0\0");
	// ft_printf("09) my       PRINTF : |%20p|\n", "\0\0\0\0\0");
	// printf("10) standart PRINTF : |%p|\n", "");
	// ft_printf("10) my       PRINTF : |%p|\n", "");
	// printf("11) standart PRINTF : |%p|\n", NULL);
	// ft_printf("11) my       PRINTF : |%p|\n", NULL);
	// printf("12) standart PRINTF : |%10p|\n", NULL);
	// ft_printf("12) my       PRINTF : |%10p|\n", NULL);
	// printf("13) standart PRINTF : |%-10p|\n", NULL);
	// ft_printf("13) my       PRINTF : |%-10p|\n", NULL);
	printf("st)hello |%-20.15p|\n", "456");
	ft_printf("my)hello |%-20.15p|\n", "456");
	printf("st)hello |%20.15p|\n", "456");
	ft_printf("my)hello |%20.15p|\n", "456");
}