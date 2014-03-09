/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 02:08:10 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/09 03:21:50 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	ai_move(t_game *game, t_slot player)
{
	int	random;

	random = (rand() % game->pos.col) + 1;
	while (add_pawn(game, random, player) != OK)
		random = (rand() % game->pos.col) + 1;
	ft_putstr(MSG_AI_HAS_PLAY);
	ft_putnbr(random);
	ft_putchar('\n');
}
