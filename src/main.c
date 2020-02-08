/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:03:18 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/07 18:46:16 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

int     main(void)
{
    t_filler    *flr;
    char        *map;

    map = NULL;
    flr = (t_filler *)malloc(sizeof(t_filler));
    get_next_line(0, &map);
    return  (0);
}