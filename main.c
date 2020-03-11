/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:48:38 by mcarrete          #+#    #+#             */
/*   Updated: 2020/03/11 21:26:34 by mcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx/mlx.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
/*
int		deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}*/

int		x_increment(int key, int arrow_x)
{
	//hay que pasarel arrow_x a una struct
	int		increment;

	increment = 0;
	if (key == 124) //right arrow
	{
		increment += 10;
	}
	else if (key == 123) //left arrow
	{
		increment -= 10;
	}
	arrow_x += increment;
	printf("arrow_x_arriba = %d\n", arrow_x);
	return (arrow_x);
}

int		y_increment(int key, int arrow_y)
{
	int		increment;

	increment = 0;
	if (key == 126) //up arrow
	{
		increment += 10;
	}
	else if (key == 125) //down arrow
	{
		increment -= 10;
	}
	arrow_y += increment;
	printf("arrow_y_arriba = %d\n", arrow_y);
	return (arrow_y);
}

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*foto_ptr;
	int		foto_h;
	int		foto_w;
	int		x;
	int		y;
	int		arrow_x;
	int		arrow_y;

	//inicializo mlx
	mlx_ptr = mlx_init();

	//create new window
	win_ptr = mlx_new_window(mlx_ptr, 648, 486, "Holiiii");

	//puts pixels to create a red square
	y = 250;
	while (y < 350)
	{
		x = 250;
		while (x < 350)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0152000000);
			x++;
		}
		y++;
	}

	//pinter to xpm image on file
	foto_ptr = mlx_xpm_file_to_image(mlx_ptr, "images/foto_small.xpm", &foto_h, &foto_w);

	//put that photo inside the window created above
	mlx_put_image_to_window(mlx_ptr, win_ptr, foto_ptr, 1, 2);

	arrow_x = 324;
	arrow_y = 243;
	mlx_do_key_autorepeatoff(mlx_ptr);
	arrow_x += mlx_hook(win_ptr, 2, 1, x_increment, 0);
	printf("arrow_x = %d\n", arrow_x);
	arrow_y += mlx_hook(win_ptr, 2, 1, y_increment, 0);
	printf("arrow_y = %d\n", arrow_y);
	//writes on top of the image
	mlx_string_put(mlx_ptr, win_ptr, arrow_x, arrow_y, 0xFFFFFF, "Hola");

	//mlx_loop function is in charge of the event log inside of the window
	mlx_loop(mlx_ptr);
	return (0);
}
