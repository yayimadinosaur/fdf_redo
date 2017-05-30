/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:06:16 by wfung             #+#    #+#             */
/*   Updated: 2016/12/19 15:33:07 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (little[j] == '\0')
		return ((char*)big);
	while (big[k] != '\0')
	{
		i = k;
		while (little[j] != '\0' && little[j] == big[i])
		{
			j++;
			i++;
		}
		if (little[j] == '\0')
			return ((char*)&big[k]);
		if (little[j] != big[i] && little[j] != '\0')
			j = 0;
		k++;
	}
	return (NULL);
}
