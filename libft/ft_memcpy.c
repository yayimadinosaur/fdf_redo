/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:48:50 by wfung             #+#    #+#             */
/*   Updated: 2016/12/20 17:46:49 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_buff;
	char	*src_buff;

	i = 0;
	dst_buff = (char*)dst;
	src_buff = (char*)src;
	while (i < n)
	{
		dst_buff[i] = src_buff[i];
		i++;
	}
	return ((void*)dst_buff);
}
