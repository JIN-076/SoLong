/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:07:28 by jhong             #+#    #+#             */
/*   Updated: 2022/03/20 03:34:13 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	moveLeft(t_material *mat)
{
	mat->map.matrix[mat->img.position.y][mat->img.position.x] = '0';
	mat->img.position.x -= 1;
	mat->map.matrix[mat->img.position.y][mat->img.position.x] = 'P';
	mat->game.cntSteps++;
	mat->img.spritesPath = "./img/sprite2.xpm";
	return (0);
}

int	moveRight(t_material *mat)
{
	mat->map.matrix[mat->img.position.y][mat->img.position.x] = '0';
	mat->img.position.x += 1;
	mat->map.matrix[mat->img.position.y][mat->img.position.x] = 'P';
	mat->game.cntSteps++;
	mat->img.spritesPath = "./img/sprite1.xpm";
	return (0);
}

int	moveUp(t_material *mat)
{
	mat->map.matrix[mat->img.position.y][mat->img.position.x] = '0';
	mat->img.position.y -= 1;
	mat->map.matrix[mat->img.position.y][mat->img.position.x] = 'P';
	mat->game.cntSteps++;
	return (0);
}

int	moveDown(t_material *mat)
{
	mat->map.matrix[mat->img.position.y][mat->img.position.x] = '0';
	mat->img.position.y += 1;
	mat->map.matrix[mat->img.position.y][mat->img.position.x] = 'P';
	mat->game.cntSteps++;
	return (0);
}

int	movement(t_material *mat, int type)
{
	if ((mat->map.matrix[mat->img.position.y][mat->img.position.x - 1] == 'E') \
		&& (type == A_TYPE))
		escapeCondition(mat);
	else if ((mat->map.matrix[mat->img.position.y][mat->img.position.x - 1] \
			!= '1') && (type == A_TYPE))
		moveLeft(mat);
	if ((mat->map.matrix[mat->img.position.y - 1][mat->img.position.x] == 'E') \
		&& (type == W_TYPE))
		escapeCondition(mat);
	else if ((mat->map.matrix[mat->img.position.y - 1][mat->img.position.x] \
			!= '1') && (type == W_TYPE))
		moveUp(mat);
	if ((mat->map.matrix[mat->img.position.y][mat->img.position.x + 1] == 'E') \
		&& (type == D_TYPE))
		escapeCondition(mat);
	else if ((mat->map.matrix[mat->img.position.y][mat->img.position.x + 1] \
			!= '1') && (type == D_TYPE))
		moveRight(mat);
	if ((mat->map.matrix[mat->img.position.y + 1][mat->img.position.x] == 'E') \
		&& (type == S_TYPE))
		escapeCondition(mat);
	else if ((mat->map.matrix[mat->img.position.y + 1][mat->img.position.x] \
			!= '1') && (type == S_TYPE))
		moveDown(mat);
	return (0);
}
