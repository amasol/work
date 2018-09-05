/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:07:05 by amasol            #+#    #+#             */
/*   Updated: 2018/09/04 15:07:06 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_flg_x(va_list lst, char *format, t_flg *flg, t_inf *inf)
{
	int			k;
	uintmax_t	i;
	char		*tmp;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'x')
	{
		inf->x = 'x';
		i = (APPLY) ? (cast_uintmax(i, flg)) : (unsigned int)i;
		tmp = ft_itoa_base_uintmax(i, 16, 'x');
		inf->un_j += ft_strlen(tmp);
		free(tmp);
		if (LY)
			entry_min_uint(inf);
		tmp = ft_itoa_base_uintmax(i, 16, 'x');
		cast_flg_x(inf, i, flg, tmp);
		ft_strdel(&tmp);
	}
	return (1);
}

int			ft_flg_u(va_list lst, char *format, t_flg *flg, t_inf *inf)
{
	int			k;
	uintmax_t	i;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'u')
	{
		i = (APPLY) ? (cast_uintmax(i, flg)) : (unsigned int)i;
		inf->un_j = ft_cou_uint(i);
		if (LY)
			entry_min_uint(inf);
		cast_flg_u(inf, i, flg);
	}
	else if (format[k] == 'U')
	{
		i = (unsigned long)i;
		inf->un_j = ft_cou_uint(i);
		if (LY)
			entry_min_uint(inf);
		cast_flg_u(inf, i, flg);
	}
	return (1);
}

int			ft_flg_oo(va_list lst, char *format, t_flg *flg, t_inf *inf)
{
	int			k;
	uintmax_t	i;
	char		*str;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'O')
	{
		i = (unsigned long)i;
		str = ft_itoa_base_uintmax(i, 8, 'X');
		inf->un_j += ft_strlen(str);
		free(str);
		if (LY)
			entry_min_uint(inf);
		str = ft_itoa_base_uintmax(i, 8, 'X');
		cast_flg_x(inf, i, flg, str);
		ft_strdel(&str);
	}
	return (1);
}

int			ft_flg_o(va_list lst, char *format, t_flg *flg, t_inf *inf)
{
	int			k;
	uintmax_t	i;
	char		*str;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'o')
	{
		i = (APPLY) ? (cast_uintmax(i, flg)) : (unsigned int)i;
		str = ft_itoa_base_uintmax(i, 8, 'x');
		inf->un_j += ft_strlen(str);
		free(str);
		if (LY)
			entry_min_uint(inf);
		str = ft_itoa_base_uintmax(i, 8, 'x');
		cast_flg_o(inf, i, flg, str);
		ft_strdel(&str);
	}
	return (1);
}

int			ft_flg_p(va_list lst, char *format, t_flg *flg, t_inf *inf)
{
	int			k;
	uintmax_t	i;
	char		*str;

	k = 0;
	i = va_arg(lst, uintmax_t);
	if (format[k] == 'p')
	{
		str = ft_itoa_base_uintmax(i, 16, 'x');
		inf->un_j += ft_strlen(str);
		free(str);
		if (LY)
			entry_min_uint(inf);
		str = ft_itoa_base_uintmax(i, 16, 'x');
		cast_flg_p(inf, i, flg, str);
		free(str);
	}
	return (1);
}
