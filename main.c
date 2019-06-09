/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:30:14 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/08 10:17:44 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void    put_pic(int flag, t_window *win)
{
	int *img;
	int size_line = 1000;
	int bpp = 8;
	int endian = 0;
	int i = 0;
	char *line = NULL;

	if (flag == 1)
		line = get_alliance();
	else if (flag == 2)
		line = get_horde();
	else if (flag == 3)
		line = get_undead();
	else if (flag == 4)
		line = get_elf();
	img = (int *)mlx_get_data_addr(win->img, &bpp, &size_line, &endian);
	i = 0;
	while (i < 225)
	{
		img[i] = ft_atoi(line);
		line += ft_power(ft_atoi(line), 10) + 1;
		i++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, win->x, win->y);
	win->x += 16;
}

int     main()
{
	t_window	*win;

	win = inicialization_win();
	win->win = mlx_new_window(win->mlx, SIZEX, SIZEY, "icon");
	win->img = mlx_new_image(win->mlx, 15, 15);

	put_pic(1, win);
	put_pic(2, win);
	put_pic(3, win);
	put_pic(4, win);

	controls(win);
	mlx_loop(win->mlx);
	return (0);
}

