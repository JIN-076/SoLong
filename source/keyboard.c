/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:34:12 by jhong             #+#    #+#             */
/*   Updated: 2022/03/21 02:31:35 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	pressKey(int type, t_material *mat)
{
	int	init_steps;

	init_steps = mat->game.cntSteps;
	if (type == ESC)
		exitGame(mat, "\e[33m\e[1mGame closed! (ESC)\e[0m");
	else
	{
		movement(mat, type);
		if (mat->hasEnemy > 0)
			movementToEnemy(mat, type);
	}
	if (init_steps != mat->game.cntSteps)
		printMsg("Steps: ", mat->game.cntSteps, 1);
	printMap(*mat);
	printSteps(mat);
	return (0);
}

int	exitMlx(t_material *mat)
{
	printMsg("\e[33m\e[1mGame closed! (X)\e[0m", 0, 0);
	freeMap(mat);
	exit(0);
	return (0);
}

int	failExitGame(t_material *mat, char *msg)
{
	printMsg(msg, 0, 0);
	failFreeMap(mat);
	exit(0);
	return (0);
}
