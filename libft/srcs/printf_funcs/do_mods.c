/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:30:04 by yserkez           #+#    #+#             */
/*   Updated: 2019/01/26 11:51:13 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	shift_sign(char **ret, char **add)
{
	if (*ret[0] == '-' || *ret[0] == '+')
	{
		*add[0] = *ret[0];
		*ret[0] = '0';
	}
	else if (ft_strnstr(*ret, "0x", 2) || ft_strnstr(*ret, "0X", 2))
	{
		ft_strncpyn(add, *ret, 2);
		*ret = ft_memset(*ret, '0', 2);
	}
}

void	mod_width(char **ret, int len)
{
	char	*add;
	char	fill;

	add = NULL;
	len = g_width - len;
	if (hash_check(g_conv_table, 'c') && !(*ret[0]))
		--len;
	if (len < 1)
		return ;
	if (hash_check(g_flag_table, '0') && !hash_check(g_flag_table, '-') &&
			(hash_check(g_conv_table, 'c') || g_precision == -1))
		fill = '0';
	else
		fill = ' ';
	add = ft_chartostr(fill, len);
	if (fill == '0')
		shift_sign(ret, &add);
	if (hash_check(g_flag_table, '-'))
		*ret = ft_strjoin(ret, add);
	else
		*ret = ft_strjoinr(add, ret);
	add != NULL ? ft_memdel((void**)&add) : 0;
}

void	mod_prec(char **ret)
{
	char	*tmp;

	tmp = NULL;
	if (g_precision == 0 && ft_strequ(*ret, "0"))
	{
		free(*ret);
		*ret = "";
	}
	else if (hash_check(g_conv_table, 'o') || hash_check(g_conv_table, 'd') ||
		hash_check(g_conv_table, 'i') || hash_check(g_conv_table, 'u'))
	{
		if (**ret == '-' && (g_precision >= (int)ft_strlen(*ret)))
		{
			g_precision++;
			tmp = ft_chartostr('0', g_precision - ft_strlen(*ret));
			shift_sign(ret, &tmp);
		}
		else if (g_precision >= (int)ft_strlen(*ret))
			tmp = ft_chartostr('0', g_precision - ft_strlen(*ret));
		*ret = ft_strjoinr(tmp, ret);
	}
	else if (hash_check(g_conv_table, 's'))
		(tmp = *ret) ?
		(*ret = ft_strsub(*ret, 0, g_precision)) : 0;
	tmp != NULL ? ft_memdel((void**)&tmp) : 0;
}

void	mod_hash(char **ret)
{
	if (ft_strcmp(*ret, "0") == 0 && !hash_check(g_conv_table, 'p'))
		;
	else if (hash_check(g_conv_table, 'o'))
		*ret = ft_strjoinr("0", ret);
	else if (hash_check(g_conv_table, 'x') || hash_check(g_conv_table, 'p'))
		*ret = ft_strjoinr("0x", ret);
	else if (hash_check(g_conv_table, 'X'))
		*ret = ft_strjoinr("0X", ret);
}

void	do_mods(char **ret)
{
	if (g_precision != -1)
		mod_prec(ret);
	if (hash_check(g_conv_table, 'i') || hash_check(g_conv_table, 'd'))
	{
		if (*ret[0] != '-' && (hash_check(g_flag_table, '+') ||
			hash_check(g_flag_table, ' ')))
			hash_check(g_flag_table, '+') ? (*ret = ft_strjoinr("+", ret)) :
			(*ret = ft_strjoinr(" ", ret));
	}
	else if (hash_check(g_conv_table, 'p') || ((((hash_check(g_conv_table, 'x')
			|| hash_check(g_conv_table, 'X')) && g_precision != 0)
		|| hash_check(g_conv_table, 'o')) && hash_check(g_flag_table, '#')))
		mod_hash(ret);
	mod_width(ret, (int)ft_strlen(*ret));
}
