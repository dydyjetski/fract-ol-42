/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeurant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:03:54 by dmeurant          #+#    #+#             */
/*   Updated: 2023/05/09 19:03:55 by dmeurant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	erreur_comp(t_hook_data *info, char **argv)
{
	if (argv[2] != NULL)
	{
		if (check(argv[2]) != 1)
			info->xjulia = ((double)ft_atoi(argv[2]) / 1000);
		else
		{
			write(1, "ERREUR <int module1> <int module2>", 34);
			return (1);
		}
	}
	if (argv[3] != NULL && argv[2] != NULL)
	{
		if (check(argv[3]) != 1)
			info->yjulia = ((double)ft_atoi(argv[3]) / 1000);
		else
		{
			write(1, "ERREUR <int module1> <int module2>", 34);
			return (1);
		}
	}
	return (0);
}

int	erreur(t_hook_data *info, int argc, char **argv)
{
	if (argc <= 1)
	{
		write(1, "ERREUR ./fractol <Name> <module1> <module2>", 43);
		return (1);
	}
	if (argc >= 2 && argc <= 4)
	{
		if (erreur_comp(info, argv) != 0 && argc > 2)
			return (1);
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
		{
			info->type = 1;
			return (0);
		}
		else if (ft_strcmp(argv[1], "julia") == 0)
		{
			info->type = 2;
			return (0);
		}
		else
			write(1, "<julia/mandelbrot> <int(module1)> <int(module2)>\n", 49);
	}
	return (1);
}
