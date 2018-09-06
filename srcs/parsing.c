/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:19:18 by amasol            #+#    #+#             */
/*   Updated: 2018/05/08 17:19:20 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		parsing_h(char *str, va_list lst, t_inf *inf, t_flg *flg)
{
	int i;

	i = 0;
	while (!(ft_qualifier(str[i])))
	{
		inf->nothi = 1;
		if (is_check_specs(str[i]))
			break ;
		if (inf->wid_t == 0)
			parsing_four(str, flg, inf);
		if (inf->wid == 0)
			parsing_three(&str[i], inf, flg);
		if (inf->cou_three == 0)
			parsing_five(&str[i], inf, flg);
		if (inf->wid == 0)
			parsing_three(&str[i], inf, flg);
		i++;
	}
	if (ft_qualifier(str[i]))
		pars_spec(&str[i], lst, flg, inf);
	output_after(&str[i], lst, flg, inf);
	inf->cou_format += i;
}

void			parsing(char *str, va_list lst, t_inf *inf)
{
	int		i;
	t_flg	flg;

	i = 0;
	if (str[i])
	{
		initialization_flg(&flg, inf);
		parsing_one(&str[i], &flg);
		parsing_two(&str[i], &flg);
	}
	parsing_h(str, lst, inf, &flg);
}

void			parsing_one(char *str, t_flg *flg)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '%' && !ft_qualifier(str[i]))
	{
		if (str[i] == '+')
			flg->pls = 1;
		if (str[i] == '-')
			flg->min = 1;
		if (str[i] == '#')
			flg->slash = 1;
		if (str[i] == ' ')
			flg->space = 1;
		if (!is_zero(str))
			flg->zero = 1;
		if (str[i] == '.' || (ft_isdigit(str[i]) && str[i + 1] == '.'))
		{
			is_check_preci(&str[i], flg);
			flg->preci = 1;
		}
		if (ft_isdigit(str[i]))
			flg->wid = 1;
		i++;
	}
}

void			parsing_two(char *str, t_flg *flg)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '%')
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
		{
			flg->hh = 1;
			i++;
		}
		else if (str[i] == 'h')
			flg->h = 1;
		else if (str[i] == 'l' && str[i + 1] == 'l')
		{
			flg->ll = 1;
			i++;
		}
		else if (str[i] == 'l')
			flg->l = 1;
		else if (str[i] == 'j')
			flg->j = 1;
		else if (str[i] == 'z')
			flg->z = 1;
		i++;
	}
}

void			parsing_three(char *str, t_inf *inf, t_flg *flg)
{
	int i;

	i = 0;
	flg->zero_preci = 0;
	if ((ft_flg_check((*str)) || ft_isdigit(*str)) && flg->preci == 1)
	{
		while (*str != '.')
			str++;
		if (ft_isdigit(str[i + 1]) && flg->preci == 1)
		{
			inf->wid = ft_atoi(&str[i + 1]);
			flg->zero_preci = 1;
		}
	}
	while (str[i] == '0' && ft_flg_check(str[i]))
		i++;
	if (str[i] >= '1' && str[i] <= '9')
	{
		inf->wid = ft_atoi(&str[i]);
		inf->cou_four = 1;
	}
	while (ft_flg_check(*str))
		str++;
}
