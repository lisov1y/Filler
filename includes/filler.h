/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstupnik <mstupnik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:02:59 by mstupnik          #+#    #+#             */
/*   Updated: 2020/02/07 18:44:33 by mstupnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_libftprintf/includes/ft_printf.h"
# include "ft_libftprintf/includes/libft/includes/get_next_line.h"

typedef struct  s_filler
{
    int         x_max;
    int         y_max;
    char        **map;
    char        **hmap;
}               t_filler;

#endif