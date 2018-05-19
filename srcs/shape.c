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

void	ft_shape_1(t_fil *game, int x, int y)
{
	int i;

	i = 0;
	while (i < 3)
	{
		ft_calc_angle(game, x, y);
		if (!i)
		{
			if (game->angle[0] > game->angle[1])
				game->dist[0] = game->angle[0];
			else
				game->dist[1] = game->angle[1];
			x += 2;
			y += 2;
		}
		else if (i == 1)
			game->dist[2] = game->angle[2];
		else if (i == 2)
			game->dist[3] = game->angle[3];
		i++;
		x += 2;
		y += 2;
	}
}

void	ft_all_in_plc(t_fil *game, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_calc_angle(game, x, y);
		(!i) ? game->dist[0] = game->angle[0] : 0;
		(i == 1) ? game->dist[1] = game->angle[1] : 0;
		(i == 2) ? game->dist[2] = game->angle[2] : 0;
		(i == 3) ? game->dist[3] = game->angle[3] : 0;
		x += 2;
		y += 2;
		i++;
	}
}

void	ft_one_left(t_fil *game, int x, int y)
{
	int i;
	int c;

	i = 0;
	c = 0;
	ft_calc_angle(game, x, y);
	while (i++ < 4)
	{
		if (c < game->angle[i])
		{
			c = game->angle[i];
			game->dist[i] = c;
			if (i > 0)
				game->dist[i - 1] = -1;
		}
	}
}

void	ft_upper_horizont(t_fil *game, int x, int y)
{
	int i;

	i = 0;
	while (i < 2)
	{
		ft_calc_angle(game, x, y);
		if (!i)
			game->dist[0] = (ANGL[0] > ANGL[2]) ? ANGL[0] : ANGL[2];
		else
			game->dist[1] = (ANGL[1] > ANGL[3]) ? ANGL[1] : ANGL[3];
		i++;
		x += 2;
		y += 2;
	}
}

void	ft_left_vert(t_fil *game, int x, int y)
{
	int i;

	i = 0;
	while (i < 2)
	{
		ft_calc_angle(game, x, y);
		if (!i)
		{
			if (ANGL[0] > ANGL[1])
				game->dist[0] = ANGL[0];
			else
				game->dist[1] = ANGL[1];
		}
		else
		{
			if (ANGL[2] > ANGL[3])
				game->dist[2] = ANGL[2];
			else
				game->dist[3] = ANGL[3];
		}
		i++;
		x += 4;
		y += 4;
	}
}
