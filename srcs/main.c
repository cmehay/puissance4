/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:53:04 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/09 03:11:46 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		turn;
	int		end;

	srand(time(NULL));
	if (argc != 3 || !(game = init_game(argv[1], argv[2])))
		return ((int)dsp_error(MSG_RULES, (void*)1));
	turn = 0;
	while (!(end = game_is_over(game)))
	{
		play(game, turn);
		turn++;
	}
	display_grid(game);
	if (end == -1)
		ft_putendl(MSG_DREW);
	else if (end == game->ai)
		ft_putendl(MSG_AI_WIN);
	else
		ft_putendl(MSG_PLAYER_WIN);
	free_for_all(NULL);
	return (0);
}
