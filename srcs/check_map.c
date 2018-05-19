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

void	ft_rm(t_fil *game, int rm)
{
	if (rm == 0 || rm == 1)
		(rm) ? ft_push_upright(game, rm + 1) : \
		ft_push_upleft(game, rm);
	(rm == 2) ? ft_push_dwleft(game, rm + 2) : 0;
	(rm == 3) ? ft_push_dwright(game, rm + 3) : 0;
	(RES_X == ERR) ? (game->dist[game->chk] = -1) : 0;
}

int		ft_which_way(t_fil *game, int j, int c)
{
	int rm;

	while (RES_X == ERR || RES_Y == ERR)
	{
		j = 0;
		c = -1;
		rm = -1;
		while (j < 4)
		{
			if (c < game->dist[j] && game->dist[j] >= 0)
			{
				c = game->dist[j];
				rm = j;
			}
			j++;
		}
		if (rm < 0)
		{
			ft_push_anywhere(game, 0, 0, 0);
			return (0);
		}
		ft_rm(game, rm);
	}
	return (0);
}

void	ft_shape_2(t_fil *game, int x, int y)
{
	int i;

	i = 0;
	while (i < 3)
	{
		ft_calc_angle(game, x, y);
		if (!i)
			game->dist[0] = game->angle[0];
		else if (i == 1)
			game->dist[1] = game->angle[1];
		else if (i == 2)
			game->dist[3] = (game->angle[2] > game->angle[3]) ? \
			game->angle[2] : game->angle[3];
		x += 2;
		y += 2;
		i++;
	}
}

int		ft_check_angle(t_fil *game, int x, int y)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (MASS[x] >= 0 && MASS[x + 2] < 0 && MASS[4] < 0 && MASS[6] < 0)
		ft_one_left(game, x, y);
	else if (MASS[x] >= 0 && MASS[x + 2] >= 0 &&\
	MASS[x + 4] < 0 && MASS[x + 6] < 0)
		ft_upper_horizont(game, x, y);
	else if (MASS[x] >= 0 && MASS[x + 2] < 0 && \
	MASS[x + 4] > 0 && MASS[x + 6] < 0)
		ft_left_vert(game, x, y);
	else if (MASS[x] >= 0 && MASS[x + 2] < 0 && \
	MASS[x + 4] >= 0 && MASS[x + 6] >= 0)
		ft_shape_1(game, x, y);
	else if (MASS[x] >= 0 && MASS[x + 2] >= 0 && \
	MASS[x + 4] >= 0 && MASS[x + 6] < 0)
		ft_shape_2(game, x, y);
	else if (MASS[x] >= 0 && MASS[x + 2] >= 0 && \
	MASS[x + 4] >= 0 && MASS[x + 6] >= 0)
		ft_all_in_plc(game, x, y);
	ft_which_way(game, 0, -1);
	return (0);
}

int		ft_check_map(t_fil *game, int x, int y)
{
	int ch;

	ch = 0;
	game->j = 1;
	game->i = 0;
	while (MAP[x])
	{
		y = 0;
		if ((CHR(MAP[x], PLR) || CHR(MAP[x], (PLR + 32))) && \
		(game->mass[0] < 0 && game->mass[2] < 0))
			ft_helper_check_map_3(game, &x, &y, &ch);
		(CHR(MAP[x], PLR) || CHR(MAP[x], PLR + 32)) ? (ch = x) : 0;
		x++;
	}
	ft_helper_check_map(game, game->i, game->j, ch);
	ft_check_angle(game, 0, 1);
	return (0);
}
