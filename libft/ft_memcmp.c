/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:24:09 by wfung             #+#    #+#             */
/*   Updated: 2016/12/19 13:52:16 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_buff;
	unsigned char	*s2_buff;

	i = 0;
	s1_buff = (unsigned char*)s1;
	s2_buff = (unsigned char*)s2;
	while (i < n)
	{
		if (s1_buff[i] == s2_buff[i])
			i++;
		else if (s1_buff[i] != s2_buff[i])
			return (s1_buff[i] - s2_buff[i]);
	}
	return (0);
}
