/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:39:42 by yserkez           #+#    #+#             */
/*   Updated: 2019/02/02 11:25:41 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getvar(const char *name)
{
	int	i;
	int	index;

	i = -1;
	while (g_env[++i])
	{
		index = ft_indexof(g_env[i], '=');
		if (ft_strnequ(g_env[i], name, index))
			return (ft_strdup(&g_env[i][index + 1]));
	}
	return (NULL);
}

int		ft_getenv(char **args)
{
	char	*var;

	if (!args[0])
		return (1);
	if ((var = ft_getvar(args[0])))
	{
		ft_printf("%s\n", var);
		free(var);
	}
	return (1);
}

int		ms_setenv(char **args)
{
	char	**cpy;
	char	*tmp;
	int		i;

	i = -1;
	if (!args[0] || !ft_strchr(args[0], '='))
	{
		ft_printf("minishell: setenv usage: ENVIRONMENT=value\n");
		return (1);
	}
	tmp = ft_strsub(args[0], 0, ft_indexof(args[0], '='));
	ms_unsetenv(&tmp);
	free(tmp);
	cpy = (char**)malloc(sizeof(char*) * (++g_env_size) + 1);
	while (g_env[++i])
		cpy[i] = ft_strdup(g_env[i]);
	cpy[i++] = ft_strdup(args[0]);
	cpy[i] = 0;
	ft_arrcdel(g_env);
	g_env = cpy;
	return (1);
}

int		ms_unsetenv(char **args)
{
	int	i;

	i = -1;
	if (!args[0])
		return (1);
	while (g_env[++i])
	{
		if (ft_strnequ(g_env[i], args[0], ft_indexof(g_env[i], '=')))
		{
			shift_array(g_env, i);
			break ;
		}
	}
	return (1);
}

int		ms_env(char **args)
{
	int	i;

	i = -1;
	if (args[0])
		ft_getenv(args);
	else
	{
		while (g_env[++i])
			ft_printf("%s\n", g_env[i]);
	}
	return (1);
}
