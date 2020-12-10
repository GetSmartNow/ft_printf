/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctycho <ctycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 01:47:07 by ctycho            #+#    #+#             */
/*   Updated: 2020/12/10 01:47:11 by ctycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_list
{
	va_list				ap;
	char				*print;
	int					minus;
	int					zero;
	int					width;
	int					width_res;
	int					precision;
	int					precision_res;
	int					dot;
	int					type;
	char				*s;
	int					str_len;
	int					i;
	int					count;
	int					total;
	int					sign;
	unsigned long		six;
}				t_list;

int				ft_printf(char *format, ...);
void			ft_init(t_list *list);
void			ft_reinit(t_list *list);
void			ft_parser(t_list *list);
void			ft_putchr(char c, t_list *list);
size_t			ft_strlen(const char *str);
void			ft_putnbr(int n, t_list *list);
void			ft_putnbr_u(unsigned int n, t_list *list);
void			ft_putnbr_hex(unsigned int n, unsigned int base,
				t_list *list, char c);
void			ft_putnbr_hex_p(unsigned long n, unsigned int base,
				t_list *list);
void			ft_putstr(t_list *list);
int				ft_atoi(const char *s, t_list *list);
void			check_ft(t_list *list);
void			display_int(t_list *list);
void			display_chr(t_list *list);
void			display_str(t_list *list);
void			display_pointer(t_list *list);
void			display_u(t_list *list);
void			display_x(t_list *list);
void			display_x_cap(t_list *list);
void			display_percent(t_list *list);

#endif
