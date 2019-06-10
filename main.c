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
	int *img, *mas = NULL;
	int size_line = 1000;
	int bpp = 8;
	int endian = 0;
	int i = 0;

	if (flag == 1)
		mas = get_alliance_black();
	else if (flag == 2)
		mas = get_alliance_white();
	else if (flag == 3)
		mas = get_alliance_grey();
	else if (flag == 4)
		mas = get_horde_black();
	else if (flag == 5)
		mas = get_horde_white();
	else if (flag == 6)
		mas = get_horde_grey();
	else if (flag == 7)
		mas = get_elf_black();
	else if (flag == 8)
		mas = get_elf_white();
	else if (flag == 9)
		mas = get_elf_grey();
	else if (flag == 10)
		mas = get_undead_black();
	else if (flag == 11)
		mas = get_undead_white();
	else if (flag == 12)
		mas = get_undead_grey();
	if (mas == NULL)
	{
		write(1, "mas = NULL\n", 11);
		exit(0);
	}
	img = (int *)mlx_get_data_addr(win->img, &bpp, &size_line, &endian);
	i = 0;
	while (i < 324)
	{
		img[i] = mas[i];
		i++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, win->x, win->y);
	if(win->y < 60)
		win->y += 20;
	if (win->y >= 60)
	{
		win->y = 0;
		win->x += 20;
	}
}

int     main()
{
	t_window	*win;
	int x = 1;

	win = inicialization_win();
	win->win = mlx_new_window(win->mlx, SIZEX, SIZEY, "icon");
	win->img = mlx_new_image(win->mlx, 18, 18);

	while(x <= 12)
	{
		put_pic(x++, win);
	}
	controls(win);
	mlx_loop(win->mlx);
	return (0);
}

