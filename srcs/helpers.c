/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 10:38:07 by yserkez           #+#    #+#             */
/*   Updated: 2019/02/02 11:48:42 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_index(char *name)
{
	int	i;

	i = 0;
	while (g_env[i] && !ft_strnequ(g_env[i], name, ft_indexof(g_env[i], '=')))
		++i;
	return (g_env[i] ? i : -1);
}

void	shift_array(char **args, int start)
{
	char	*tmp;

	tmp = args[start];
	while (args[++start])
		args[start - 1] = args[start];
	args[start - 1] = 0;
	free(tmp);
}

void	shift_string(char *arg, int start)
{
	while (arg[++start])
		arg[start - 1] = arg[start];
	arg[start - 1] = 0;
}
