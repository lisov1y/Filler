/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:58:30 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/20 16:20:17 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	heatmap(t_filler *flr)
{
	hmap_base(flr);
	heat_base(flr);
	go(flr);
}

void	hmap_base(t_filler *flr)
{
	int x;
	int y;

	x = -1;
	while (++x < flr->x_max)
	{
		y = -1;
		while (++y < flr->y_max)
			flr->hmap[x][y] = flr->map[x][y];
	}
}

void	heat_base(t_filler *flr)
{
	int x;
	int y;

	while (flr->hi <= 42)
	{
		x = -1;
		while (++x < flr->x_max)
		{
			y = -1;
			while (++y < flr->y_max)
				if (flr->hmap[x][y] == flr->hi)
					put_hpiece(flr, x, y);
		}
		flr->hi++;
	}
}

void	put_hpiece(t_filler *flr, int x, int y)
{
	if (x > 0 && y > 0 && y < flr->y_max - 1)
	{
		if (flr->hmap[x - 1][y - 1] == 42)
			flr->hmap[x - 1][y - 1] = flr->hi + 1;
		if (flr->hmap[x - 1][y] == 42)
			flr->hmap[x - 1][y] = flr->hi + 1;
		if (flr->hmap[x - 1][y + 1] == 42)
			flr->hmap[x - 1][y + 1] = flr->hi + 1;
	}
	if (x < flr->x_max - 1 && y > 0 && y < flr->y_max - 1)
	{
		if (flr->hmap[x + 1][y + 1] == 42)
			flr->hmap[x + 1][y + 1] = flr->hi + 1;
		if (flr->hmap[x + 1][y] == 42)
			flr->hmap[x + 1][y] = flr->hi + 1;
		if (flr->hmap[x + 1][y - 1] == 42)
			flr->hmap[x + 1][y - 1] = flr->hi + 1;
	}
	if (y > 0 && y < flr->y_max - 1)
	{
		if (flr->hmap[x][y + 1] == 42)
			flr->hmap[x][y + 1] = flr->hi + 1;
		if (flr->hmap[x][y - 1] == 42)
			flr->hmap[x][y - 1] = flr->hi + 1;
	}
}
