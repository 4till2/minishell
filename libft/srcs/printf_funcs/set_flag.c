/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:20:25 by yserkez           #+#    #+#             */
/*   Updated: 2019/01/26 11:52:21 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_number(char *s, int *i)
{
	int	num;

	num = 0;
	while (s[*i] && (s[*i] >= '0' && s[*i] <= '9'))
	{
		num = num * 10 + (s[*i] - '0');
		++(*i);
	}
	--(*i);
	return (num);
}

int		set_flag(char *s, int *i)
{
	char c;

	c = s[*i];
	if (hash_update(g_conv_table, c))
		return (CONVERSION);
	else if ((c == 'h' && s[*i + 1] == 'h') || (c == 'l' && s[*i + 1] == 'l'))
	{
		++(*i);
		hash_update(g_type_table, c);
		return (TYPE);
	}
	else if (c == 'z' || c == 'j')
	{
		hash_update(g_type_table, c);
		return (TYPE);
	}
	else if (hash_update(g_flag_table, c))
		return (FLAG);
	return (-1);
}
