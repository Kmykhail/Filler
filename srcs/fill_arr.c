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

void	ft_piec_cor(t_fil *game, int *x, int *y)
{
	int xx;
	int yy;
	int ch;

	ch = 0;
	xx = *x;
	yy = *y;
	while (xx < game->piec_x)
	{
		yy = (!ch) ? *y : 0;
		while (PIEC[xx][yy] && yy <= game->piec_y)
		{
			if (PIEC[xx][yy] == '*')
			{
				*y = yy;
				*x = xx;
				return ;
			}
			yy++;
		}
		xx++;
		ch = 1;
	}
}

int		ft_find_map_cor(t_fil *game, int *ax, int *by)
{
	int x;
	int y;
	int ch;

	x = *ax;
	y = *by;
	ch = 0;
	while (x <= game->map_x)
	{
		y = (!ch) ? *by : 0;
		while (MAP[x][y] && y <= game->map_y)
		{
			if (MAP[x][y] == PLR)
			{
				*ax = x;
				*by = y;
				return (0);
			}
			ch = 1;
			y++;
		}
		x++;
		ch = 1;
	}
	return ((x > game->map_x && y > game->map_y) ? -1 : 0);
}

void	ft_random_piec(t_fil *game, int *x, int *y)
{
	int xx;
	int yy;
	int ch;

	xx = *x;
	yy = *y;
	ch = 0;
	while (xx < game->piec_x)
	{
		yy = (!ch) ? *y : 0;
		while (PIEC[xx][yy] && yy < game->piec_y)
		{
			if (PIEC[xx][yy] == '*')
			{
				*x = xx;
				*y = yy;
				return ;
			}
			yy++;
			ch = 1;
		}
		xx++;
		ch = 1;
	}
}

void	ft_push_anywhere_2(t_fil *game, int x, int *ok)
{
	game->xx = 0;
	game->yy = 0;
	while (game->xx < game->piec_x)
	{
		game->yy = 0;
		if (x >= game->piec_x)
			break ;
		while (PIEC[game->xx][game->yy])
		{
			if (PIEC[game->xx][game->yy] == '*' && (RES_X + game->xx >= 0 \
			&& RES_X + game->xx <= game->map_x) && (RES_Y + game->yy >= 0\
			&& RES_Y + game->yy <= game->map_y))
			{
				if (MAP[RES_X + game->xx][RES_Y + game->yy] == '.')
					*ok += 1;
			}
			game->yy++;
		}
		game->xx++;
	}
}

void	ft_push_anywhere(t_fil *game, int x, int y, int iter)
{
	game->i = 0;
	game->ok = 0;
	game->ax = 0;
	game->by = 0;
	while (game->ok != game->tkn - 1)
	{
		game->ok = 0;
		(iter >= game->tkn) ? ft_init(&x, &y, &game->by, &iter) : 0;
		ft_random_piec(game, &x, &y);
		(!iter) ? (game->i = ft_find_map_cor(game, &game->ax, &game->by)) : 0;
		if ((game->ax == game->map_x && game->by > game->map_y) || game->i < 0)
		{
			RES_X = ERR;
			RES_Y = ERR;
			break ;
		}
		RES_X = game->ax - x;
		RES_Y = game->by - y;
		ft_push_anywhere_2(game, x, &game->ok);
		iter++;
		y++;
	}
	game->ok = (game->ok != game->tkn - 1) ? 0 : game->ok;
}
