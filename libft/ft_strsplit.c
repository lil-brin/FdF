/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 20:29:01 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/04 23:00:04 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s || !c)
		return (0);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s[i])
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && (s[i + len] != c))
				len++;
			str[j++] = ft_strsub(s, i, len);
			i = i + len;
		}
	str[j] = 0;
	return (str);
}
