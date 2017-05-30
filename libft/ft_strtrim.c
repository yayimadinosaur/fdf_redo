/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:45:44 by wfung             #+#    #+#             */
/*   Updated: 2016/12/20 15:36:34 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_nowhtspcs(char *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (0);
	j = i;
	while (s[i] != '\0')
		i++;
	if (s[i] == '\0')
		i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	j = i - j + 1;
	return (j);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		x;
	char	*buff;

	i = 0;
	x = 0;
	if (!s)
		return (NULL);
	j = ft_strlen_nowhtspcs((char*)s);
	buff = (char*)malloc(sizeof(char) * (j + 1));
	if (!buff)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (x < j)
	{
		buff[x] = s[i];
		x++;
		i++;
	}
	buff[x] = '\0';
	return (buff);
}
