/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:37:42 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/27 17:37:51 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char **s1, char c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	if (!(str = ft_strnew(ft_strlen(*s1) + 2)))
		return (NULL);
	while (*s1 != NULL && (*s1)[i])
	{
		str[i] = (*s1)[i];
		i++;
	}
	str[i++] = c;
	str[i] = '\0';
	ft_memdel((void**)s1);
	return (str);
}
