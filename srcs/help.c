/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:04:58 by amasol            #+#    #+#             */
/*   Updated: 2018/09/03 18:04:59 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			cast_flg_di_h5(t_inf *inf, intmax_t i, t_flg *flg)
{
	if (flg->space == 1 && flg->preci != 1 && i > 0 && inf->nothi == 1)
	{
		inf->r += write(1, " ", 1);
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
	else if (flg->slash == 0 &&
		flg->zero == 0 && flg->wid == 0 && flg->preci == 0)
	{
		if ((inf->min_v == 1 || flg->min == 1) && i != LONG_MIN && i > 0)
			inf->r += write(1, "-", 1);
		else if (inf->min_v == 1 && i == -1)
			inf->r += 1;
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
	else if (inf->nothi == 0)
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	return (0);
}

int			cast_flg_p_h5(t_inf *inf, t_flg *flg, char *str)
{
	if (flg->pls == 0 && flg->slash == 0 && flg->zero == 0
		&& flg->wid == 0 && flg->preci == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		inf->r += write(1, "0x", 2);
		ft_putstr(str);
	}
	return (0);
}

int			cast_flg_s_h5(t_inf *inf, t_flg *flg, char *str, char *tmp)
{
	if ((flg->pls == 1 && flg->preci == 0 && inf->wid == 0)
		|| (flg->space == 1 && flg->preci != 1)
		|| (flg->preci == 1 && inf->cou_t == 0 && *str == '\0'))
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if (flg->preci == 1 && flg->min == 1)
	{
		tmp = ft_strsub(str, 0, inf->wid);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		inf->r = (inf->cou > 0 && *str == '\0')
				? inf->r += ps_l(" ", inf->cou) : inf->r;
		inf->r = (inf->cou_t > 0 && flg->min == 1)
				? inf->r += ps_l(" ", inf->cou_t) : inf->r;
		ft_strdel(&tmp);
	}
	else if (inf->nothi == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	return (0);
}

int			cast_flg_ss_h5(t_inf *inf, t_flg *flg, wchar_t *str)
{
	int i;

	i = 0;
	if ((flg->space == 1 || flg->pls == 1)
			|| (flg->preci == 1 || flg->l == 1) || (flg->wid == 0))
	{
		while (str[i])
			ft_putwchar(str[i++], inf);
	}
	return (0);
}

uintmax_t	ft_cou_uint(uintmax_t n)
{
	uintmax_t i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
