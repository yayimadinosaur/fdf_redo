/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:41:50 by wfung             #+#    #+#             */
/*   Updated: 2016/12/18 16:54:05 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*buff;

	i = 0;
	buff = (char*)malloc(sizeof(char) * (size + 1));
	if (!buff)
		return (NULL);
	while (i < size)
	{
		buff[i] = '\0';
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
