/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_flag_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:34:23 by amasol            #+#    #+#             */
/*   Updated: 2018/09/04 15:34:24 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_flg_c(va_list lst, char *format, t_flg *flg, t_inf *inf)
{
	unsigned char	str;

	if (*format == 'c' || (*format == 'C' && MB_CUR_MAX == 1))
	{
		if (flg->l == 1)
		{
			ft_flg_cc(lst, format, flg, inf);
			return (1);
		}
		else
			str = va_arg(lst, unsigned int);
		inf->un_j += 1;
		cast_flg_c(inf, flg, str);
	}
	return (1);
}

int			ft_flg_cc(va_list lst, char *format, t_flg *flg, t_inf *inf)
{
	wchar_t c;

	if (*format == 'C' && MB_CUR_MAX == 1)
	{
		ft_flg_c(lst, format, flg, inf);
		return (1);
	}
	else if (*format == 'C' || (*format == 'c' && flg->l == 1))
	{
		c = va_arg(lst, wchar_t);
		cast_flg_cc(inf, flg, c);
	}
	return (1);
}

int			ft_flg_s(va_list lst, char *format, t_flg *flg, t_inf *inf)
{
	int		i;
	char	*str;

	i = 0;
	if (format[i] == 's' || (*format == 'S' && MB_CUR_MAX == 1))
	{
		if (flg->l == 1)
		{
			ft_flg_ss(lst, format, flg, inf);
			return (1);
		}
		else if (*format == 'S' && MB_CUR_MAX == 1)
			str = va_arg(lst, char *);
		else
			str = va_arg(lst, char *);
		if (str == NULL)
		{
			cast_flg_s(inf, flg, str);
			return (1);
		}
		inf->un_j += ft_strlen(str);
		cast_flg_s(inf, flg, str);
	}
	return (1);
}

int			ft_flg_ss(va_list lst, char *format, t_flg *flg, t_inf *inf)
{
	wchar_t		*sstr;

	if (*format == 'S' && MB_CUR_MAX == 1)
	{
		ft_flg_s(lst, format, flg, inf);
		return (1);
	}
	if (*format == 'S' || (*format == 's' && flg->l == 1))
	{
		sstr = va_arg(lst, wchar_t *);
		if (sstr == NULL)
		{
			cast_flg_ss(inf, flg, sstr);
			return (1);
		}
		cast_flg_ss(inf, flg, sstr);
	}
	return (1);
}

int			ft_flg_xx(va_list lst, char *format, t_flg *flg, t_inf *inf)
{
	int			k;
	uintmax_t	i;
	char		*tmp;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'X')
	{
		inf->x = 'X';
		i = (APPLY) ? (cast_uintmax(i, flg)) : (unsigned int)i;
		tmp = ft_itoa_base_uintmax(i, 16, 'X');
		inf->un_j += ft_strlen(tmp);
		free(tmp);
		if (LY)
			entry_min_uint(inf);
		tmp = ft_itoa_base_uintmax(i, 16, 'X');
		cast_flg_x(inf, i, flg, tmp);
		ft_strdel(&tmp);
	}
	return (1);
}
