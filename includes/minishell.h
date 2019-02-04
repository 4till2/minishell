/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 20:23:37 by yserkez           #+#    #+#             */
/*   Updated: 2019/02/02 12:58:36 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include "../libft/includes/libft.h"
# define NUM_CMDS 7

char			**g_env;
int				g_env_size;
typedef	int		(t_func)(char **);

typedef	struct	s_cmds
{
	char		*name;
	t_func		*function;
}				t_cmds;

void			remove_tabs(char *arg);
void			shift_string(char *arg, int start);
void			shift_array(char **args, int start);
int				env_index(char *name);
void			init_env(char **envp);
void			expand(char **args);
int				ft_getenv(char **args);
char			*ft_getvar(const char *name);
int				ms_cd(char **args);
int				ms_echo(char **args);
int				ms_env(char **args);
int				ms_exit(char **args);
int				ms_setenv(char **args);
int				ms_unsetenv(char **args);

#endif
