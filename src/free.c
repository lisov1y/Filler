/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:49:36 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/20 16:08:45 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	piece_free(t_filler *flr)
{
	int i;

	i = 0;
	while (i < flr->px_max)
		free(flr->pc[i++]);
	free(flr->pc);
}

void	map_free(t_filler *flr)
{
	int i;

	i = 0;
	while (i < flr->x_max)
		free(flr->map[i++]);
	free(flr->map);
	i = 0;
	while (i < flr->x_max)
		free(flr->hmap[i++]);
	free(flr->hmap);
	free(flr);
}
