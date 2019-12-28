/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:54:45 by mnukeri           #+#    #+#             */
/*   Updated: 2019/07/09 13:18:52 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t p;

	p = 0;
	while (s1[p] && s2[p] && s1[p] == s2[p] && --n != 0)
		p++;
	if (n == 0)
		return (0);
	return ((unsigned char)s1[p] - (unsigned char)s2[p]);
}
