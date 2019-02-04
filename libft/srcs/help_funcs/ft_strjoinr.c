/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 10:47:25 by yserkez           #+#    #+#             */
/*   Updated: 2019/01/31 10:47:31 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinr(char const *s1, char **s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(*s2) + 1)))
		return (NULL);
	while (s1 != NULL && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2 != NULL && (*s2)[j])
	{
		str[i] = (*s2)[j];
		j++;
		i++;
	}
	str[i] = '\0';
	if ((*s2)[0])
		ft_memdel((void**)s2);
	return (str);
}
