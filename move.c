/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeurant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:00:43 by dmeurant          #+#    #+#             */
/*   Updated: 2023/05/09 19:00:44 by dmeurant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key(int keycode, t_hook_data *hook_data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(hook_data->ptr, hook_data->win);
		mlx_destroy_display(hook_data->ptr);
		free(hook_data->ptr);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == 65361)
		hook_data->longueur -= 50;
	else if (keycode == 65362)
		hook_data->largeur -= 50;
	else if (keycode == 65363)
		hook_data->longueur += 50;
	else if (keycode == 65364)
		hook_data->largeur += 50;
	else if (keycode == 65505)
		hook_data->mskn *= 3;
	michelle_repete(hook_data);
	return (0);
}

int	mouse_zoom(int key, int x, int y, t_hook_data *hook_data)
{
	if (key == 4)
		hook_data->zoom += 100;
	if (key == 5)
		hook_data->zoom -= 100;
	if (hook_data->zoom < 0)
		hook_data->zoom += 50;
	hook_data->longueur = hook_data->longueur - (x - 960) / 2;
	hook_data->largeur = hook_data->largeur - (y - 540) / 2;
	michelle_repete(hook_data);
	return (0);
}
