/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 03:54:31 by jhong             #+#    #+#             */
/*   Updated: 2022/03/21 02:09:31 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	movementToEnemy(t_material *mat, int type)
{
	if ((mat->map.matrix[mat->img.position.y][mat->img.position.x - 1] == 'Y')
		&& (type == A_TYPE))
		exitGame(mat, "You Lose: Player touches the Enemy, Game is Fail\n");
	if ((mat->map.matrix[mat->img.position.y - 1][mat->img.position.x] == 'Y')
		&& (type == W_TYPE))
		exitGame(mat, "You Lose: Player touches the Enemy, Game is Fail\n");
	if ((mat->map.matrix[mat->img.position.y][mat->img.position.x + 1] == 'Y')
		&& (type == D_TYPE))
		exitGame(mat, "You Lose: Player touches the Enemy, Game is Fail\n");
	if ((mat->map.matrix[mat->img.position.y + 1][mat->img.position.x] == 'Y')
		&& (type == S_TYPE))
		exitGame(mat, "You Lose: Player touches the Enemy, Game is Fail\n");
	return (0);
}

int	escapeCondition(t_material *mat)
{
	if (getInitCollectionCnt(mat) == 0)
		exitGame(mat, "Congratulation! You WON!!");
	else
		exitGame(mat, "You must collect Diamond MORE!");
	return (0);
}

int	animationEnemy(t_material *mat)
{
	if (mat->enemy.position.x % 2 == 0)
	{
		mat->img.imgPtr = mlx_xpm_file_to_image(mat->mlxPtr, \
					"./img/enemy1.xpm", &mat->img.size.x, &mat->img.size.y);
	}
	else
	{
		mat->img.imgPtr = mlx_xpm_file_to_image(mat->mlxPtr, \
					"./img/enemy2.xpm", &mat->img.size.x, &mat->img.size.y);
	}
	return (0);
}

int	freeMap(t_material *mat)
{
	int	row;

	row = 0;
	mlx_destroy_window(mat->mlxPtr, mat->winPtr);
	free(mat->mlxPtr);
	while (row < mat->map.size.y)
	{
		free(mat->map.matrix[row]);
		row++;
	}
	free(mat->map.matrix);
	return (0);
}

int	failFreeMap(t_material *mat)
{
	int	row;

	row = 0;
	while (row < mat->map.size.y)
	{
		free(mat->map.matrix[row]);
		row++;
	}
	free(mat->map.matrix);
	return (0);
}
