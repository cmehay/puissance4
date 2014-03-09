/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_slot_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 19:01:44 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/09 21:23:10 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int	check_high_right(t_game *game, t_slot player, t_pos pos)
{
	int		check;
	t_slot	slot;

	if (++(pos.col) == game->pos.col || !pos.row--)
		return (0);
	slot = game->grid[pos.col][pos.row].slot;
	if (slot == EMPTY)
		return (1);
	check = check_diag1(game, pos, slot, 0);
	if (slot == player && check == 3)
		return (4);
	if (slot != player && check == 3)
		return (3);
	return (2);
}

int	check_hor2(t_game *game, t_pos pos, t_slot slot, int rtn)
{
	if (pos.col < game->pos.col && game->grid[pos.col++][pos.row].slot == slot)
		return (check_hor2(game, pos, slot, ++rtn));
	return (rtn);
}

int	check_right(t_game *game, t_slot player, t_pos pos)
{
	int		check;
	t_slot	slot;

	if (++(pos.col) == game->pos.col)
		return (0);
	slot = game->grid[pos.col][pos.row].slot;
	if (slot == EMPTY)
		return (1);
	check = check_hor2(game, pos, slot, 0);
	if (slot == player && check == 3)
		return (4);
	if (slot != player && check == 3)
		return (3);
	return (2);
}
