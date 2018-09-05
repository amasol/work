/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:19:24 by amasol            #+#    #+#             */
/*   Updated: 2018/08/22 15:19:25 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int g_lob;

void			pars_no_spec(t_flg *flg, t_inf *inf)
{
	inf->wid -= 1;
	if (flg->wid == 1 && flg->min != 1)
	{
		inf->r = (flg->preci == 0) ? inf->r += ps_l(" ", inf->wid) : inf->r;
		inf->r = (inf->wid > 0 && flg->preci == 1 && flg->check_preci == 1)
			? inf->r += ps_l("0", inf->wid) : inf->r;
		inf->r += write(1, "%", 1);
	}
	else if (flg->wid == 1 && flg->min == 1)
	{
		inf->r += write(1, "%", 1);
		inf->r = (inf->wid > 0) ? inf->r += ps_l(" ", inf->wid) : inf->r;
	}
	else if (flg->wid == 0)
		inf->r += write(1, "%", 1);
}

static void		pars_hi_z_h(char *format, t_flg *flg, t_inf *inf)
{
	if (inf->wid > 0 && flg->min == 0 && flg->zero == 1)
	{
		inf->r = (inf->wid > 0) ? inf->r += ps_l("0", inf->wid) : inf->r;
		inf->r += write(1, "Z", 1);
	}
	else
	{
		while (*format)
		{
			ft_putchar(*format);
			inf->r += 1;
			format++;
		}
	}
}

int				pars_hi_z(char *format, t_flg *flg, t_inf *inf, va_list lst)
{
	intmax_t i;

	g_lob = inf->r;
	i = va_arg(lst, intmax_t);
	inf->wid -= 1;
	if (inf->wid > 0 && flg->min == 0 && flg->zero == 0)
	{
		inf->r = (i != 0) ? inf->r += ps_l(" ", inf->wid) : inf->r;
		inf->r += write(1, "Z", 1);
	}
	else if (inf->wid > 0 && flg->min == 1 && flg->zero == 0)
	{
		inf->r += write(1, "Z", 1);
		inf->r = (i != 0) ? inf->r += ps_l(" ", inf->wid) : inf->r;
	}
	if (g_lob < inf->r)
		return (1);
	pars_hi_z_h(format, flg, inf);
	return (0);
}

void			cancellation_flgs_di(t_flg *flg, t_inf *inf)
{
	if (flg->min == 1 && flg->pls == 1)
	{
		inf->tmp = flg->pls;
		flg->pls = 0;
	}
	if ((flg->min == 1 || flg->preci == 1) && flg->zero == 1)
		flg->zero = 0;
}

intmax_t		min_v_di(intmax_t i, t_flg *flg, t_inf *inf)
{
	if (i < 0)
	{
		flg->space = 0;
		flg->pls = 0;
	}
	if ((i < 0 && flg->min == 0) || (i < 0 && flg->min == 1))
	{
		inf->min_v = 1;
		i *= -1;
	}
	return (i);
}
