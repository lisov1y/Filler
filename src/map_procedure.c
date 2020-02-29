/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_procedure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 10:06:43 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/20 16:15:02 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	x_fill(t_filler *flr, char *info)
{
	int x;
	int y;

	x = 0;
	while (x < flr->x_max)
	{
		get_next_line(0, &info);
		y = 0;
		y_fill(flr, info, x, y);
		++x;
		ft_strdel(&info);
	}
}

void	y_fill(t_filler *flr, char *info, int x, int y)
{
	while (y < flr->y_max)
	{
		if (info[y + 4] == 'O' && flr->plr == 1)
			flr->map[x][y] = 99;
		else if (info[y + 4] == 'o' && flr->plr == 1)
			flr->map[x][y] = 98;
		else if (info[y + 4] == 'X' && flr->plr == 2)
			flr->map[x][y] = 99;
		else if (info[y + 4] == 'x' && flr->plr == 2)
			flr->map[x][y] = 98;
		else if (info[y + 4] == 'x' || info[y + 4] == 'X' ||
				info[y + 4] == 'o' || info[y + 4] == 'O')
			flr->map[x][y] = 0;
		else
			flr->map[x][y] = 42;
		++y;
	}
}

void	mapalloc(t_filler *flr)
{
	int line;

	line = 0;
	flr->map = (int **)malloc(sizeof(int *) * flr->x_max);
	while (line < flr->x_max)
	{
		flr->map[line] = (int *)malloc(sizeof(int) * flr->y_max);
		++line;
	}
	line = 0;
	flr->hmap = (int **)malloc(sizeof(int *) * flr->x_max);
	while (line < flr->x_max)
	{
		flr->hmap[line] = (int *)malloc(sizeof(int) * flr->y_max);
		++line;
	}
}
