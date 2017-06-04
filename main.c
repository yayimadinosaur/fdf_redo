/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:03:56 by wfung             #+#    #+#             */
/*   Updated: 2017/06/03 19:45:57 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*draw w/ 5 variables*/
void	draw(void *mlx, void *win, t_fdfstore *grid)
{
	int		i;
	int		j;
	int		n;	//stopper? for y?
	int		p;	//stopper for x?
	int		m;	//slope
//	int		x;	//old

	i = 0;
	printf("grid value test col %i row %i win_x %i win_y %i center_x %i center_y %i start_x %i start_y %i max_x %i max_y %i h %i w %i\n", grid->col, grid->row, grid->win_x, grid->win_y, grid->center_x, grid->center_y, grid->start_x, grid->start_y, grid->max_x, grid->max_y, grid->h, grid->w);
	while (i < grid->col)	//remember to print proper array	//old - while(grid->f_array[i]
	{
		j = 0;
		while (j < grid->row )
		{
			m = ((j - (j + 1)) / (i - (i + 1))) * j + 1;	//NOT TEST?
		//	n = grid->start_x + (grid->win_x / (grid->col * j + 1));
		//	p =  grid->start_y + (grid->win_y / (grid->row * i + 1));
	//		n = grid->start_x + grid->start_x * i;
	//		p = grid->start_y + grid->start_y * j;
			n = grid->start_x + grid->h * i;
			p = grid->start_y + grid->w * j;
			printf("j = [%i] i = [%i] m = [%i] n = [%i] p = [%i]\n", j, i, m, n, p);
			while (n < grid->start_x + grid->h * (i + 1))
		//	while (n > grid->start_x + grid->start_x * (i - 1))
			{
			//	mlx_pixel_put(mlx, win, n * m + n , p, 0xff00);	//green
			//	mlx_pixel_put(mlx, win, n, p * m + p, 0xffff00);	//yellow
				mlx_pixel_put(mlx, win, n, p, 0xff);	//blue	//was - red
			//	mlx_pixel_put(mlx, win, n * m + n, p * m + p, 0xffffff);	//white
		//		n--;
				n++;
			}
			n = grid->start_x + grid->h * i;
			while (p < grid->start_x + grid->w * (j + 1))
	//		while (p > grid->start_y + grid->start_y * (j - 1))
			{
				mlx_pixel_put(mlx, win, n, p, 0xff0000);	//red
				p++;
	//			p--;
			}
			p = grid->start_y + grid->w * j;
			j++;
		}
		i++;
	}
	while (n > grid->start_x && p > grid->start_y)
	{
		mlx_pixel_put(mlx, win, n, p, 0xffff00);	//yellow
		n--;
	//	mlx_pixel_put(mlx, win, n, p, 0xff00);		//green
	//	p--;
	}
	printf("fin draw ft\n");
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	t_env w;

	w = *e;
	printf("mouse: %d (%d:%d)\n", button, x, y);
	mlx_pixel_put(e->mlx, e->win, x, y, 0xff0000);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	t_env w;
	w = *e;
	printf("key: %d\n", keycode);
	if (keycode == 53)
		return (53);
	return (0);
}

void	set_window(int n, t_fdfstore *grid)
{
	if (n < 0)
		ft_putstr("window size needs to be positive\n");
	if (n == 0)
		ft_putstr("window size needs to be greater than 0\n");
	grid->win_x = n;
	grid->win_y = n;
	grid->center_x = n / 2;
	grid->center_y = n / 2;
	grid->start_x =  n / 10;		//starts off 10% inside x y
	grid->start_y =  n / 10;
	grid->max_x = n - (n / 10);
	grid->max_y = n - (n / 10);
	grid->h = (n - (grid->start_x * 2)) / grid->col;
	grid->w = (n - (grid->start_x * 2)) / grid->row;
}

int		main(int ac, char **av)
{
	t_env		e;
	t_fdfstore	*grid;
	int			fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (!(grid = (t_fdfstore*)malloc(sizeof(t_fdfstore) * (1))))
			return (0);
		grid->next = NULL;
		if (make_grid(fd, grid) == 0)
		{
			printf("make grid fails\n");
//			clr_struct(grid);
			return (0);
		}
		ft_make_intarray(grid);
		print_intarray(grid);	//for testing purposes
		set_window(600, grid);	//set window values
		e.mlx = mlx_init();		//fails if returns NULL PTR
		e.win = mlx_new_window(e.mlx, grid->win_x, grid->win_y, "42");	//creates new window
		draw(e.mlx, e.win, grid);
//		mlx_key_hook(e.win, key_hook, &e);
//	if (mlx_key_hook(e.win, key_hook, &e) == 53)
//		return (0);
//	mlx_expose_hook(e.win, expose_hook, &e);
	//	mlx_mouse_hook(e.win, mouse_hook, &e);		//MOUSE HOOK PRINTS PIXEL AT MOUSE LOCATION!
//	mlx_mouse_hook(e.win, draw_mouse, &e);
		mlx_loop(e.mlx);	//function never returns / infinite loop
//	mlx_clear_window(e.mlx, e.win);	//clears window	
	//	sleep(5);
	//	usleep(5000);
	}
	else
		write(1, "Not Enough Args\n", 16); 
	return (0);
}

//expose_hook	- redraws window when going out bounds of current window
//loop_hook		- continuous button pressing
