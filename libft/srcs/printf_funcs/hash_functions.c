/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:28:40 by yserkez           #+#    #+#             */
/*   Updated: 2019/01/26 11:51:28 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hash_code(int key)
{
	return (key % SIZE);
}

void	hash_init(void)
{
	hash_insert(g_conv_table, 'c', 0);
	hash_insert(g_conv_table, 's', 0);
	hash_insert(g_conv_table, 'p', 0);
	hash_insert(g_conv_table, 'f', 0);
	hash_insert(g_conv_table, 'd', 0);
	hash_insert(g_conv_table, 'i', 0);
	hash_insert(g_conv_table, 'o', 0);
	hash_insert(g_conv_table, 'u', 0);
	hash_insert(g_conv_table, 'x', 0);
	hash_insert(g_conv_table, 'X', 0);
	hash_insert(g_conv_table, 'O', 0);
	hash_insert(g_conv_table, 'C', 0);
	hash_insert(g_conv_table, 'S', 0);
	hash_insert(g_type_table, 'h', 0);
	hash_insert(g_type_table, 'z', 0);
	hash_insert(g_type_table, 'j', 0);
	hash_insert(g_type_table, 'l', 0);
	hash_insert(g_flag_table, 'h', 0);
	hash_insert(g_flag_table, 'l', 0);
	hash_insert(g_flag_table, 'L', 0);
	hash_insert(g_flag_table, '#', 0);
	hash_insert(g_flag_table, '0', 0);
	hash_insert(g_flag_table, '-', 0);
	hash_insert(g_flag_table, ' ', 0);
	hash_insert(g_flag_table, '+', 0);
}

int		hash_insert(t_hash *table, char key, int data)
{
	t_hash	item;

	item.data = data;
	item.key = key;
	table[hash_code(key)] = item;
	return (0);
}

int		hash_update(t_hash *table, char key)
{
	int		index;

	index = hash_code(key);
	if (table[index].key == key)
		table[index].data += 1;
	else
		return (0);
	return (1);
}

int		hash_check(t_hash *table, char key)
{
	int		index;

	index = hash_code(key);
	if (table[index].key == key && table[index].data > 0)
		return (1);
	else
		return (0);
}
