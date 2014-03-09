/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_slot_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 19:15:45 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/09 22:00:49 by svermeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"
#include "stdio.h"

int	check_vert2(t_game *game, t_pos pos, t_slot slot, int rtn)
{
	if (pos.row < game->pos.row && game->grid[pos.col][pos.row++].slot == slot)
		return (check_vert2(game, pos, slot, ++rtn));
	return (rtn);
}

int	check_low(t_game *game, t_slot player, t_pos pos)
{
	int		check;
	t_slot	slot;

	if (++(pos.row) == game->pos.row)
		return (0);
	slot = game->grid[pos.col][pos.row].slot;
	if (slot == EMPTY)
		return (1);
	check = check_vert2(game, pos, slot, 0);
	if (slot == player && check == 3)
		return (4);
	if (slot != player && check == 3)
		return (3);
	return (2);
}

int	check_diag4(t_game *game, t_pos pos, t_slot slot, int rtn)
{
	if (pos.row < game->pos.row && pos.col < game->pos.col
		&& game->grid[pos.col++][pos.row++].slot == slot)
		return (check_diag4(game, pos, slot, ++rtn));
	return (rtn);
}

int	check_low_right(t_game *game, t_slot player, t_pos pos)
{
	int		check;
	t_slot	slot;

	if (++(pos.col) == game->pos.col || ++(pos.row) == game->pos.row)
		return (0);
	slot = game->grid[pos.col][pos.row].slot;
	if (slot == EMPTY)
		return (1);
	check = check_diag4(game, pos, slot, 0);
	if (slot == player && check == 3)
		return (4);
	if (slot != player && check == 3)
		return (3);
	return (2);
}
