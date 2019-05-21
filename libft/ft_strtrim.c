/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:23:36 by vmuravio          #+#    #+#             */
/*   Updated: 2017/11/30 17:12:09 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		i;

	if (!s)
		return (0);
	len = ft_strlen(s);
	while (is_whitespace(s[len - 1]))
		len--;
	i = 0;
	while (is_whitespace(s[i]))
	{
		len--;
		i++;
	}
	if (len <= 0)
		len = 0;
	if (!(str = (char *)malloc(sizeof(*s) * (len + 1))))
		return (0);
	s += i;
	i = -1;
	while (++i < len)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}
