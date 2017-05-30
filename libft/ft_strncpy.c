/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:54:36 by wfung             #+#    #+#             */
/*   Updated: 2017/01/01 19:53:49 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	x;
	size_t	i;

	i = 0;
	x = ft_strlen(src);
	if (x < len)
	{
		while (i < x && len--)
		{
			dst[i] = src[i];
			i++;
		}
		while (len--)
		{
			dst[i] = '\0';
			i++;
		}
	}
	else
		while (len--)
		{
			dst[i] = src[i];
			i++;
		}
	return (dst);
}
