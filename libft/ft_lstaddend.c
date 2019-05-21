/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuravio <vmuravio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:10:08 by vmuravio          #+#    #+#             */
/*   Updated: 2017/12/03 17:40:55 by vmuravio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alist, t_list *list)
{
	if (!alist || !list || !(*alist))
		return ;
	while ((*alist)->next != 0)
		*alist = (*alist)->next;
	(*alist)->next = list;
}
