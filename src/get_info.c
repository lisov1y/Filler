/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:52:38 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/20 16:08:48 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void	map_num(t_filler *flr, char *info)
{
	if (ft_strstr(info, "Plateau 15 17:"))
	{
		flr->x_max = 15;
		flr->y_max = 17;
	}
	else if (ft_strstr(info, "Plateau 24 40:"))
	{
		flr->x_max = 24;
		flr->y_max = 40;
	}
	else if (ft_strstr(info, "Plateau 100 99:"))
	{
		flr->x_max = 100;
		flr->y_max = 99;
	}
}

void	pl_num(t_filler *flr, char *info)
{
	if (ft_strstr(info, "$$$ exec p1 : [players/mstupnik.filler]"))
		flr->plr = 1;
	else if (ft_strstr(info, "$$$ exec p2 : [players/mstupnik.filler]"))
		flr->plr = 2;
}
