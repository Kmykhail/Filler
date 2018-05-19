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

void	ft_check_best(t_fil *game, int *s_dist, int x)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (i < game->tkn)
	{
		if (!res || (res > s_dist[i] && s_dist[i] >= 0))
		{
			res = s_dist[i];
			x = i;
			res = (res < 0) ? 0 : res;
		}
		i++;
	}
	if (s_dist[x] == ERR)
	{
		RES_X = ERR;
		RES_Y = ERR;
		return ;
	}
	RES_X = game->dt_x[x];
	RES_Y = game->dt_y[x];
	free(s_dist);
}

void	ft_init_short_angle(t_fil *game, int **s_dist)
{
	game->i = 0;
	*s_dist = malloc(sizeof(int) * (game->tkn + 1));
	while (game->i < game->tkn)
		(*s_dist)[game->i++] = -1;
	game->i = 0;
}

void	ft_analyz_short_angle(t_fil *game, int x, int y, int res)
{
	int *s_dist;

	ft_init_short_angle(game, &s_dist);
	while (game->i < game->tkn)
	{
		res = 0;
		x = game->dt_x[game->i];
		y = game->dt_y[game->i];
		while (x++ < game->piec_x + game->dt_x[game->i])
		{
			y = game->dt_y[game->i];
			if (y == ERR || x == ERR)
				break ;
			while (y++ < game->piec_y + game->dt_y[game->i])
			{
				if (!res || res > ft_formula(game, x, y, 1))
				{
					res = ft_formula(game, x, y, 1);
					s_dist[game->i] = res;
				}
			}
		}
		game->i++;
	}
	ft_check_best(game, s_dist, x);
}

int		ft_helper_touch(t_fil *game, int *x, int *y, int *way)
{
	*y = 0;
	if (MASS[*way] < 0 || MASS[*way + 1] < 0)
		return (-1);
	while (PIEC[*x][*y])
	{
		if (PIEC[*x][*y] == '*' && (RES_X + *x >= 0 && RES_X + *x <= \
		game->map_x) && (RES_Y + *y >= 0 && RES_Y + *y <= game->map_y))
		{
			game->ok += (MAP[RES_X + *x][RES_Y + *y] == '.') ? 1 : 0;
			if (!game->i || game->i > ft_formula(game, *x, *y, 0))
			{
				game->dt_x[game->iter] = RES_X;
				game->dt_y[game->iter] = RES_Y;
				game->i = ft_formula(game, *x, *y, 0);
			}
		}
		*y += 1;
	}
	*x += 1;
	return (0);
}

int		ft_touch(t_fil *game, int y, int way, int x)
{
	RES_X = 0;
	RES_Y = 0;
	while (game->iter < game->tkn)
	{
		game->ok = 0;
		game->i = 0;
		ft_piec_cor(game, &game->xx, &game->yy);
		if (game->xx >= game->piec_x || game->yy >= game->piec_y)
			break ;
		RES_X = MASS[way] - game->xx;
		RES_Y = MASS[way + 1] - game->yy;
		x = 0;
		while (RES_X + x <= game->map_x && x < game->piec_x)
			if (ft_helper_touch(game, &x, &y, &way) < 0)
				break ;
		game->yy++;
		if (game->ok != game->tkn - 1)
		{
			game->dt_x[game->iter] = ERR;
			game->dt_y[game->iter] = ERR;
		}
		game->iter++;
	}
	ft_analyz_short_angle(game, 0, 0, 0);
	return (0);
}
