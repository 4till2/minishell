/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:22:25 by yserkez           #+#    #+#             */
/*   Updated: 2019/02/02 13:29:44 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmds	g_builtin_cmds[NUM_CMDS] = {
	{"cd", &ms_cd},
	{"echo", &ms_echo},
	{"env", &ms_env},
	{"exit", &ms_exit},
	{"setenv", &ms_setenv},
	{"unsetenv", &ms_unsetenv}
};

int		exec_path(char **parsed)
{
	char	*path;
	char	**arrpaths;
	int		i;

	i = 0;
	arrpaths = ft_strsplit(ft_getvar("PATH"), ':');
	path = ft_strdup(parsed[0]);
	while (arrpaths && access(path, X_OK) < 0 && arrpaths[i] && errno != EACCES)
	{
		arrpaths[i] = ft_strjoin(&arrpaths[i], "/");
		free(path);
		path = ft_strjoin(&arrpaths[i++], parsed[0]);
	}
	ft_arrcdel(arrpaths);
	return ((access(path, X_OK) >= 0 && execve(path, parsed, g_env)) ? 0 : -1);
}

int		shell_exec(char **parsed)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		ft_printf("minishell: error forking:\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (exec_path(parsed) < 0)
		{
			errno == EACCES ? ft_printf("minishell: permission denied: ") :
							ft_printf("minishell: command not found: ");
			ft_printf("%s\n", parsed[0]);
			exit(EXIT_SUCCESS);
		}
	}
	else
		waitpid(pid, &status, 0);
	return (1);
}

int		run_command(char **parsed)
{
	int	i;

	i = -1;
	if (!parsed[0])
		return (1);
	while (++i < NUM_CMDS - 1)
	{
		if (ft_strcmp(parsed[0], g_builtin_cmds[i].name) == 0)
			return (g_builtin_cmds[i].function(&parsed[1]));
	}
	return (shell_exec(parsed));
}

void	minishell(void)
{
	char	*input;
	char	**args;
	char	**parsed;
	int		status;
	int		i;

	status = 1;
	while (status && write(1, "$> ", 3))
	{
		if (!get_next_line(0, &input) && write(1, "\n", 1))
			continue ;
		i = -1;
		args = ft_strsplit(input, ';');
		while (args[++i] && status)
		{
			remove_tabs(args[i]);
			parsed = ft_strsplit(args[i], ' ');
			expand(parsed);
			status = run_command(parsed);
			ft_arrcdel(parsed);
		}
		free(input);
		ft_arrcdel(args);
	}
}

int		main(int argc, char **argv, char **envp)
{
	if (argc == 0 || !argv || !envp)
		return (-1);
	init_env(envp);
	minishell();
	return (0);
}
