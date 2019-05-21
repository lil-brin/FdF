/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:34:23 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/05 14:46:30 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*str;
	char	*tmp;

	l = 0;
	while (s1[l])
		l++;
	str = (char*)malloc(sizeof(*str) * (l + 1));
	if (str == NULL)
		return (NULL);
	tmp = str;
	while (l--)
	{
		*str = *s1;
		str++;
		s1++;
	}
	*str = '\0';
	return (tmp);
}
