/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 01:21:56 by jhong             #+#    #+#             */
/*   Updated: 2022/03/20 04:07:02 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init(t_material *mat)
{
	mat->map.matrix = (char **)malloc((mat->map.size.y + 1) * sizeof(char *));
	mat->map.matrix[mat->map.size.y] = NULL;
	mat->game.cntSteps = 0;
	mat->game.cntEnemy = 0;
	mat->enemy.position.x = 0;
	mat->enemy.position.y = 0;
	mat->hasEnemy = 0;
	mat->img.spritesPath = "./img/sprite.xpm";
	return (0);
}

int	getInitCollectionCnt(t_material *mat)
{
	int	row;
	int	col;

	row = 0;
	mat->game.cntCollection = 0;
	while (row < mat->map.size.y)
	{
		col = 0;
		while (col < mat->map.size.x)
		{
			if (mat->map.matrix[row][col] == 'C')
				mat->game.cntCollection++;
			col++;
		}
		row++;
	}
	return (mat->game.cntCollection);
}

int	getInitPlayerPos(t_material *mat)
{
	int	row;
	int	col;

	row = 0;
	while (row < mat->map.size.y)
	{
		col = 0;
		while (col < mat->map.size.x)
		{
			if (mat->map.matrix[row][col] == 'P')
			{
				mat->img.position.x = col;
				mat->img.position.y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	getInitEnemyPos(t_material *mat)
{
	int		row;
	int		col;

	row = 0;
	while (row < mat->map.size.y)
	{
		col = 0;
		while (col < mat->map.size.x)
		{
			if (mat->map.matrix[row][col] == 'Y')
			{
				mat->enemy.position.x = col;
				mat->enemy.position.y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	getInitEnemyCnt(t_material *mat)
{
	int	row;
	int	col;

	row = 0;
	mat->game.cntEnemy = 0;
	while (row < mat->map.size.y)
	{
		col = 0;
		while (col < mat->map.size.x)
		{
			if (mat->map.matrix[row][col] == 'Y')
				mat->hasEnemy++;
			col++;
		}
		row++;
	}
	return (0);
}
