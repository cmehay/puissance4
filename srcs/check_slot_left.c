/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_slot_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 19:15:49 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/09 22:35:47 by svermeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int	check_high_left(t_game *game, t_slot player, t_pos pos)
{
	int		check;
	t_slot	slot;

	if (!pos.col-- || !pos.row--)
		return (0);
	slot = game->grid[pos.col][pos.row].slot;
	if (slot == EMPTY)
		return (1);
	check = check_diag2(game, pos, slot, 0);
	if (slot == player && check == 3)
		return (4);
	if (slot != player && check == 3)
		return (3);
	return (2);
}

int	check_left(t_game *game, t_slot player, t_pos pos)
{
	int		check;
	t_slot	slot;

	if (!pos.col--)
		return (0);
	slot = game->grid[pos.col][pos.row].slot;
	if (slot == EMPTY)
		return (1);
	check = check_hor(game, pos, slot, 0);
	if (slot == player && check == 3)
		return (4);
	if (slot != player && check == 3)
		return (3);
	return (2);
}

int	check_diag3(t_game *game, t_pos pos, t_slot slot, int rtn)
{
	if (pos.row < game->pos.row && pos.col > -1
		&& game->grid[pos.col--][pos.row++].slot == slot)
		return (check_diag3(game, pos, slot, ++rtn));
	return (rtn);
}

int	check_low_left(t_game *game, t_slot player, t_pos pos)
{
	int		check;
	t_slot	slot;

	if (!pos.col-- || ++(pos.row) == game->pos.row)
		return (0);
	slot = game->grid[pos.col][pos.row].slot;
	if (slot == EMPTY)
		return (1);
	check = check_diag3(game, pos, slot, 0);
	if (slot == player && check == 3)
		return (4);
	if (slot != player && check == 3)
		return (3);
	return (2);
}
