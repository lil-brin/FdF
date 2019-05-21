/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:38:37 by vmuravio          #+#    #+#             */
/*   Updated: 2017/11/21 00:30:56 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	res;

	res = ft_strlen(dst) + ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	while (dstlen < size - 1)
	{
		dst[dstlen] = *src;
		dstlen++;
		src++;
	}
	if (dst[dstlen] != '\0')
		dst[dstlen] = '\0';
	return (res);
}
