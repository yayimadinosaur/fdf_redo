/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:45:43 by wfung             #+#    #+#             */
/*   Updated: 2017/01/01 20:22:23 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	if (c < 0 || c > 255)
		return (c);
	else if ((unsigned char)c >= 97 && (unsigned char)c <= 122)
		c = c - 32;
	return ((int)c);
}
