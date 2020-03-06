/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:35:57 by mnukeri           #+#    #+#             */
/*   Updated: 2019/06/16 14:28:13 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc_int(size_t size)
{
	unsigned int *space;

	space = (unsigned int *)malloc(sizeof(int) * size);
	if (!(space))
		return (0);
	ft_memset_int(space, 0, size);
	return (space);
}
