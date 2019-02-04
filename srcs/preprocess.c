/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 10:49:15 by yserkez           #+#    #+#             */
/*   Updated: 2019/02/02 12:38:58 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_tilde(char *arg)
{
	char	*ret;

	ret = ft_getvar("HOME");
	if (arg[1])
		ret = ft_strjoin(&ret, &arg[1]);
	return (ret);
}

char	*expand_dollar(char *arg)
{
	char	*ret;

	ret = ft_getvar(arg);
	return (ret);
}

void	expand(char **args)
{
	int		i;
	char	*tmp;

	i = -1;
	while (args[++i])
	{
		if (args[i][0] == '~')
		{
			tmp = args[i];
			args[i] = expand_tilde(args[i]);
			free(tmp);
		}
		else if (args[i][0] == '$')
		{
			tmp = args[i];
			args[i] = expand_dollar(&args[i][1]);
			free(tmp);
		}
		else if (args[i][0] == '\t')
		{
			shift_string(args[i], 0);
			!args[i][0] ? shift_array(args, i) : 0;
			--i;
		}
	}
}

void	remove_tabs(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '\t')
			shift_string(arg, i);
	}
}

void	init_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		++i;
	g_env_size = i;
	g_env = (char **)malloc(sizeof(char *) * g_env_size + 1);
	i = -1;
	while (envp[++i])
		g_env[i] = ft_strdup(envp[i]);
	g_env[i] = 0;
}
