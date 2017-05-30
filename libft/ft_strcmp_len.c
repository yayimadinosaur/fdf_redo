/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:49:29 by wfung             #+#    #+#             */
/*   Updated: 2017/01/03 13:49:47 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcmp_len(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (-1);
	if (s1 > s2)
		return (ft_strlen(s1) - ft_strlen(s2));
	else if (s1 < s2)
		return (ft_strlen(s2) - ft_strlen(s1));
	else
		return (0);
}
