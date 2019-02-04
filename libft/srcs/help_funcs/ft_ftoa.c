/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:39:30 by yserkez           #+#    #+#             */
/*   Updated: 2019/01/25 14:32:09 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_int(double long n)
{
	long long	trunc;

	trunc = (long long)n;
	return (n == trunc);
}

void	ft_round(char **num, int next, int pos)
{
	if (next >= 5 && next <= 9)
	{
		if (((*num)[pos] - '0') == 9)
		{
			(*num)[pos] = '0';
			ft_round(num, 9, --pos);
		}
		else
			(*num)[pos] = ((((*num)[pos] - '0') + 1) + '0');
	}
}

void	convert_dec(char **ret, double long fpart, int precision)
{
	char	*tmp;
	int		i;
	char	x;

	if (precision != 0)
	{
		i = 0;
		tmp = ft_strnew(precision + 1);
		tmp[i] = '.';
		while ((!is_int(fpart) && precision > 0) || precision > 0)
		{
			x = ((int)(fpart * 10) % 10) + '0';
			(x >= '0' && x <= '9') ? (tmp[++i] = x) :
			(tmp[++i] = '0');
			fpart = fpart * 10;
			--precision;
		}
		ft_round(&tmp, ((int)(fpart * 10) % 10), i);
		*ret = ft_strjoin(ret, tmp);
		free(tmp);
	}
}

char	*ft_ftoa(double long n, int precision)
{
	char		*ret;
	double long	i;
	double long	fpart;

	precision == -1 ? (precision = 6) : 0;
	i = n;
	fpart = n;
	if (precision == 0)
		((((int)(fpart * 10) % 10)) > 4) ? ++i : 0;
	ret = ft_itoa_base((long long)i, 10);
	convert_dec(&ret, fpart, precision);
	return (ret);
}
