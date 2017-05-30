/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:06:34 by wfung             #+#    #+#             */
/*   Updated: 2016/12/18 16:36:09 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if ((c > 90 && c < 97) || c < 0 || c > 122)
		return (0);
	else if ((((unsigned char)c >= 65 && (unsigned char)c <= 90))
			|| (((unsigned char)c >= 97 && (unsigned char)c <= 122)))
		return (1);
	else
		return (0);
}
