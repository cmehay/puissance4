/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 15:25:07 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/09 22:03:20 by svermeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int	check_vert(t_game *game, t_pos pos, t_slot slot, int rtn)
{
	if (pos.row > -1 && game->grid[pos.col][pos.row--].slot == slot)
		return (check_vert(game, pos, slot, ++rtn));
	return (rtn);
}

int	check_diag1(t_game *game, t_pos pos, t_slot slot, int rtn)
{
	if (pos.row > -1 && pos.col < game->pos.col
		&& game->grid[pos.col++][pos.row--].slot == slot)
		return (check_diag1(game, pos, slot, ++rtn));
	return (rtn);
}

int	check_diag2(t_game *game, t_pos pos, t_slot slot, int rtn)
{
	if (pos.row > -1 && pos.col > -1
		&& game->grid[pos.col--][pos.row--].slot == slot)
		return (check_diag2(game, pos, slot, ++rtn));
	return (rtn);
}

int	check_hor(t_game *game, t_pos pos, t_slot slot, int rtn)
{
	if (pos.col > -1 && game->grid[pos.col--][pos.row].slot == slot)
		return (check_hor(game, pos, slot, ++rtn));
	return (rtn);
}

int	game_is_over(t_game *game)
{
	t_pos	pos;
	t_slot	slot;
	int		count;

	pos.col = -1;
	count = 0;
	while (++(pos.col) < game->pos.col)
	{
		pos.row = -1;
		while (++(pos.row) < game->pos.row)
		{
			if ((slot = game->grid[pos.col][pos.row].slot))
			{
				count++;
				if (check_vert(game, pos, slot, 0) == 4
					|| check_diag1(game, pos, slot, 0) == 4
					|| check_diag2(game, pos, slot, 0) == 4
					|| check_hor(game, pos, slot, 0) == 4)
					return (slot);
			}
		}
	}
	if (count == game->pos.row * game->pos.col)
		return (-1);
	return (0);
}
