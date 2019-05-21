/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:22:34 by vmuravio          #+#    #+#             */
/*   Updated: 2017/11/12 19:45:08 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destptr, const char *srcptr, size_t n)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = destptr;
	while (*destptr)
		destptr++;
	while (*srcptr && n--)
		*destptr++ = *srcptr++;
	*destptr = '\0';
	return (tmp);
}
