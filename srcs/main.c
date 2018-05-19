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

void	ft_init_var_fame(t_fil *game)
{
	int i;

	i = 0;
	while (i < 8)
		game->mass[i++] = -1;
	i = 0;
	while (i < 4)
	{
		game->rek[i] = -1;
		game->dist[i] = -1;
		game->angle[i++] = -1;
	}
	game->dist[i] = -1;
	game->chk = -1;
	game->tkn = 0;
	game->xx = 0;
	game->yy = 0;
	game->go = 0;
	game->res_x = ERR;
	game->res_y = ERR;
	game->cnt = 0;
	game->map = NULL;
	game->i = 0;
	game->piece = NULL;
}

int		ft_create_map(t_fil *game, char **line, int fd)
{
	int k;

	k = 0;
	get_next_line_q(fd, &(*line));
	game->map_x = ft_atoi(ft_strchr(*line, ' '));
	game->map_y = ft_atoi(ft_strrchr(*line, ' '));
	game->map = (char**)malloc(sizeof(char*) * (game->map_x + 1));
	while (k < game->map_x)
	{
		get_next_line_q(0, &(*line));
		if (*line)
			if (CHR(*line, '0') && CHR(*line, ' ') && !ft_strstr(*line, "0123"))
				game->map[k++] = ft_strdup(*line + 4);
		if (game->map_x == k)
		{
			MAP[game->map_x] = NULL;
			ft_strdel(&(*line));
			game->map_x -= 1;
			game->map_y -= 1;
			game->cnt = 0;
			return (0);
		}
		ft_strdel(&(*line));
	}
	return (0);
}

int		ft_create_piece(t_fil *game, char **line, int fd)
{
	get_next_line_q(fd, &(*line));
	if (ft_strstr(*line, "Piece"))
	{
		game->piec_x = ft_atoi(ft_strchr(*line, ' '));
		game->piec_y = ft_atoi(ft_strrchr(*line, ' '));
		game->piece = (char**)malloc(sizeof(char*) * (game->piec_x + 1));
		ft_strdel(&(*line));
	}
	while (get_next_line_q(fd, &(*line)))
	{
		game->piece[game->cnt++] = ft_strdup(*line);
		if (game->cnt == game->piec_x)
		{
			ft_how_many_tokens(game);
			ft_strdel(&(*line));
			return (0);
		}
		ft_strdel(&(*line));
	}
	return (0);
}

void	ft_free_game(t_fil **game)
{
	int i;
	int k;

	i = 0;
	k = 0;
	(*game)->i = 0;
	(*game)->cnt = 0;
	(*game)->tkn = 0;
	(*game)->cnt = 0;
	(*game)->piec_x = 0;
	(*game)->piec_y = 0;
	(*game)->map_x = 0;
	(*game)->map_y = 0;
	while ((*game)->map[i])
		ft_strdel(&(*game)->map[i++]);
	free((*game)->map);
	while ((*game)->piece[k])
		ft_strdel(&(*game)->piece[k++]);
	free((*game)->piece);
	free((*game)->help_x);
	free((*game)->help_y);
	free((*game)->dt_x);
	free((*game)->dt_y);
}

int		main(void)
{
	char	*line;
	t_fil	*game;

	game = malloc(sizeof(t_fil));
	get_next_line_q(0, &line);
	game->plr = (line[10] == '1') ? 'O' : 'X';
	game->enm = (game->plr == 'O') ? 'X' : 'O';
	while (1)
	{
		ft_init_var_fame(game);
		ft_create_map(game, &line, 0);
		ft_create_piece(game, &line, 0);
		ft_check_map(game, 0, 0);
		if (game->res_x == ERR && game->res_y == ERR)
		{
			ft_coordinat(0, 0);
			break ;
		}
		else
			ft_coordinat(game->res_x, game->res_y);
		ft_free_game(&game);
	}
	free(game);
	return (0);
}
