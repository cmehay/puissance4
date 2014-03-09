/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 02:08:10 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/09 22:54:52 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int	check_slot(t_game *game, t_slot player, int col)
{
	int		i;
	t_pos	pos;
	int		check[7] =
	{
		0
	};

	i = -1;
	while (++i < game->pos.row && !game->grid[col][i].slot)
		;
	if (!i--)
		return (0);
	pos.col = col;
	pos.row = i;
	check[0] = check_high_left(game, player, pos);
	check[1] = check_left(game, player, pos);
	check[2] = check_low_left(game, player, pos);
	check[3] = check_low(game, player, pos);
	check[4] = check_low_right(game, player, pos);
	check[5] = check_right(game, player, pos);
	check[6] = check_high_right(game, player, pos);
	return (ft_higher(check, 7));
}

static int	find_best_move(t_game *game, t_slot player)
{
	int	i;
	int	*check;
	int	rtn;

	i = game->pos.col;
	check = (int*)cool_malloc(sizeof(int) * game->pos.col);
	while (i--)
		check[i] = check_slot(game, player, i);
	rtn = ft_higher_idx(check, game->pos.col);
	if (ft_higher(check, game->pos.col) < 2)
	{
		ft_putnbr(ft_higher(check, game->pos.col));ft_putendl(" random");
		rtn = (rand() % game->pos.col);
	}
	else
		ft_putnbr(ft_higher(check, game->pos.col));ft_putendl(" set");
	cool_free(check);
	return (rtn + 1);
}

void		ai_move(t_game *game, t_slot player)
{
	int	move;

	move = find_best_move(game, player);
	while (add_pawn(game, move, player) != OK)
		move = (rand() % game->pos.col) + 1;
	ft_putstr(MSG_AI_HAS_PLAY);
	ft_putnbr(move);
	ft_putchar('\n');
}
