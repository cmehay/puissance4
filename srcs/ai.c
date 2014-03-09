/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svermeer <svermeer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 15:53:43 by svermeer          #+#    #+#             */
/*   Updated: 2014/03/09 17:31:16 by svermeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"puissance4.h"
#include <stdio.h>
void	    ai_move(t_game *game, t_slot player)
{
	int		*solution;
	int		i;
	int		j;
    int random;

	i = -1;
	j = -1;
	solution = (int*)cool_malloc(sizeof(*solution) * (7 * game->pos.col));
	while (++i < game->pos.col)
	{
		check_grid(game, i, solution, &j);
	}
	j = -1;
	if (find_situation(game, solution, &j) == 0)
	{
		printf("test0\n");
		add_pawn(game, (j % 7), player);
		i = game->pos.col;
		ft_putstr(MSG_AI_HAS_PLAY);
		ft_putnbr((j % 7) + 1);
		ft_putchar('\n');
		return ;
	}
	j = -1;
	if (find_situation(game, solution, &j) == 1)
	{
		printf("test1\n");
		add_pawn(game, (j % 7), player);
		ft_putstr(MSG_AI_HAS_PLAY);
		ft_putnbr((j % 7) + 1);
		ft_putchar('\n');
	}
	else
	{
		printf("test2\n");
		random = (rand() % game->pos.col) + 1;
		while (add_pawn(game, random, player) != OK)
			random = (rand() % game->pos.col) + 1;
		ft_putstr(MSG_AI_HAS_PLAY);
		ft_putnbr(random);
		ft_putchar('\n');
	}
}

int			check_grid(t_game *game, int col, int *solution, int *j)
{
	int		row;
	int		p[2];

	row = 0;
	while (game->grid[col][row].slot == EMPTY && row < game->pos.row)
		++row;
	if (row > game->pos.row)
		return (-2);
	solution[++(*j)] = check_left_row(game, col, row, p);
	solution[++(*j)] = check_diag_down_left(game, col, row, p);
	solution[++(*j)] = check_diag_up_left(game, col, row, p);
	solution[++(*j)] = check_col(game, col, row, p);
	solution[++(*j)] = check_right_row(game, col, row, p);
	solution[++(*j)] = check_diag_down_right(game, col, row, p);
	solution[++(*j)] = check_diag_up_right(game, col, row, p);
	return (-1);
}

int			find_situation(t_game *game, int *solution, int *j)
{
	while (++(*j) < (7 * game->pos.col))
	{
		printf("sol : %d, j : %d\n", solution[*j], *j);
		if (solution[*j] == -3)
		{
			return (1);
		}
		else if (solution[*j] == 3)
			return (0);
	}
	return (-1);
}
	
int			check_res(int p[2])
{
	printf("res : %d\n", p[1]);
	if (p[0] == 3)
	{
		printf("gagne\n");
		return (3); // Coup gagnant, priorite return
	}
	else if (p[1] == 3)
	{
		printf("perdu\n");
		return (-3); // Coup perdant, priorite si pas Coup gagnant dans les autres colonnes (garder en memoire)
	}
	else
	{
		return (p[0]); // rien a faire ici
	}
}

/*
IA 2 : Check des colonnes uniquement

- Verifier les n emplacements possible de jetons (n etant le nombre de colonnes dans le jeu)
- Le faire une fois pour les victoire/defaites, et une autre fois pour poser un pion (choisir une colonne aleatoire pour eviter les mouvements predictible)

Exemple verification 1ere colonne :
| | | | | | | |          |O|-|-|-|-|-|>|
|o|o|o| | | | |          |||\| | | | | |
|x|x|o| | | | |          ||| |\| | | | |
|x|o|x|o| | | |          |v| | |x| | | |
|1|2|3|4|5|6|7|          |1|2|3|4|5|6|7|

Horizontalement : rien
Verticalement : un rond, apres une croix, donc < 3, rien a jouer ici
	Diagonalement 1 : 3 ronds, donc danger, poser le pion en priorite ici
	Diagonalement 2 : pas sur la 1ere colonne
*/
