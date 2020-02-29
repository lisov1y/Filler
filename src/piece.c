/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:26:25 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/20 16:16:50 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	piece_check(t_filler *flr, char *info)
{
	int		a;
	int		b;
	char	*sym;

	sym = ft_strnew(2);
	a = 0;
	b = 0;
	while (info[a] < '0' || info[a] > '9')
		++a;
	while (info[a] >= '0' && info[a] <= '9')
		sym[b++] = info[a++];
	sym[b] = '\0';
	++a;
	flr->px_max = ft_atoi(sym);
	ft_bzero(sym, 3);
	b = 0;
	while (info[a] >= '0' && info[a] <= '9')
		sym[b++] = info[a++];
	flr->py_max = ft_atoi(sym);
	free(sym);
	piece_mem(flr);
	piece_use(flr, info);
}

void	piece_mem(t_filler *flr)
{
	int	i;

	i = 0;
	flr->pc = (int **)malloc(sizeof(int *) * flr->px_max);
	while (i < flr->px_max)
		flr->pc[i++] = (int *)malloc(sizeof(int) * flr->py_max);
}

void	piece_use(t_filler *flr, char *info)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	while (x < flr->px_max)
	{
		get_next_line(0, &info);
		i = 0;
		y = 0;
		while (y < flr->py_max)
		{
			if (info[i] == '*')
				flr->pc[x][y] = 50;
			else
				flr->pc[x][y] = 0;
			++i;
			++y;
		}
		++x;
		ft_strdel(&info);
	}
	heatmap(flr);
}
