/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:25:22 by wfung             #+#    #+#             */
/*   Updated: 2017/01/03 12:26:37 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lst_count(t_list *lst)
{
	size_t	i;
	t_list	*current;

	i = 0;
	current = lst;
	if (!current)
		return (0);
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}
