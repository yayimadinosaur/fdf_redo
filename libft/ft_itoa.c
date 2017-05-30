/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:51:47 by wfung             #+#    #+#             */
/*   Updated: 2016/12/20 16:13:12 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_int(long nb)
{
	int len_int;

	len_int = 0;
	if (nb < 0)
	{
		len_int++;
		nb = nb * -1;
	}
	if (nb == 0)
		len_int++;
	else
	{
		while (nb > 0)
		{
			len_int++;
			nb = nb / 10;
		}
	}
	return (len_int);
}

static char	*ft_strrev_w_neg(char *str)
{
	int		i;
	int		j;
	char	x;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	i = i - 1;
	if (str[j] == '-')
		j++;
	while (j < i)
	{
		x = str[j];
		str[j] = str[i];
		str[i] = x;
		i--;
		j++;
	}
	return (str);
}

static char	*ft_store_putnbr(char *str, long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = -n;
	}
	else if (n == 0)
	{
		str[i] = 48;
		i++;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	long	temp;
	char	*buff;

	temp = (long)n;
	buff = (char*)malloc(sizeof(char) * ft_len_int(temp) + 1);
	if (!buff)
		return (NULL);
	return (ft_strrev_w_neg(ft_store_putnbr(buff, temp)));
}
