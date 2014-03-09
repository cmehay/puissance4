/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svermeer <svermeer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 14:32:06 by svermeer          #+#    #+#             */
/*   Updated: 2014/03/09 17:31:05 by svermeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"puissance4.h"
#include <stdio.h>

int			check_left_row(t_game *game, int col, int row, int p[2])
{
	int		i;

	i = col;
	p[0] = 0;
	p[1] = 0;
    while (--i >= 0)
    {
        if (game->grid[i][row].slot == game->ai && p[1] == 0)
            ++(p[0]);
        if (game->grid[i][row].slot != game->ai
			&& game->grid[i][row].slot != EMPTY && p[0] == 0)
            ++(p[1]);
    }
	return (check_res(p));
}

int			check_right_row(t_game *game, int col, int row, int p[2])
{
	int		i;

	i = col;
	p[0] = 0;
	p[1] = 0;
    while (++i < game->pos.col)
    {
        if (game->grid[i][row].slot == game->ai && p[1] == 0)
            ++(p[0]);
        if (game->grid[i][row].slot != game->ai
			&& game->grid[i][row].slot != EMPTY && p[0] == 0)
            ++(p[1]);
    }
	return (check_res(p));
}
