/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:02:59 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/20 16:23:59 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_libftprintf/includes/ft_printf.h"
# include "ft_libftprintf/includes/libft/includes/get_next_line.h"

typedef struct	s_filler
{
	int			x_max;
	int			y_max;
	int			plr;
	int			px_max;
	int			py_max;
	int			hi;
	int			score;
	int			maxval;
	int			mx;
	int			my;
	int			fx;
	int			fy;
	int			**map;
	int			**pc;
	int			**hmap;
}				t_filler;

/*
** get_info.c
*/

void			map_num(t_filler *flr, char *info);
void			pl_num(t_filler *flr, char *info);

/*
** map_procedure.c
*/

void			x_fill(t_filler *flr, char *info);
void			y_fill(t_filler *flr, char *info, int x, int y);
void			mapalloc(t_filler *flr);

/*
** process.c
*/

void			process(t_filler *flr, char *info);
void			fil_reset(t_filler *flr);

/*
** piece.c
*/

void			piece_check(t_filler *flr, char *info);
void			piece_mem(t_filler *flr);
void			piece_use(t_filler *flr, char *info);

/*
** heatmap.c
*/

void			heatmap(t_filler *flr);
void			hmap_base(t_filler *flr);
void			heat_base(t_filler *flr);
void			put_hpiece(t_filler *flr, int x, int y);

/*
** my_turn.c
*/

void			go(t_filler *flr);
int				piece_fit(t_filler *flr, int x, int y);
void			score_count(t_filler *flr, int x, int y);
void			finish_turn(t_filler *flr);

/*
** free.c
*/

void			piece_free(t_filler *flr);
void			map_free(t_filler *flr);

#endif
