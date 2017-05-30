/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:50:33 by wfung             #+#    #+#             */
/*   Updated: 2016/12/15 17:42:40 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	x;
	char			*y;

	i = 0;
	x = (unsigned char)c;
	y = (char*)s;
	while (y[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (y[i] == x)
			return (&y[i]);
		i--;
	}
	return (NULL);
}
