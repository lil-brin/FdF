/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 22:23:52 by vmuravio          #+#    #+#             */
/*   Updated: 2017/11/27 16:53:53 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_digits(int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*result;
	size_t	length;
	int		tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = (ft_digits(n));
	if (n < 0)
		length++;
	if (n == 0)
		return (ft_strdup("0"));
	if (!(result = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	tmp = n;
	if (n < 0)
		n = -n;
	result[length] = '\0';
	while (length--)
	{
		result[length] = n % 10 + '0';
		n /= 10;
	}
	if (tmp < 0)
		result[0] = '-';
	return (result);
}
