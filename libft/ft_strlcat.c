/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:53:09 by wfung             #+#    #+#             */
/*   Updated: 2017/01/01 19:59:15 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	p;

	i = 0;
	j = 0;
	k = ft_strlen(dst);
	p = ft_strlen(src);
	while (i <= k && i < size && dst[i] != '\0')
		i++;
	if (size <= k)
		return (i + p);
	while (src[j] != '\0' && j < size - k - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (k + p);
}
