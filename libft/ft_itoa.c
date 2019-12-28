/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:51:46 by mnukeri           #+#    #+#             */
/*   Updated: 2019/07/04 14:22:02 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_dig(int d)
{
	int		k;

	k = 0;
	while (d != 0)
	{
		d /= 10;
		k++;
	}
	return (k);
}

char			*ft_itoa(int n)
{
	int		p;
	char	*st;
	int		neg;

	neg = 1;
	if (n == 0 || n == -0)
		return ("0");
	p = ft_dig(n);
	if (n < 0)
	{
		p++;
		neg = -1;
	}
	if (!(st = (char*)malloc(sizeof(char) * (p + 1))))
		return (NULL);
	ft_memset(st, '\0', p + 1);
	while (p-- > 0)
	{
		st[p] = ((n % 10) * neg) + '0';
		n /= 10;
	}
	if (neg == -1)
		st[0] = '-';
	return (st);
}
