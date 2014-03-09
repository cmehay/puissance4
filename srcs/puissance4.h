/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:53:13 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/09 20:08:22 by cmehay           ###   ########.fr       */
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

/*
** check_slot_left.c
*/
int		check_high_left(t_game *game, t_slot player, t_pos pos);
int		check_left(t_game *game, t_slot player, t_pos pos);
int		check_diag3(t_game *game, t_pos pos, t_slot slot, int rtn);
int		check_low_left(t_game *game, t_slot player, t_pos pos);

/*
** check_slot_low.c
*/
int		check_vert2(t_game *game, t_pos pos, t_slot slot, int rtn);
int		check_low(t_game *game, t_slot player, t_pos pos);
int		check_diag4(t_game *game, t_pos pos, t_slot slot, int rtn);
int		check_low_right(t_game *game, t_slot player, t_pos pos);

/*
** check_slot_right.c
*/
int		check_high_right(t_game *game, t_slot player, t_pos pos);
int		check_hor2(t_game *game, t_pos pos, t_slot slot, int rtn);
int		check_right(t_game *game, t_slot player, t_pos pos);

/*
** detect_line.c
*/
int		check_vert(t_game *game, t_pos pos, t_slot slot, int rtn);
int		check_diag1(t_game *game, t_pos pos, t_slot slot, int rtn);
int		check_diag2(t_game *game, t_pos pos, t_slot slot, int rtn);
int		check_hor(t_game *game, t_pos pos, t_slot slot, int rtn);
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
