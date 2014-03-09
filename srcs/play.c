/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:08:38 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/09 22:53:24 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

t_play			add_pawn(t_game *game, int col, t_slot player)
{
	int	i;

	if (col < 1 || col > game->pos.col)
		return (WRONG);
	if (game->grid[col - 1][0].slot)
		return (FULL);
	i = -1;
	while (++i < game->pos.row && !game->grid[col - 1][i].slot)
		;
	game->grid[col - 1][--i].slot = player;
	return (OK);
}

static void		player_play(t_game *game, int turn)
{
	if ((turn % 2) + 1 == game->ai)
		ai_move(game, (turn % 2) + 1);
	else
		player_move(game, (turn % 2) + 1);
}

void			play(t_game *game, int turn)
{
	ft_putstr(MSG_TURN);
	ft_putnbr(turn);
	ft_putchar('\n');
	display_grid(game);
	player_play(game, turn);
}
