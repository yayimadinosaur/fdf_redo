/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:05:19 by wfung             #+#    #+#             */
/*   Updated: 2017/04/13 14:39:56 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	j = ft_strlen(s1);
	buff = (char*)malloc(sizeof(char) * (j + 1));
	if (!buff)
		return (NULL);
	ft_bzero(buff, j + 1);
	if (s1[i] == '\0')
	{
		buff[i] = '\0';
		return (buff);
	}
	while (i < j)
	{
		buff[i] = s1[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
