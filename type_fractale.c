/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_fractale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeurant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 02:03:37 by dmeurant          #+#    #+#             */
/*   Updated: 2023/05/09 02:03:38 by dmeurant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandel(double x, double y, t_hook_data *hook_data)
{
	int		i;
	double	tmp_x;
	double	tmp_y;

	i = 0;
	hook_data->x1 = 0;
	hook_data->y1 = 0;
	hook_data->x = (x - hook_data->longueur) / hook_data->zoom;
	hook_data->y = (y - hook_data->largeur) / hook_data->zoom;
	while ((hook_data->x1 * hook_data->x1) + (hook_data->y1 * hook_data->y1) < 4
		&& i < 100)
	{
		tmp_x = hook_data->x1;
		tmp_y = hook_data->y1;
		hook_data->x1 = ((tmp_x * tmp_x) - (tmp_y * tmp_y)) + hook_data->x;
		hook_data->y1 = (2 * tmp_x * tmp_y) + hook_data->y;
		i++;
	}
	if (i == 100)
		return (0x00000000);
	else
		return ((int)floor(hook_data->x1 + hook_data->mskn) * 0x00100506);
}

int	julia(double x, double y, t_hook_data *hook_data)
{
	int		i;
	double	tmp_x;
	double	tmp_y;

	i = 0;
	hook_data->x1 = (x - hook_data->longueur) / hook_data->zoom;
	hook_data->y1 = (y - hook_data->largeur) / hook_data->zoom;
	while ((hook_data->x1 * hook_data->x1) + (hook_data->y1 * hook_data->y1) < 4
		&& i < 100)
	{
		tmp_x = hook_data->x1;
		tmp_y = hook_data->y1;
		hook_data->x1 = ((tmp_x * tmp_x) - (tmp_y * tmp_y)) + hook_data->xjulia;
		hook_data->y1 = (2 * tmp_x * tmp_y) + hook_data->yjulia;
		i++;
	}
	if (i == 100)
		return (0x00000000);
	else
		return ((int)floor(hook_data->x1 * 10 + hook_data->mskn) * 0x00000404);
}

void	remplissage(t_hook_data *hook_data)
{
	hook_data->xjulia = 0.285;
	hook_data->yjulia = 0.01;
	hook_data->longueur = 980;
	hook_data->largeur = 540;
	hook_data->zoom = 500;
	hook_data->mskn = 1;
}
