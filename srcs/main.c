/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:53:04 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/08 18:39:59 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		turn;

	srand(time(NULL));
	if (argc != 3 || !(game = init_grid(argv[1], argv[2])))
		return ((int)game_error(MSG_RULES, (void*)1));
	turn = 0;
	while (!grid_is_over(game))
	{
		turn++;
		play(game, (turn % 2) + 1);
	}
	return (0);
}
