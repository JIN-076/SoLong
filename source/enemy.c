/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:42:25 by jhong             #+#    #+#             */
/*   Updated: 2022/03/21 02:03:59 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	moveLeftEnemy(t_material *mat)
{
	if (mat->map.matrix[mat->enemy.position.y][mat->enemy.position.x - 1] \
	== 'P')
		exitGame(mat, "You Lose: Player touches the Enemy, Game is Fail\n");
	mat->map.matrix[mat->enemy.position.y][mat->enemy.position.x] = '0';
	mat->enemy.position.x -= 1;
	mat->map.matrix[mat->enemy.position.y][mat->enemy.position.x] = 'Y';
	mat->game.cntEnemy++;
	return (0);
}

int	moveRightEnemy(t_material *mat)
{
	if (mat->map.matrix[mat->enemy.position.y][mat->enemy.position.x + 1] \
	== 'P')
		exitGame(mat, "You Lose: Player touches the Enemy, Game is Fail\n");
	mat->map.matrix[mat->enemy.position.y][mat->enemy.position.x] = '0';
	mat->enemy.position.x += 1;
	mat->map.matrix[mat->enemy.position.y][mat->enemy.position.x] = 'Y';
	mat->game.cntEnemy++;
	return (0);
}

int	moveUpEnemy(t_material *mat)
{
	if (mat->map.matrix[mat->enemy.position.y + 1][mat->enemy.position.x] \
	== 'P')
		exitGame(mat, "You Lose: Player touches the Enemy, Game is Fail\n");
	mat->map.matrix[mat->enemy.position.y][mat->enemy.position.x] = '0';
	mat->enemy.position.y += 1;
	mat->map.matrix[mat->enemy.position.y][mat->enemy.position.x] = 'Y';
	mat->game.cntEnemy++;
	return (0);
}

int	moveDownEnemy(t_material *mat)
{
	if (mat->map.matrix[mat->enemy.position.y - 1][mat->enemy.position.x] \
	== 'P')
		exitGame(mat, "You Lose: Player touches the Enemy, Game is Fail\n");
	mat->map.matrix[mat->enemy.position.y][mat->enemy.position.x] = '0';
	mat->enemy.position.y -= 1;
	mat->map.matrix[mat->enemy.position.y][mat->enemy.position.x] = 'Y';
	mat->game.cntEnemy++;
	return (0);
}

int	patrol(t_material *mat)
{
	int	X;
	int	Y;

	usleep(200000);
	getInitEnemyPos(mat);
	X = mat->enemy.position.x;
	Y = mat->enemy.position.y;
	if ((mat->map.matrix[Y][X + 1] == '0' || mat->map.matrix[Y][X + 1] \
	== 'P') && mat->game.cntEnemy < mat->map.size.x)
		moveRightEnemy(mat);
	else if ((mat->map.matrix[Y + 1][X] == '0' || mat->map.matrix[Y + 1][X] \
	== 'P') && mat->game.cntEnemy < (mat->map.size.x + mat->map.size.y))
		moveUpEnemy(mat);
	else if ((mat->map.matrix[Y][X - 1] == '0' || mat->map.matrix[Y][X - 1] \
	== 'P') && mat->game.cntEnemy < ((2 * mat->map.size.x) + mat->map.size.y))
		moveLeftEnemy(mat);
	else if ((mat->map.matrix[Y - 1][X] == '0' || mat->map.matrix[Y - 1][X] \
	== 'P') && mat->game.cntEnemy < (2 * (mat->map.size.x + mat->map.size.y)))
		moveDownEnemy(mat);
	else
		mat->game.cntEnemy = 0;
	printMap(*mat);
	printSteps(mat);
	return (0);
}
