/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:28:48 by mnukeri           #+#    #+#             */
/*   Updated: 2019/08/07 17:10:28 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
    int st1;
    int st2;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
    st1 = 0;
	if (s1[i] >= 65 && s1[i] <= 90)
		st1 = s1[i] - 64;
	if (s1[i] >= 97 && s2[i] <= 122)
		st1 = s1[i] - 96;
    st2 = 0;
	if (s2[i] >= 65 && s2[i] <= 90)
		st2 = s2[i] - 64;
	if (s2[i] >= 97 && s2[i] <= 122)
        st2 = s2[i] - 96;
	
	if (st1 < st2)
		return (-1);
	if (st1 > st2)
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	if (s1[i] > s2[i])
		return (1);
	return (0);
}
