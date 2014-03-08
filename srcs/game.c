/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 14:04:01 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/09 00:17:12 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

t_game	*init_game(char *col, char *row)
{
	static t_game	*game;
	int				i;

	if (!game)
		game = (t_game*)cool_malloc(sizeof(t_game));
	if (game && col && row)
	{
		game->pos.col = ft_atoi(col);
		game->pos.row = ft_atoi(row);
		if (game->pos.col < MAX_COL || game->pos.row < MAX_ROW)
			return (dsp_error(MSG_RULES, NULL));
		game->wide = ft_strlen(col) + !(ft_strlen(col) % 2);
		game->grid = (t_grid**)cool_malloc(sizeof(t_grid*) * game->pos.col);
		game->ai = (rand() % 2) + 1;
		i = game->pos.col;
		while (i--)
			game->grid[i] = (t_grid*)cool_malloc(sizeof(t_grid));
	}
	return (game);
}
