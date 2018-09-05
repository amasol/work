/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_b_uintmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:51:56 by amasol            #+#    #+#             */
/*   Updated: 2018/08/31 15:51:57 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int		cou(uintmax_t nbr, unsigned base)
{
	int			i;
	uintmax_t	tmp;

	i = 1;
	tmp = nbr;
	while (tmp >= base)
	{
		tmp /= base;
		i++;
	}
	return (i);
}

static	void	transform_b(char *str, char c)
{
	int j;

	j = 0;
	if (c == 'X')
	{
		while (str[j])
		{
			if (str[j] >= 'a' && str[j] <= 'z')
				str[j] -= 32;
			j++;
		}
	}
}

static	void	ft_bukv_m(uintmax_t nbr, int len, char *str)
{
	if (nbr == 10)
		str[len] = 'a';
	if (nbr == 11)
		str[len] = 'b';
	if (nbr == 12)
		str[len] = 'c';
	if (nbr == 13)
		str[len] = 'd';
	if (nbr == 14)
		str[len] = 'e';
	if (nbr == 15)
		str[len] = 'f';
}

static	void	transform(uintmax_t nbr, int len, unsigned base, char *str)
{
	while (nbr >= base)
	{
		if (nbr % base >= 10 && nbr % base <= 15 && base > 10)
			ft_bukv_m(nbr % base, len, str);
		else
			str[len] = nbr % base + 48;
		nbr /= base;
		len--;
	}
	if (nbr % base >= 10 && nbr % base <= 15 && base > 10)
		ft_bukv_m(nbr % base, len, str);
	else
		str[len] = nbr % base + 48;
}

char			*ft_itoa_base_uintmax(uintmax_t nbr, unsigned base, char c)
{
	char	*str;
	int		len;

	len = cou(nbr, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	transform(nbr, len, base, str);
	transform_b(str, c);
	return (str);
}
