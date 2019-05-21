/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:11:50 by vmuravio          #+#    #+#             */
/*   Updated: 2017/11/19 19:13:01 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destptr, const char *srcptr)
{
	char	*tmp;

	tmp = destptr;
	while (*destptr)
		destptr++;
	while (*srcptr)
		*destptr++ = *srcptr++;
	*destptr = '\0';
	return (tmp);
}
