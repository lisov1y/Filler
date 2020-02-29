/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:01:41 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/20 16:19:55 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	process(t_filler *flr, char *info)
{
	fil_reset(flr);
	if (ft_strstr(info, "    0123456789"))
		x_fill(flr, info);
	else if (ft_strstr(info, "Piece"))
		piece_check(flr, info);
	ft_strdel(&info);
}

void	fil_reset(t_filler *flr)
{
	flr->px_max = 0;
	flr->py_max = 0;
	flr->hi = -1;
	flr->mx = 0;
	flr->my = 0;
	flr->maxval = 0;
	flr->score = 0;
	flr->fx = 0;
	flr->fy = 0;
}
