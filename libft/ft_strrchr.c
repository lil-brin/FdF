/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:54:55 by vmuravio          #+#    #+#             */
/*   Updated: 2017/11/14 15:42:05 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int s)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i++;
	while (i--)
		if (str[i] == (char)s)
			return ((char *)str + i);
	return (0);
}
