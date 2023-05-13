/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeurant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:43:25 by dmeurant          #+#    #+#             */
/*   Updated: 2023/05/08 16:43:27 by dmeurant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>

# include "./minilibx-linux/mlx.h"

typedef struct s_hook_data
{
	void	*ptr;
	void	*win;
	int		mskn;
	double	x1;
	double	y1;
	double	x;
	double	y;
	int		zoom;
	int		longueur;
	int		largeur;
	double	xjulia;
	double	yjulia;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		type;
}				t_hook_data;

int		mandel(double x, double y, t_hook_data *hook_data);
int		julia(double x, double y, t_hook_data *hook_data);
void	remplissage(t_hook_data *hook_data);
int		handle_key(int keycode, t_hook_data *hook_data);
void	michelle_repete(t_hook_data *hook_data);
int		erreur(t_hook_data *info, int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
int		mouse_zoom(int key, int x, int y, t_hook_data *hook_data);

#endif
