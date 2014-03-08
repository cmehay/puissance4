/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 10:53:13 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/08 15:28:06 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_COL 7
#define MAX_ROW 6

#define MSG_TO_PLAYER "Ok, it's your turn"
#define MSG_AI_HAS_PLAYED "AI has played :)"
#define MSG_KEY_INPUT "Please, enter a collum number: "
#define MSG_PLAYER_WIN "Ok... you win"
#define MSG_AI_WIN "Haha! I win"
#define MSG_DREW "Well done, I didn't win, but neither did you :p"
#define MSG_RULES \
"Please set a correct grid size to play\nUsage: puissance4 col row"

typedef enum	e_slot
{
	EMPTY,
	PLAYER1,
	PLAYER2
}				t_slot;

typedef struct	s_grid
{
	t_slot	slot;
}				t_grid;

typedef struct	s_game
{
	unsigned int	col;
	unsigned int	row;
	unsigned int	wide;
	t_slot			ai;
	t_grid			**grid;
}				t_game;

/*
** error.c
*/
void	*game_error(char *str, void *rtn);

/*
** grid.c
*/
t_game	*init_grid(char *col, char *row);
