/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 14:04:01 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/08 15:28:08 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

t_game	*init_grid(char *col, char *row)
{
	static t_game	*game;
	int				i;

	if (!game)
		game = (t_game*)cool_malloc(sizeof(t_game));
	if (game && col && row)
	{
		game->col = ft_atoi(col);
		game->row = ft_atoi(row);
		if (game->col < MAX_COL || game->row < MAX_ROW)
			return (game_error(MSG_RULES, NULL));
		game->grid = (t_grid**)cool_malloc(sizeof(t_grid*) * game->col);
		game->ai = (rand() % 2) + 1;
		i = game->col;
		while (i--)
			game->grid[i] = (t_grid*)cool_malloc(sizeof(t_grid));
	}
	return (game);
}

int		grid_is_over(t_game	*game)
{
	
}
