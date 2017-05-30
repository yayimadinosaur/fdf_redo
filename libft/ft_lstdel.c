/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:24:30 by wfung             #+#    #+#             */
/*   Updated: 2016/12/30 16:43:14 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;

	if (!alst)
		return ;
	if (!alst)
		return ;
	while (*alst != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		current = (*alst)->next;
		free(*alst);
		*alst = current;
	}
	current = NULL;
}
