/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svermeer <svermeer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 14:31:33 by svermeer          #+#    #+#             */
/*   Updated: 2014/03/09 17:27:29 by svermeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"puissance4.h"

int         check_diag_down_left(t_game *game, int col, int row, int p[2])
{
	int		i;
	int		j;

	i = col;
	j = row;
	p[0] = 0;
	p[1] = 0;
    while (--i >= 0 && ++j < game->pos.row)
    {
        if (game->grid[i][j].slot == game->ai && p[1] == 0)
            ++(p[0]);
        if (game->grid[i][j].slot != game->ai
			&& game->grid[i][j].slot != EMPTY && p[0] == 0)
            ++(p[1]);
	}
	return (check_res(p));
}

int         check_diag_up_left(t_game *game, int col, int row, int p[2])
{
	int		i;
	int		j;

	i = col;
	j = row;
	p[0] = 0;
	p[1] = 0;
    while (--i >= 0 && --j >= 0)
    {
        if (game->grid[i][j].slot == game->ai && p[1] == 0)
            ++(p[0]);
        if (game->grid[i][j].slot != game->ai
			&& game->grid[i][j].slot != EMPTY && p[0] == 0)
            ++(p[1]);
	}
	return (check_res(p));
}

int         check_diag_down_right(t_game *game, int col, int row, int p[2])
{
	int		i;
	int		j;

	i = col;
	j = row;
	p[0] = 0;
	p[1] = 0;
    while (++i < game->pos.col && ++j < game->pos.row)
    {
        if (game->grid[i][j].slot == game->ai && p[1] == 0)
            ++(p[0]);
        if (game->grid[i][j].slot != game->ai
			&& game->grid[i][j].slot != EMPTY && p[0] == 0)
            ++(p[1]);
	}
	return (check_res(p));
}
#include <stdio.h>
int         check_diag_up_right(t_game *game, int col, int row, int p[2])
{
	int		i;
	int		j;

	i = col;
	j = row;
	p[0] = 0;
	p[1] = 0;
    while (++i < game->pos.col && --j >= 0)
    {
        if (game->grid[i][j].slot == game->ai && p[1] == 0) 
            ++(p[0]);
       if (game->grid[i][j].slot != game->ai
		   && game->grid[i][j].slot != EMPTY && p[0] == 0)
            ++(p[1]);
	}
	/* printf("row : %d, col : %d, ai : %d, p : %d\n", row, col, p[0], p[1]); */
	return (check_res(p));
}
