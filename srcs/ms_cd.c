/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 22:32:26 by yserkez           #+#    #+#             */
/*   Updated: 2019/02/02 12:15:08 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_pwd(char *old)
{
	int		index;
	char	*new;

	new = NULL;
	if (!old)
		old = "";
	old = ft_strjoin2("OLDPWD=", old);
	if ((index = env_index("OLDPWD")) >= 0)
	{
		free(g_env[index]);
		g_env[index] = ft_strdup(old);
	}
	else
		ms_setenv(&old);
	new = getcwd(new, 0);
	new = ft_strjoinr("PWD=", &new);
	if ((index = env_index("PWD")) >= 0)
	{
		free(g_env[index]);
		g_env[index] = ft_strdup(new);
	}
	else
		ms_setenv(&new);
	free(new);
	free(old);
}

int		ms_cd(char **args)
{
	char	*old;
	char	*new;

	old = NULL;
	if (!args[0] && !(new = ft_getvar("HOME")))
	{
		ft_printf("minishell: could not find environment variable: HOME\n");
		return (1);
	}
	else if (args[0] && !(new = ft_strequ(args[0], "-") ? ft_getvar("OLDPWD") :
			ft_strdup(args[0])))
	{
		ft_printf("minishell: could not find environment variable: OLDPWD\n");
		return (1);
	}
	old = getcwd(old, 0);
	if (chdir(new) == -1)
		ft_printf("minishell: could not enter directory: '%s'\n", new);
	else
		update_pwd(old);
	free(old);
	free(new);
	return (1);
}
