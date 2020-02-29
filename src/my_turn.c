/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:02:58 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/20 16:09:02 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	go(t_filler *flr)
{
	flr->maxval = 2147483647;
	while (flr->mx <= flr->x_max - flr->px_max)
	{
		if (piece_fit(flr, flr->mx, flr->my))
		{
			score_count(flr, flr->mx, flr->my);
			if (flr->maxval > flr->score && flr->score)
			{
				flr->maxval = flr->score;
				flr->fx = flr->mx;
				flr->fy = flr->my;
			}
		}
		if (flr->my < flr->y_max - flr->py_max)
			flr->my++;
		else if (flr->mx <= flr->x_max - flr->px_max)
		{
			flr->mx++;
			flr->my = 0;
		}
	}
	finish_turn(flr);
}

int		piece_fit(t_filler *flr, int x, int y)
{
	int i;
	int j;
	int touch;

	j = 0;
	touch = 0;
	while (j < flr->px_max)
	{
		i = 0;
		y = flr->my;
		while (i < flr->py_max)
		{
			if (flr->hmap[x][y] == 0 && flr->pc[j][i] == 50)
				return (0);
			else if (flr->hmap[x][y] == 99 && flr->pc[j][i] == 50)
				if (touch++ > 1)
					return (0);
			i++;
			y++;
		}
		j++;
		x++;
	}
	return (touch == 1) ? 1 : 0;
}

void	score_count(t_filler *flr, int x, int y)
{
	int i;
	int j;

	j = 0;
	flr->score = 0;
	while (j < flr->px_max)
	{
		i = 0;
		y = flr->my;
		while (i < flr->py_max)
		{
			if (flr->pc[j][i] == 50 && flr->hmap[x][y] != 99)
				flr->score += flr->hmap[x][y];
			i++;
			y++;
		}
		j++;
		x++;
	}
}

void	finish_turn(t_filler *flr)
{
	ft_putnbr(flr->fx);
	ft_putchar(' ');
	ft_putnbr(flr->fy);
	ft_putchar('\n');
	piece_free(flr);
}
