/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:25:56 by wfung             #+#    #+#             */
/*   Updated: 2016/12/16 18:22:40 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_buf;
	unsigned char	*s2_buf;

	i = 0;
	s1_buf = (unsigned char*)s1;
	s2_buf = (unsigned char*)s2;
	while (s1_buf[i] == s2_buf[i] && s1_buf[i] != '\0' && s2_buf[i] != '\0'
			&& i < n)
		i++;
	if (i == n)
		i = i - 1;
	return (s1_buf[i] - s2_buf[i]);
}
