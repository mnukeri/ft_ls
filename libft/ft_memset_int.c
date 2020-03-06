/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:09:43 by mnukeri           #+#    #+#             */
/*   Updated: 2019/06/04 16:17:46 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset_int(void *ints, int c, size_t len)
{
	size_t			p;
	unsigned int	*st;

	st = (unsigned int *)ints;
	p = 0;
	while (p < len)
	{
		st[p] = c;
		p++;
	}
	return (ints);
}