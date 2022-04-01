/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 03:23:54 by jhong             #+#    #+#             */
/*   Updated: 2022/03/21 04:54:53 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	wallCheck(t_material mat)
{
	int	row;
	int	col;

	row = 0;
	while (row < mat.map.size.y)
	{
		col = 0;
		if (row == 0 || row == mat.map.size.y - 1)
		{
			while (mat.map.matrix[row][col])
			{
				if (mat.map.matrix[row][col] != '1')
					failExitGame(&mat, "Invalid Maps: \
							The map must be surrounded by Walls\n");
				col++;
			}
		}
		if (mat.map.matrix[row][0] != '1'
			|| mat.map.matrix[row][mat.map.size.x - 1] != '1')
			failExitGame(&mat, "Invalid Maps: The map must be surrounded \
														by Walls\n");
		row++;
	}
	return (0);
}

int	spritesCheck(t_material mat)
{
	int	arg[3];
	int	row;
	int	col;

	row = 0;
	while (row < mat.map.size.y)
	{
		col = 0;
		while (col <= mat.map.size.x)
		{
			if (mat.map.matrix[row][col] == 'P')
				arg[0] = 1;
			if (mat.map.matrix[row][col] == 'E')
				arg[1] = 1;
			if (mat.map.matrix[row][col] == 'C')
				arg[2] = 1;
			col++;
		}
		row++;
	}
	if (arg[0] != 1 || arg[1] != 1 || arg[2] != 1)
		failExitGame(&mat, "Invalid Maps: The map must include at least \
				one Exit, one fish Collection, and one Starting point\n");
	return (0);
}

int	rectangleCheck(t_material mat)
{
	int	row;

	row = 0;
	while (row < mat.map.size.y)
	{
		if (mat.map.size.x != (int)ft_strlen(mat.map.matrix[row]))
			failExitGame(&mat, "Invalid Maps: The map must be rectangular\n");
		row++;
	}
	return (0);
}

int	stringCheck(t_material mat)
{
	int	row;
	int	col;

	row = 0;
	while (row < mat.map.size.y)
	{
		col = 0;
		while (mat.map.matrix[row][col])
		{
			if (mat.map.matrix[row][col] != '0' && \
				mat.map.matrix[row][col] != '1' && \
				mat.map.matrix[row][col] != 'P' && \
				mat.map.matrix[row][col] != 'E' && \
				mat.map.matrix[row][col] != 'C' && \
				mat.map.matrix[row][col] != 'Y')
				failExitGame(&mat, "Invalid Maps: \
					The map must consist of ONLY Five Possible Strings\n");
			col++;
		}
		row++;
	}
	return (0);
}

int	mapCheck(t_material mat)
{
	wallCheck(mat);
	spritesCheck(mat);
	rectangleCheck(mat);
	stringCheck(mat);
	return (0);
}
