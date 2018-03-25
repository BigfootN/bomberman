/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:37:09 by aemebiku          #+#    #+#             */
/*   Updated: 2014/06/26 15:37:10 by aemebiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*my_memset(void *b, int c, size_t len)
{
	unsigned char	*str2;

	str2 = (unsigned char *)b;
	if (str2 == NULL)
		return (0);
	while (len > 0)
	{
		len--;
		str2[len] = c;
	}
	return (str2);
}
