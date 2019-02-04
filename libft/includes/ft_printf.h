/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:16:05 by yserkez           #+#    #+#             */
/*   Updated: 2019/01/26 11:52:53 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define SIZE 128
# define FLAG 1
# define WIDTH 2
# define PRECISION 3
# define TYPE 4
# define CONVERSION 5
# define MESSAGE 6

typedef struct	s_hash
{
	int			data;
	char		key;
}				t_hash;

extern t_hash	g_conv_table[SIZE];
extern t_hash	g_flag_table[SIZE];
extern t_hash	g_type_table[SIZE];
extern int		g_width;
extern int		g_precision;
extern char		g_message;

int				hash_update(t_hash *table, char key);
int				hash_insert(t_hash *table, char key, int data);
void			hash_init(void);
int				hash_check(t_hash *table, char key);
void			do_mods(char **ret);
int				ft_printf(char *s, ...);
int				append_arg(char **orig, va_list args);
int				get_arg(char **ret, va_list args);
int				append_arg(char **orig, va_list args);
int				set_flag(char *s, int *i);
int				get_number(char *s, int *i);
#endif
