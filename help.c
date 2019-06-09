/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:29:27 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/08 13:40:15 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_window		*inicialization_win(void)
{
	t_window *win;

	win = (t_window*)malloc(sizeof(t_window));
	win->mlx = mlx_init();
	win->win = NULL;
	win->y = 0;
	win->x = 0;
	return (win);
}

int    put(t_window *win)
{
	if (win->y >= 900)
		return (0);
	if (win->x < 900)
		mlx_put_image_to_window(win->mlx, win->win, win->img, win->x, win->y);
	else if (win->x >= 900)
	{
		win->x = 0;
		win->y += 15;
		if (win->y < 900)
			mlx_put_image_to_window(win->mlx, win->win, win->img, win->x, win->y);
		else
			return (0);
	}
	win->x += 15;
	return (0);
}

int     put2(t_window *win)
{
	int x;

	while (1)
	{
		x = 0;
		while (x < 100000000)
			x++;
		put(win);
		if (win->y >= 900)
			break;
	}
	return (0);
}

void			controls(t_window *win)
{
	mlx_hook(win->win, 2, 0, key_press, win);
	mlx_hook(win->win, 17, 0, close, win);
	mlx_hook(win->win, 17, 0, expose, win);
}

int				key_press(int key, void *fdf)
{
	t_window	*win;
	int x;

	win = fdf;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == SPACE)
	{
		put(win);
	}
	if (key == ARROW_UP)
	{
		put(win);
	}
	if (key == ARROW_DOWN)
	{
		put(win);
	}
	return (0);
}

int				expose(void *param)
{
	t_window	*win;

	win = param;
	exit(0);
}