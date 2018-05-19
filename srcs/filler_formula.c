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

int		ft_formula(t_fil *game, int x, int y, int tc)
{
	if (!tc)
	{
		if (game->chk == 0)
			return (RES_X + x + RES_X + y);
		if (game->chk == 1)
			return (RES_X + x + (game->map_y - (RES_Y + y)));
		if (game->chk == 2)
			return ((game->map_x - (RES_X + x) + RES_Y + y));
		if (game->chk == 3)
			return ((game->map_x - (RES_X + x)) + (game->map_y - (RES_Y + y)));
	}
	else
	{
		if (game->chk == 0)
			return (x + y);
		if (game->chk == 1)
			return (x + (game->map_y - y));
		if (game->chk == 2)
			return ((game->map_x - x) + y);
		if (game->chk == 3)
			return ((game->map_x - x) + (game->map_y - y));
	}
	return (0);
}
