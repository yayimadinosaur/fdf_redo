/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:08:07 by wfung             #+#    #+#             */
/*   Updated: 2016/12/12 19:00:33 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*buff;

	i = 0;
	buff = (char*)malloc(sizeof(char) * size);
	if (!buff)
		return (NULL);
	while (i < size)
	{
		buff[i] = 0;
		i++;
	}
	return ((void*)buff);
}
