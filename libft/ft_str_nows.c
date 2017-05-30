/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_nows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:37:50 by wfung             #+#    #+#             */
/*   Updated: 2017/01/02 17:46:27 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_nows(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*buff;

	i = 0;
	j = 0;
	buff = (char*)malloc(sizeof(char) * (ft_strlen_nows(str) + 1));
	if (!buff)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		else if (str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
		{
			buff[j] = str[i];
			j++;
			i++;
		}
	}
	buff[j] = '\0';
	return (buff);
}
