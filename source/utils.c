/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 03:06:32 by jhong             #+#    #+#             */
/*   Updated: 2022/03/21 02:31:10 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	printMap(t_material mat)
{
	int	row;
	int	col;

	row = 0;
	while (row < mat.map.size.y)
	{
		col = 0;
		while (col < mat.map.size.x)
		{
			loadingMap(mat, row, col);
			col++;
		}
		row++;
	}
	return (0);
}

int	printSteps(t_material *mat)
{
	char	*steps;

	steps = ft_itoa(mat->game.cntSteps);
	mlx_string_put(mat->mlxPtr, mat->winPtr, \
				(mat->img.position.x * SPRITE_W) + 5, \
				(mat->img.position.y * SPRITE_H) + 10, \
				0x833000, steps);
	free(steps);
	return (0);
}

int	printErr(char *msg)
{
	perror(msg);
	exit (EXIT_FAILURE);
}

void	printMsg(char *msg, int nbr, int mode)
{
	ft_putstr_fd(msg, 1);
	if (mode == 1)
		ft_putnbr_fd(nbr, 1);
	ft_putchar_fd('\n', 1);
}

int	exitGame(t_material *mat, char *msg)
{
	printMsg(msg, 0, 0);
	freeMap(mat);
	exit(0);
}
