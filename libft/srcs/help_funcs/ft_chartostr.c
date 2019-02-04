/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:37:34 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/24 16:38:39 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chartostr(char c, int len)
{
	char *ret;

	ret = ft_strnew(len + 1);
	ret[len] = '\0';
	while (--len >= 0)
		ret[len] = c;
	return (ret);
}
