/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:55:44 by wfung             #+#    #+#             */
/*   Updated: 2017/01/01 19:46:07 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*src_buf;
	unsigned char	*dst_buf;

	i = 0;
	src_buf = (unsigned char*)src;
	dst_buf = (unsigned char*)dst;
	if (src_buf >= dst_buf)
	{
		while (len--)
			*dst_buf++ = *src_buf++;
	}
	else if (src_buf < dst_buf)
	{
		dst_buf = dst_buf + len - 1;
		src_buf = src_buf + len - 1;
		while (len--)
			*dst_buf-- = *src_buf--;
	}
	return ((void*)dst);
}
