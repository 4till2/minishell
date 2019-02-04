/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:19:55 by yserkez           #+#    #+#             */
/*   Updated: 2019/01/26 11:51:20 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_hash	g_conv_table[SIZE];
t_hash	g_flag_table[SIZE];
t_hash	g_type_table[SIZE];
int		g_width;
int		g_precision;
char	g_message;

int		print_out(char *ret)
{
	int i;

	i = -1;
	while (ret[++i])
		write(1, &ret[i], 1);
	ret[0] ? ft_memdel((void**)&ret) : 0;
	return (i);
}

int		handle_flag(char *s, int *i, va_list args, char **ret)
{
	int	conv;

	conv = 0;
	hash_init();
	g_message = '\0';
	g_precision = -1;
	g_width = -1;
	while (s[++(*i)] && (conv != CONVERSION) && !g_message)
	{
		if ((conv = set_flag(s, i)) > 0)
			continue ;
		else if (ft_isdigit(s[*i]))
			g_width = get_number(s, i);
		else if (s[*i] == '.')
			++(*i) ? g_precision = get_number(s, i) : 0;
		else
			g_message = s[*i];
	}
	if ((hash_check(g_conv_table, 'i') || hash_check(g_conv_table, 'd')) &&
			hash_check(g_type_table, 'h'))
		hash_update(g_flag_table, 'h');
	return (append_arg(ret, args));
}

int		ft_printf(char *s, ...)
{
	char		*ret;
	int			i;
	va_list		args;

	ret = NULL;
	ret = ft_strnew(1);
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			handle_flag(s, &i, args, &ret);
		else
			ret = ft_strappend(&ret, s[i++]);
	}
	va_end(args);
	return (print_out(ret));
}
