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

int		ft_push_upleft(t_fil *game, int way)
{
	int x;
	int y;
	int c;

	x = 0;
	y = 0;
	c = 0;
	game->yy = 0;
	game->xx = 0;
	game->ok = 0;
	game->iter = 0;
	ft_fill_arr(game);
	game->chk = 0;
	if ((x = ft_touch(game, 0, way, 0)) < 0)
		return (-1);
	return (0);
}

int		ft_push_upright(t_fil *game, int way)
{
	int x;
	int y;
	int c;

	x = 0;
	y = 0;
	c = 0;
	game->yy = 0;
	game->xx = 0;
	game->ok = 0;
	game->iter = 0;
	game->i = 0;
	game->chk = 1;
	(game->mass[way] < 0) ? (way -= 2) : 0;
	ft_fill_arr(game);
	if ((x = ft_touch(game, 0, way, 0)) < 0)
		return (-1);
	return (0);
}

int		ft_push_dwleft(t_fil *game, int way)
{
	int x;
	int y;
	int c;

	x = 0;
	y = 0;
	c = 0;
	game->i = 0;
	game->chk = 2;
	game->yy = 0;
	game->xx = 0;
	game->ok = 0;
	game->iter = 0;
	ft_fill_arr(game);
	if ((x = ft_touch(game, 0, way, 0)) < 0)
		return (-1);
	return (0);
}

int		ft_push_dwright(t_fil *game, int way)
{
	int x;
	int y;
	int c;

	x = 0;
	y = 0;
	c = 0;
	game->i = 0;
	game->chk = 3;
	game->yy = 0;
	game->xx = 0;
	game->ok = 0;
	game->iter = 0;
	(game->mass[way] < 0) ? (way -= 2) : 0;
	ft_fill_arr(game);
	if ((x = ft_touch(game, 0, way, 0)) < 0)
		return (-1);
	return (0);
}
