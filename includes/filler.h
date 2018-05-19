/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:05:01 by kmykhail          #+#    #+#             */
/*   Updated: 2017/12/17 14:23:17 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../includes/libft.h"
# include <string.h>
# include <stdio.h>
# define MAP game->map
# define PIEC game->piece
# define MASS game->mass
# define CHR ft_strchr
# define PLR game->plr
# define RES_X game->res_x
# define RES_Y game->res_y
# define ENM   game->enm
# define CHR    ft_strchr
# define ANGL	game->angle
# define ERR    -10000

typedef	struct		s_fil
{
	int				rek[4];
	int				enm_old[4];
	int				enm_new[4];
	int				xx;
	int				ok;
	int				ax;
	int				by;
	int				yy;
	int				iter;
	int				c;
	int				tkn;
	int				go;
	int				chk;
	int				mass[8];
	int				dist[5];
	int				*help_x;
	int				*help_y;
	int				cnt;
	int				i;
	int				j;
	char			plr;
	char			enm;
	int				piec_x;
	int				angle[4];
	int				*dt_x;
	int				*dt_y;
	int				res_x;
	int				res_y;
	int				piec_y;
	int				map_x;
	int				map_y;
	char			**map;
	char			**piece;
}					t_fil;

typedef struct		s_lst
{
	char			*str;
	int				fd;
	struct s_lst	*next;
}					t_lst;

void				ft_coordinat(int x, int y);
void				ft_one_left(t_fil *game, int x, int y);
void				ft_upper_horizont(t_fil *game, int x, int y);
void				ft_init(int *x, int *y, int *by, int *iter);
int					ft_touch(t_fil *game, int y, int way, int x);
void				ft_all_in_plc(t_fil *game, int x, int y);
void				ft_helper_check_map(t_fil *game, int i, int j, int ch);
void				ft_helper_check_map_3(t_fil *game, int *x, int *y, int *ch);
void				ft_shape_1(t_fil *game, int x, int y);
void				ft_left_vert(t_fil *game, int x, int y);
void				ft_calc_angle(t_fil *game, int x, int y);
void				ft_how_many_tokens(t_fil *game);
void				ft_free_game(t_fil **game);
void				ft_coordinat(int x, int y);
int					ft_check_map(t_fil *game, int add_x, int add_y);
int					ft_check_centr(t_fil *game);
void				ft_push_centr(t_fil *game, int dest_y, int q);
void				ft_init_var_fame(t_fil *game);
int					ft_push_upleft(t_fil *game, int way);
int					ft_push_upright(t_fil *game, int way);
int					ft_push_dwleft(t_fil *game, int way);
int					ft_push_dwright(t_fil *game, int way);
void				ft_fill_arr(t_fil *game);
int					get_next_line_q(const int fd, char **line);
void				ft_push_anywhere(t_fil *game, int x, int y, int iter);
void				ft_piec_cor(t_fil *game, int *x, int *y);
int					ft_formula(t_fil *game, int x, int y, int way);
#endif
