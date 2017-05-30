/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:55:56 by wfung             #+#    #+#             */
/*   Updated: 2016/12/19 20:27:02 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_array_word_count(char const *s, char c)
{
	int		i;
	int		word_count;
	char	**array_count;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			word_count++;
		}
	}
	array_count = (char**)malloc(sizeof(char*) * (word_count + 1));
	if (!array_count)
		return (NULL);
	array_count[word_count] = NULL;
	return (array_count);
}

static char	**ft_array_word(char **array, char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	int		word_count;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			end = i + 1;
			array[word_count] = (char*)malloc(sizeof(char) * (end - start));
			if (!array[word_count])
				return (NULL);
			word_count++;
		}
		else if (s[i] == c)
			i++;
	}
	array[word_count] = NULL;
	return (array);
}

static int	ft_null_protect_strsplit(char const *s, char c)
{
	if (!s)
		return (0);
	if (!ft_array_word_count(s, c))
		return (0);
	if (!ft_array_word(ft_array_word_count(s, c), s, c))
		return (0);
	else
		return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		word_count;
	char	**buff_array;

	i = 0;
	word_count = 0;
	if (ft_null_protect_strsplit(s, c) == 0)
		return (NULL);
	buff_array = ft_array_word(ft_array_word_count(s, c), s, c);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i] != c && s[i] != '\0')
				buff_array[word_count][j++] = s[i++];
			buff_array[word_count][j] = '\0';
			word_count++;
		}
		else if (s[i] == c)
			i++;
	}
	return (buff_array);
}
