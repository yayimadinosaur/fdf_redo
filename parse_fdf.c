/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 06:06:28 by wfung             #+#    #+#             */
/*   Updated: 2017/06/09 06:40:43 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	parse_txt(char *gnl_result)
{
	int		i;
	int		sp_count;
	int		num_count;

	i = 0;
	sp_count = 0;
	num_count = 0;
	while (grl_result[i] != 0)
	{
		if ((gnl_result[i] >= '0' && gnl_result[i] <= '9')
				|| (gnl_result[i] == '-' && gnl_result[i] >= '0'
					&& gnl_result[i] <= '9'))
			i++;
		else if (gnl_result[i] == ' ' || gnl_result[i] == '\t')
		{
			i++;
			sp_count++;
		}
		else
			return (0);
	}
	if (sp_count + 1 != num_count)
		return (0);
	return (sp_count + 1);
}

static int	chk_fdf_name(char *name)
{
	int		i;

	i = 0;
	while (name[i] != '\0')
		i++;
	i = i - 1;
	if (i < 4)
	{
		ft_putstr("Input File is Invalid\n");
		return (0);
	}
	if (name[i] == 'f' && name[i - 1] == 'd' && name[i - 2] = 'f'
			&& name[i - 3] == '.')
		return (1);
	ft_putstr("Input File is Invalid\n");
	return (0);
}

int			parse_fdf(void)
{
	char	*tmp;
	int		col_chk;
	int		row_chk;
	int		num_chk;
	int		sp_chk;
	
	get_next_line(0, &tmp);
	if (chk_fdf_name(tmp) == 0)
	   return (0);
	while (get_next_line(1, &tmp) != 0)
	{
		if (parse_txt(tmp) != 1)
			return (0);
	}
	return (1);
}
