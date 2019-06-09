/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:29:27 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/08 13:40:15 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

#include <stdlib.h>
#include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
#include "libftprintf/ft_printf.h"
#include "libftprintf/libft/libft.h"
# define SIZEX 1000
# define SIZEY 1000
# define MAIN_PAD_ESC		53
# define SPACE				49
# define ARROW_UP			126
# define ARROW_DOWN			125
typedef struct				s_window
{
	void					*mlx;
	void					*win;
	void                    *img;
	int                     x;
	int                     y;
}							t_window;

int							main(int argc, char **argv);
t_window					*inicialization_win(void);

/*
 * players
 */
int				key_press(int key, void *fdf);
int				expose(void *param);
void			controls(t_window *win);
int    put(t_window *win);


/*
 * players
 */
char*   get_undead();
char    *get_alliance();
char    *get_horde();
char*   get_elf();




#endif
