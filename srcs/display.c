/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:21:06 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/09 00:20:21 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static void	display_col_number(t_game *game, t_pos pos)
{
	int		len;
	int		i;
	char	*num;

	num = ft_itoa(pos.col);
	len = ft_strlen(num);
	i = -1;
	ft_putstr("\033[4m");
	while (++i < game->wide)
	{
		if (i == (game->wide / 2) || (i == game->wide - len
			&& i < (game->wide / 2)))
			ft_putstr(num);
		else if ((i < (game->wide / 2) || i > (game->wide / 2) + len - 1)
			&& len != game->wide)
			ft_putchar(' ');
		if (i == game->wide - len && i < (game->wide / 2))
			break ;
	}
	ft_putstr("\033[0m");
	ft_putchar('|');
	free(num);
}

static void	display_pawn(t_game *game, t_pos pos)
{
	int		i;
	char	pawn;

	if (game->grid[pos.col - 1][pos.row].slot == PLAYER1)
		pawn = PLAYER_1_PAWN;
	else if (game->grid[pos.col - 1][pos.row].slot == PLAYER1)
		pawn = PLAYER_2_PAWN;
	else
		pawn = ' ';
	i = -1;
	while (++i < game->wide)
	{
		if (i == (game->wide / 2))
			ft_putchar(pawn);
		else
			ft_putchar(' ');
	}
	ft_putchar('|');
}

static void	display_grid_static(t_game *game, t_pos pos)
{
	int	i;

	if (!pos.col)
		return (ft_putchar('|'));
	if (!pos.row)
	{
		i = game->wide + 1;
		while (i--)
		{
			if (pos.col == game->pos.col && !i)
				ft_putchar('|');
			else
				ft_putchar('-');
		}
		return ;
	}
	if (pos.row == game->pos.row + 1)
		return (display_col_number(game, pos));
	if (pos.row)
		return (display_pawn(game, pos));
}

void		display_grid(t_game *game)
{
	t_pos	pos;

	pos.row = -1;
	while (++(pos.row) < (game->pos.row) + 2)
	{
		pos.col = -1;
		while (++(pos.col) < (game->pos.col) + 1)
			display_grid_static(game, pos);
		ft_putchar('\n');
	}
}
