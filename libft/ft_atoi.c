/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:44:58 by vmuravio          #+#    #+#             */
/*   Updated: 2018/04/24 12:19:48 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned long int	num;
	int					neg;
	size_t				i;

	i = 0;
	num = 0;
	neg = 1;
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(str[i]))
	{
		if ((num > 922337203685477580 || (num == 922337203685477580
			&& (str[i] - '0') > 7)) && neg == 1)
			return (-1);
		else if ((num > 922337203685477580 || (num == 922337203685477580
			&& (str[i] - '0') > 8)) && neg == -1)
			return (0);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(num * neg));
}
