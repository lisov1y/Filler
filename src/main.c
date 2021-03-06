/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:03:18 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/20 16:12:19 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		main(void)
{
	t_filler	*flr;
	char		*info;

	flr = (t_filler *)malloc(sizeof(t_filler));
	info = NULL;
	get_next_line(0, &info);
	pl_num(flr, info);
	ft_strdel(&info);
	get_next_line(0, &info);
	map_num(flr, info);
	mapalloc(flr);
	ft_strdel(&info);
	while (get_next_line(0, &info))
		process(flr, info);
	map_free(flr);
}
