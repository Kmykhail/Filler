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

void	ft_fill_arr(t_fil *game)
{
	int i;

	i = 0;
	while (i < game->tkn)
	{
		game->dt_x[i] = -1;
		game->dt_y[i] = -1;
		i++;
	}
}

void	ft_helper_check_map_2(t_fil *game)
{
	if (MASS[4] == MASS[6] && MASS[5] == MASS[7])
	{
		MASS[6] = -1;
		MASS[7] = -1;
	}
	if (MASS[0] == MASS[4] && MASS[1] == MASS[5])
	{
		MASS[4] = -1;
		MASS[5] = -1;
		if (MASS[2] == MASS[6] && MASS[3] == MASS[7])
		{
			MASS[6] = -1;
			MASS[7] = -1;
		}
	}
	if (MASS[0] == MASS[2] && MASS[1] == MASS[3])
	{
		MASS[2] = -1;
		MASS[3] = -1;
	}
}

void	ft_helper_check_map(t_fil *game, int i, int j, int ch)
{
	int x;
	int y;

	y = 0;
	x = 0;
	game->mass[i] = ch;
	while ((MAP[ch][y] != PLR))
		y++;
	game->mass[j] = y;
	i += 2;
	j += 2;
	y = 0;
	game->mass[i] = ch;
	while (MAP[ch][y++])
		(MAP[ch][y] == PLR || MAP[ch][y] == PLR + 32) ? x = y : 0;
	game->mass[j] = x;
	ft_helper_check_map_2(game);
}

void	ft_helper_check_map_3(t_fil *game, int *x, int *y, int *ch)
{
	if (game->mass[game->i] < 0)
	{
		game->mass[game->i] = *x;
		while (MAP[*x][*y] != PLR && MAP[*x][*y] != PLR + 32)
			*y += 1;
		if (game->mass[game->i] >= 0 && !game->i)
		{
			game->mass[game->j] = *y;
			game->i += 2;
			game->j += 2;
		}
		game->mass[game->i] = *x;
		*y = 0;
		while (MAP[*x][*y])
		{
			(MAP[*x][*y] == PLR || MAP[*x][*y] == PLR + 32) ? *ch = *y : 0;
			*y += 1;
		}
		game->mass[game->j] = *ch;
		game->i += 2;
		game->j += 2;
	}
}
