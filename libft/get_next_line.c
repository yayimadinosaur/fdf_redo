/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:23:03 by wfung             #+#    #+#             */
/*   Updated: 2017/04/18 19:45:36 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_cpychr(char *str, int c, int len)
{
	int		i;
	char	*buff;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (!(buff = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_bzero(buff, len + 1);
	while (str[i] != (char)c && i < len + 1)
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

static int		ft_ptrlen(char *p1, char *p2, int len)
{
	int		i;
	char	*buff;

	i = 0;
	buff = p1;
	if (len == 0)
		return (0);
	while (buff != p2 && i < len)
	{
		buff++;
		i++;
	}
	return (i);
}

static int		ft_lenchk(char **s1, char **s2, char *ptr)
{
	char	*hold;

	hold = NULL;
	if (*s1 && ft_strlen(*s1) > 0)
	{
		ptr = ft_strchr(*s1, 10);
		if (ptr != NULL)
		{
			*s2 = ft_cpychr(*s1, 10, ft_ptrlen(*s1, ptr, ft_strlen(*s1)));
			hold = ft_strsub(*s1, ft_ptrlen(*s1, ptr + 1, ft_strlen(*s1)),
					ft_strlen(*s1) - ft_strlen(*s2));
			*s1 = hold;
		}
		else if (ptr == NULL)
		{
			*s2 = ft_strdup(*s1);
			*s1 = NULL;
		}
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				count;
	char			tmp[BUFF_SIZE + 1];
	static char		*buff;
	char			*next;
	char			*hold;

	next = NULL;
	hold = NULL;
	if (fd < 0 || !line || read(fd, tmp, 0) < 0)
		return (-1);
	while ((count = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[count] = '\0';
		if (buff == NULL)
			buff = ft_strdup(tmp);
		else
		{
			hold = ft_strjoin(buff, tmp);
			free(buff);
			buff = hold;
		}
		if ((ft_strchr(tmp, 10)) != NULL)
			break ;
	}
	return (ft_lenchk(&buff, line, next));
}
