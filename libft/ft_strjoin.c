/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:22:23 by wfung             #+#    #+#             */
/*   Updated: 2017/04/17 20:41:38 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*buff;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	buff = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buff)
		return (NULL);
	ft_bzero(buff, ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i] != '\0')
	{
		buff[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		buff[i] = s2[j];
		i++;
		j++;
	}
	buff[i] = '\0';
	return (buff);
}
