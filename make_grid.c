/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:39:23 by wfung             #+#    #+#             */
/*   Updated: 2017/05/23 13:50:03 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
void	print_grid(char **grid)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (grid[i])
	{
		while (grid[i][j])
		{
			printf("%c", grid[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
}
*/

int		count_chr(char *str, int n, int stop)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != stop)
	{
		if (str[i] == (char)n && str[i + 1] != (char)n)
			count++;
//		if (str[i] == (char)n)
//			printf("x");
//		else
//			printf("o");
		i++;
	}
//	printf("\ncount chr col = %i\n", count);
	return (count);
}


int		make_grid(int fd, t_fdfstore *grid)
{
	char		*buff;
	int			row;
	t_fdfstore	*head;

	head = grid;
	grid->col = 0;
	row = 0;
	while (get_next_line(fd, &buff) == 1)
	{
		if (grid->col > 0)
		{
			if (count_chr(buff, '	', '\0') != grid->col)
				return (0);
		}
		else if (grid->col == 0)
			grid->col = count_chr(buff, '	', '\0');
		head->store = ft_strdup(buff);
		if (!(head->next = (t_fdfstore*)malloc(sizeof(t_fdfstore) * (1))))
			return (0);
		head = head->next;
		free(buff);
		row++;
	}
	head->next = NULL;
	grid->row = row;
	printf("col %i row %i\n", grid->col, grid->row);
	return (1);
}
