/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:53:13 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/09 16:53:37 by svermeer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_COL 7
#define MAX_ROW 6

#define PLAYER_1_PAWN "x"
#define PLAYER_2_PAWN "o"

#define MSG_TO_PLAYER "Ok, it's your turn"
#define MSG_AI_HAS_PLAY "I play in "
#define MSG_KEY_INPUT "Please, enter a collum number: "
#define MSG_PLAYER_WIN "Ok... you win"
#define MSG_AI_WIN "p0wned! I win"
#define MSG_DREW "Well done, I didn't win, but neither did you :p"
#define MSG_RULES \
"Please set a correct grid size to play\nUsage: puissance4 col row"
#define MSG_TURN "Turn number: "
#define MSG_COL_FULL "This collum is full"
#define MSG_COL_WRONG "This collum is not valid"


typedef enum	e_slot
{
	EMPTY,
	PLAYER1,
	PLAYER2
}				t_slot;

typedef enum	e_play
{
	OK,
	FULL,
	WRONG
}				t_play;

typedef struct	s_pos
{
	int	col;
	int	row;
}				t_pos;

typedef struct	s_grid
{
	t_slot	slot;
}				t_grid;

typedef struct	s_game
{
	int		wide;
	t_pos	pos;
	t_slot	ai;
	t_grid	**grid;
}				t_game;

/*
** ai.c
*/
void	ai_move(t_game *game, t_slot player);
int		check_grid(t_game *game, int col, int *solution, int *j);
int		find_situation(t_game *game, int *solution, int *j);
int		check_res(int p[2]);

/*
** check_col.c
*/
int		check_col(t_game *game, int col, int row, int p[2]);

/*
** check_diag.c
*/
int		check_diag_up_left(t_game *game, int col, int row, int p[2]);
int		check_diag_up_right(t_game *game, int col, int row, int p[2]);
int		check_diag_down_left(t_game *game, int col, int row, int p[2]);
int		check_diag_down_right(t_game *game, int col, int row, int p[2]);

/*
** check_row.c
*/
int		check_right_row(t_game *game, int col, int row, int p[2]);
int		check_left_row(t_game *game, int col, int row, int p[2]);

/*
** detect_line.c
*/
int		game_is_over(t_game *game);

/*
** display.c
*/
void	display_grid(t_game *game);

/*
** error.c
*/
void	*dsp_error(char *str, void *rtn);

/*
** game.c
*/
t_game	*init_game(char *col, char *row);

/*
** grid.c
*/
t_game	*init_game(char *col, char *row);

/*
** play.c
*/
t_play	add_pawn(t_game *game, int col, t_slot player);
void	play(t_game *game, int turn);

/*
** player.c
*/
void	player_move(t_game *game, t_slot player);
