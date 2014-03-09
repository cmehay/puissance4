/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svermeer <svermeer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 15:08:31 by svermeer          #+#    #+#             */
/*   Updated: 2014/03/09 17:05:55 by svermeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"puissance4.h"

int         check_col(t_game *game, int col, int row, int p[2])
{
	int     i;

	i = row;
	p[0] = 0;
	p[1] = 0;
	while (++i <= game->pos.row)
	{
		if (game->grid[col][i].slot == game->ai && p[1] == 0)
			++(p[0]);
		if (game->grid[col][i].slot != game->ai
			&& game->grid[col][i].slot != EMPTY && p[0] == 0)
			++(p[1]);
	}
	return (check_res(p));
}
