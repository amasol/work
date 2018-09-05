/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:43:08 by amasol            #+#    #+#             */
/*   Updated: 2018/06/21 16:43:09 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	ft_putnbr_intmax(intmax_t nb)
{
	char c;

	if (nb == LONG_MIN)
	{
		ft_putstr("-9223372036854775808");
		return (nb);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_intmax(nb / 10);
		ft_putnbr_intmax((nb % 10));
	}
	if (nb < 10)
	{
		c = nb + 48;
		write(1, &c, 1);
	}
	return (nb);
}

uintmax_t	ft_putnbr_uintmax_t(uintmax_t nb)
{
	char c;

	if ((unsigned long)nb == ULONG_MAX)
	{
		ft_putstr("18446744073709551615");
		return (nb);
	}
	if (nb > 9)
	{
		ft_putnbr_uintmax_t(nb / 10);
		ft_putnbr_uintmax_t((nb % 10));
	}
	if (nb < 10)
	{
		c = nb + 48;
		write(1, &c, 1);
	}
	return (nb);
}
