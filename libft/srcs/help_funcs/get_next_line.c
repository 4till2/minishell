/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:42:39 by yserkez           #+#    #+#             */
/*   Updated: 2019/02/01 11:50:23 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	add_next_line(char **statstr, char **line)
{
	char	*ptr;

	if (ft_strchr(*statstr, '\n') != NULL)
	{
		ptr = *statstr;
		*line = ft_strsub(*statstr, 0, ft_strchr(*statstr, '\n') - *statstr);
		*statstr = ft_strdup(ft_strchr(*statstr, '\n') + 1);
		free(ptr);
		return (1);
	}
	else if (**statstr != '\0')
	{
		ptr = *statstr;
		*line = ft_strdup(*statstr);
		*statstr = ft_strdup("\0");
		free(ptr);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char		*buf;
	static char *statstr[54139];
	int			red;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	while ((red = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (!statstr[fd])
			statstr[fd] = ft_strdup(buf);
		else
			statstr[fd] = ft_strjoin(&statstr[fd], buf);
		ft_strclr(buf);
		if (ft_strchr(statstr[fd], '\n'))
			break ;
	}
	free(buf);
	if (red <= 0)
		return (red < 0 ? -1 : 0);
	return (add_next_line(&statstr[fd], line));
}
