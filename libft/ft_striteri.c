/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:51:05 by mnukeri           #+#    #+#             */
/*   Updated: 2019/06/16 16:15:17 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int k;

	k = 0;
	if (s == NULL)
		return ;
	if (f == NULL)
		return ;
	while (s[k] != '\0')
	{
		f(k, &s[k]);
		k++;
	}
}
