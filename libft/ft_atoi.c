/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:20:13 by mnukeri           #+#    #+#             */
/*   Updated: 2019/07/08 15:19:02 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sum;
	int		p;
	char	chr;
	char	sign;

	p = 0;
	sum = 0;
	while (str[p] == '\t' || str[p] == '\n' || str[p] == '\v' ||
			str[p] == '\f' || str[p] == '\r' || str[p] == ' ')
		p++;
	sign = str[p];
	if (str[p] == '-' || str[p] == '+')
		p++;
	while ((chr = str[p]) >= '0' && chr <= '9')
	{
		sum = sum * 10 - (chr - '0');
		p++;
	}
	if (sign != '-')
		sum = -sum;
	return (sum);
}
