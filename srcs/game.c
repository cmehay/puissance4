/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmehay <cmehay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 14:04:01 by cmehay            #+#    #+#             */
/*   Updated: 2014/03/08 14:36:38 by cmehay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

t_dsp	*init_game(char *col, char *row)
{
	static t_dsp	*dsp;
	int				i;

	if (!dsp)
		dsp = (t_dsp*)cool_malloc(sizeof(t_dsp));
	if (dsp && col && row)
	{
		dsp->col = ft_atoi(col);
		dsp->row = ft_atoi(row);
		if (dsp->col < MAX_COL || dsp->row < MAX_ROW)
			return (dsp_error(MSG_RULES, NULL));
		dsp->game = (t_game**)cool_malloc(sizeof(t_game*) * dsp->col);
		i = dsp->col;
		while (i--)
			dsp->game[i] = (t_game*)cool_malloc(sizeof(t_game));
	}
	return (dsp);
}
