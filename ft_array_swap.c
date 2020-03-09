/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:33:37 by mnukeri           #+#    #+#             */
/*   Updated: 2019/08/30 15:06:04 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_array_swap(char *s1, char *s2)
{
	char	*temp;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!(temp = ft_strnew(ft_strlen(s1) + 1)))
		return (0);
	ft_strcpy(temp, s1);
	ft_strcpy(s1, s2);
	ft_strcpy(s2, temp);
	free(temp);
	return (1);
}
