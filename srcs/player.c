/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 02:08:14 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/09 03:25:21 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	player_move(t_game *game, t_slot player)
{
	char	*input;
	t_play	pawn;
	t_bool	ok;

	ft_putendl(MSG_TO_PLAYER);
	ok = FALSE;
	while (!ok)
	{
		ft_putstr(MSG_KEY_INPUT);
		get_next_line(0, &input);
		if (!input || !ft_strtest(input, ft_isdigit))
		{
			ft_putendl(MSG_COL_WRONG);
			continue ;
		}
		pawn = add_pawn(game, ft_atoi(input), player);
		if (pawn == FULL)
			ft_putendl(MSG_COL_FULL);
		else if (pawn == WRONG)
			ft_putendl(MSG_COL_WRONG);
		else
			ok = TRUE;
	}
}
