/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:12:27 by vmuravio          #+#    #+#             */
/*   Updated: 2017/11/12 19:44:25 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*new_b;

	if (len == 0)
		return (b);
	new_b = (unsigned char *)b;
	while (len)
	{
		*new_b = (unsigned char)c;
		if (len)
			new_b++;
		len--;
	}
	return (b);
}
