/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:51:31 by amasol            #+#    #+#             */
/*   Updated: 2018/09/05 19:51:32 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			cast_flg_ss_h6(t_inf *inf, wchar_t *str)
{
	int i;

	i = 0;
	inf->w_ch = 0;
	while (inf->wid > inf->cou)
	{
		inf->w_ch = 0;
		inf->cou += ft_lenwchar(str[i], inf);
		if (inf->wid < inf->cou)
		{
			inf->cou -= inf->w_ch;
			break ;
		}
	}
	inf->cou_t = (inf->wid_t > inf->cou) ? inf->wid_t - inf->cou : 0;
	inf->r = (inf->cou_t > 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
}
