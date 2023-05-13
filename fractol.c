/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeurant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:45:09 by dmeurant          #+#    #+#             */
/*   Updated: 2023/05/08 16:45:11 by dmeurant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_hook_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	aff(t_hook_data *hook_data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	hook_data->addr = mlx_get_data_addr(hook_data->img, &hook_data
			->bits_per_pixel, &hook_data->line_length, &hook_data->endian);
	while (x < 1920)
	{
		y = 0;
		while (y < 1080)
		{
			if (hook_data->type == 1)
				my_mlx_pixel_put(hook_data, x, y, mandel(x, y, hook_data));
			else if (hook_data->type == 2)
				my_mlx_pixel_put(hook_data, x, y, julia(x, y, hook_data));
			y++;
		}
		x++;
	}
}

void	michelle_repete(t_hook_data *hook_data)
{
	hook_data->img = mlx_new_image(hook_data->ptr, 1920, 1080);
	aff(hook_data);
	mlx_put_image_to_window(hook_data->ptr, hook_data->win,
		hook_data->img, 0, 0);
	mlx_destroy_image(hook_data->ptr, hook_data->img);
}

int	handle_exit(t_hook_data *hook_data)
{
	mlx_destroy_window(hook_data->ptr, hook_data->win);
	mlx_destroy_display(hook_data->ptr);
	free(hook_data->ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_hook_data	hook_data;

	remplissage(&hook_data);
	if (erreur(&hook_data, argc, argv) == 1)
		return (1);
	hook_data.ptr = mlx_init();
	hook_data.win = mlx_new_window(hook_data.ptr, 1920, 1080, "Fractol");
	michelle_repete(&hook_data);
	mlx_hook(hook_data.win, 2, 1L << 0, handle_key, &hook_data);
	mlx_hook(hook_data.win, 17, 0, handle_exit, &hook_data);
	mlx_mouse_hook(hook_data.win, mouse_zoom, &hook_data);
	mlx_loop(hook_data.ptr);
	return (0);
}
