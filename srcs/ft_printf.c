/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:21:09 by amasol            #+#    #+#             */
/*   Updated: 2018/05/16 15:06:23 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_printf_h(char *format, va_list lst, t_inf *inf)
{
	while (*format != '\0')
	{
		inf->r_h += inf->r;
		inf->r = 0;
		if (*format == '%' && *(format + 1) != '%')
		{
			format++;
			parsing(format, lst, inf);
			format += inf->cou_format;
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			inf->r += write(1, "%", 1);
			format += 2;
		}
		else if (inf->zz == 1)
		{
			format++;
			inf->zz = 0;
		}
		else
		{
			ft_putchar(*format);
			inf->r += 1;
			format++;
		}
	}
	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list	lst;
	t_inf	inf;

	inf.r = 0;
	inf.r_h = 0;
	va_start(lst, format);
	while (*format != '%' && *format != '\0')
	{
		inf.r += write(1, format, 1);
		format++;
	}
		if (*format == '%' && *(format + 1) == 0)
		return (inf.r);
	ft_printf_h((char *)format, lst, &inf);
	inf.r += inf.r_h;
	va_end(lst);
	return (inf.r);
}
