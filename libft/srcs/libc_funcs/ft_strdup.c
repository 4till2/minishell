/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:22:32 by yserkez           #+#    #+#             */
/*   Updated: 2018/09/14 15:10:09 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	char	*ret;
	int		i;

	i = -1;
	if (str == NULL)
	{
		ret = (char *)malloc(sizeof(char) * 7);
		ft_strcpy((unsigned char*)ret, "(null)");
	}
	else
	{
		ret = (char *)malloc(sizeof(char) * ft_strlen((char*)str) + 1);
		if (ret == NULL)
			return (ret);
		while (str[++i])
			ret[i] = str[i];
		ret[i] = '\0';
	}
	return (ret);
}
