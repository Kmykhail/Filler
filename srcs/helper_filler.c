/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:05:01 by kmykhail          #+#    #+#             */
/*   Updated: 2017/12/17 14:23:17 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_coordinat(int x, int y)
{
	ft_putnbr(x);
	ft_putstr(" ");
	ft_putnbr(y);
	ft_putstr("\n");
}

void	ft_how_many_tokens(t_fil *game)
{
	int i;
	int k;

	i = 0;
	k = 0;
	PIEC[game->cnt] = NULL;
	while (PIEC[i])
	{
		k = 0;
		while (PIEC[i][k])
		{
			game->tkn += (PIEC[i][k] == '*') ? 1 : 0;
			k++;
		}
		i++;
	}
	game->dt_x = malloc(sizeof(int) * (game->tkn + 1));
	game->dt_y = malloc(sizeof(int) * (game->tkn + 1));
}

int		ft_perebor(int j, int *rek)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (j == rek[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_init(int *x, int *y, int *by, int *iter)
{
	*x = 0;
	*y = 0;
	*by += 1;
	*iter = 0;
}

void	ft_calc_angle(t_fil *game, int x, int y)
{
	game->angle[0] = MASS[x] + MASS[y];
	game->angle[1] = MASS[x] + (game->map_y - MASS[y]);
	game->angle[2] = (game->map_x - MASS[x]) + MASS[y];
	game->angle[3] = (game->map_x - MASS[x]) + (game->map_y - MASS[y]);
}
