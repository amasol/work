/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:49:03 by amasol            #+#    #+#             */
/*   Updated: 2018/07/16 17:49:09 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	pars_spec_h2(char *format, va_list lst, t_flg *flg, t_inf *inf)
{
	int i;

	i = 0;
	if (ft_refinement(format[i]) == 6)
		ft_flg_u(lst, &format[i], flg, inf);
	else if (ft_refinement(format[i]) == 7)
		ft_flg_p(lst, &format[i], flg, inf);
	else if (format[i] == '%')
		pars_no_spec(flg, inf);
}

static void	pars_spec_h(char *format, va_list lst, t_flg *flg, t_inf *inf)
{
	int i;

	i = 0;
	if (ft_refinement(format[i]) == 3)
	{
		if (format[i] == 's' || (*format == 's' && flg->l == 1))
			ft_flg_s(lst, &format[i], flg, inf);
		else
			ft_flg_ss(lst, &format[i], flg, inf);
	}
	else if (ft_refinement(format[i]) == 4)
	{
		if (format[i] == 'x')
			ft_flg_x(lst, &format[i], flg, inf);
		else
			ft_flg_xx(lst, &format[i], flg, inf);
	}
	else if (ft_refinement(format[i]) == 5)
	{
		if (format[i] == 'o')
			ft_flg_o(lst, &format[i], flg, inf);
		else
			ft_flg_oo(lst, &format[i], flg, inf);
	}
	pars_spec_h2(&format[i], lst, flg, inf);
}

void		pars_spec(char *format, va_list lst, t_flg *flg, t_inf *inf)
{
	int	i;

	i = 0;
	if (format[i])
	{
		if (ft_qualifier(format[i]))
		{
			if (ft_refinement(format[i]) == 1)
			{
				if (format[i] == 'd' || format[i] == 'i')
					ft_flg_di(lst, &format[i], flg, inf);
				else
					ft_flg_dd(lst, &format[i], flg, inf);
			}
			else if (ft_refinement(format[i]) == 2)
			{
				if (format[i] == 'c' || (*format == 'c' && flg->l == 1))
					ft_flg_c(lst, &format[i], flg, inf);
				else
					ft_flg_cc(lst, &format[i], flg, inf);
			}
			pars_spec_h(&format[i], lst, flg, inf);
		}
	}
}

int			ft_flg_dd(va_list lst, char *format, t_flg *flg, t_inf *inf)
{
	int			k;
	intmax_t	j;

	k = 0;
	j = 0;
	if (format[k] == 'D')
	{
		if (flg->hh)
			j = (unsigned short)va_arg(lst, int);
		else
			j = va_arg(lst, long);
		min_v_di(j, flg, inf);
		cancellation_flgs_di(flg, inf);
		if (LY)
			entry_min_intm(j, inf, flg);
		cast_flg_di(inf, j, flg, format);
	}
	return (1);
}

int			ft_flg_di(va_list lst, char *format, t_flg *flg, t_inf *inf)
{
	int			k;
	intmax_t	i;

	k = 0;
	i = 0;
	if (format[k] == 'd' || format[k] == 'i')
	{
		i = va_arg(lst, intmax_t);
		i = (APPLY) ? (cast_intmax(i, flg)) : (int)i;
		i = min_v_di(i, flg, inf);
		cancellation_flgs_di(flg, inf);
		if (LY)
			entry_min_intm(i, inf, flg);
		cast_flg_di(inf, i, flg, format);
	}
	return (1);
}
