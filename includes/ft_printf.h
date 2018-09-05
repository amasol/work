/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:07:40 by amasol            #+#    #+#             */
/*   Updated: 2018/04/12 14:07:42 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define APPLY (flg->hh || flg->h || flg->l || flg->ll || flg->j || flg->z)
# define LY (inf->wid  || inf->wid_t || flg->zero)

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

typedef struct	s_flg
{
	int			pls;
	int			min;
	int			slash;
	int			space;
	int			zero;
	int			wid;
	int			preci;
	int			check_preci;
	int			zero_preci;
	int			nothi_flg;
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_flg;

typedef struct	s_inf
{
	int			nothi;
	char		x;
	int			wid;
	int			wid_t;
	int			cou;
	int			cou_t;
	int			cou_three;
	int			cou_four;
	int			tmp;
	int			cou_format;
	int			min_v;
	int			r;
	int			r_h;
	int			un_j;
	int			intm_j;
}				t_inf;

int				ft_printf(const char *format, ...);
void			initialization_flg(t_flg *flg, t_inf *inf);
void			pars_spec(char *format, va_list lst, t_flg *flg, t_inf *inf);
void			pars_no_spec(t_flg *flg, t_inf *inf);
int				pars_hi_z(char *format, t_flg *flg, t_inf *inf, va_list lst);
int				ft_qualifier(char s);
intmax_t		min_v_di(intmax_t i, t_flg *flg, t_inf *inf);
intmax_t		cast_intmax(intmax_t i, t_flg *flg);
uintmax_t		cast_uintmax(uintmax_t i, t_flg *flg);
intmax_t		entry_min_intm(intmax_t i, t_inf *inf, t_flg *flg);
void			entry_min_uint(t_inf *inf);
/*
** -------------------------- Functions multi-descriptors--------------------
*/
int				cast_flg_di(t_inf *inf, intmax_t i,
					t_flg *flg, char *format);
void			cast_flg_u(t_inf *inf, uintmax_t i, t_flg *flg);
int				cast_flg_x(t_inf *inf, uintmax_t i, t_flg *flg, char *str);
int				cast_flg_o(t_inf *inf, uintmax_t i, t_flg *flg, char *str);
int				cast_flg_s(t_inf *inf, t_flg *flg, char *format);
int				cast_flg_ss(t_inf *inf, t_flg *flg, wchar_t *str);
void			cast_flg_c(t_inf *inf, t_flg *flg, char format);
void			cast_flg_cc(t_inf *inf, t_flg *flg, wchar_t c);
int				cast_flg_p(t_inf *inf, uintmax_t i,
					t_flg *flg, char *format);
void			cancellation_flgs_di(t_flg *flg, t_inf *inf);
int				ft_refinement(char s);
int				ft_flg_di(va_list lst, char *format, t_flg *flg, t_inf *inf);
int				ft_flg_dd(va_list lst, char *format, t_flg *flg, t_inf *inf);
int				ft_flg_s(va_list lst, char *format, t_flg *flg, t_inf *inf);
int				ft_flg_ss(va_list lst, char *format, t_flg *flg, t_inf *inf);
int				ft_flg_c(va_list lst, char *format, t_flg *flg, t_inf *inf);
int				ft_flg_cc(va_list lst, char *format, t_flg *flg, t_inf *inf);
int				ft_flg_x(va_list lst, char *format, t_flg *flg, t_inf *inf);
int				ft_flg_xx(va_list lst, char *format, t_flg *flg, t_inf *inf);
int				ft_flg_u(va_list lst, char *format, t_flg *flg, t_inf *inf);
int				ft_flg_o(va_list lst, char *format, t_flg *flg, t_inf *inf);
int				ft_flg_oo(va_list lst, char *format, t_flg *flg, t_inf *inf);
int				ft_flg_p(va_list lst, char *format, t_flg *flg, t_inf *inf);
/*
** -------------------------- Parsing Functions -------------------------------
*/
void			parsing(char *str, va_list lst, t_inf *inf);
void			parsing_one(char *str, t_flg *flg);
void			parsing_two(char *str, t_flg *flg);
void			parsing_three(char *str, t_inf *inf, t_flg *flg);
void			parsing_four(char *str, t_flg *flg, t_inf *inf);
void			parsing_five(char *str, t_inf *inf, t_flg *flg);
int				ft_flg_check(char c);
int				output_after(char *format, va_list lst,
					t_flg *flg, t_inf *inf);
int				is_zero(char *str);
int				is_check_specs(char s);
int				is_check_preci(char *str, t_flg *flg);
int				cast_flg_di_h5(t_inf *inf, intmax_t i, t_flg *flg);
int				cast_flg_p_h5(t_inf *inf, t_flg *flg, char *str);
int				cast_flg_s_h5(t_inf *inf, t_flg *flg, char *str, char *tmp);
int				cast_flg_ss_h5(t_inf *inf, t_flg *flg, wchar_t *str);
int				cast_flg_x_h5(t_inf *inf, uintmax_t i,
					t_flg *flg, char *str);
/*
** -------------------------- Functions libft-------------------------------
*/
int				ft_atoi(const char *str);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char const *str);
int				ps_l(char const *str, int i);
void			ft_strdel(char **as);
size_t			ft_strlen(const char *s);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
void			ft_strdel(char **as);
int				ft_isdigit(int c);
int				ft_isspace(int c);
char			*ft_strnew(size_t size);
void			ft_bzero(void *s, size_t n);
int				ft_isspace(int c);
void			ft_putwchar(wchar_t c, t_inf *inf);
int				ft_lenwchar(wchar_t c);
char			*ft_itoa_base_uintmax(uintmax_t nbr, unsigned base, char c);
intmax_t		ft_putnbr_intmax(intmax_t nb);
uintmax_t		ft_putnbr_uintmax_t(uintmax_t nb);
uintmax_t		ft_strlen_uintmax(const char *s);
/*
** -------------------------- Functions help-------------------------------
*/
intmax_t		ft_cou_int(intmax_t n);
uintmax_t		ft_cou_uint(uintmax_t n);

#endif
