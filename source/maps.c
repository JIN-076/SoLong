/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:30:41 by jhong             #+#    #+#             */
/*   Updated: 2022/03/21 01:57:56 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	getMapSize(t_material *mat, char **argv)
{
	int		fd;
	char	*line;

	mat->map.size.x = 0;
	mat->map.size.y = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printErr("Open Failure: Opening Map is Fail. Please Retry again!\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (mat->map.size.x == 0)
			mat->map.size.x = (int)ft_strlen(line) - 1;
		mat->map.size.y++;
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}

int	getMap(t_material *mat, char **argv)
{
	int		row;
	int		fd;
	char	*line;

	row = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printErr("Open Failure: Opening Map is Fail. Please Retry again!\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		mat->map.matrix[row] = ft_strtrim(line, "\n");
		row++;
		free(line);
	}
	free(line);
	close(fd);
	mapCheck(*mat);
	return (0);
}

int	loadingMap(t_material mat, int row, int col)
{
	if (mat.map.matrix[row][col] == '1')
		mat.img.imgPtr = mlx_xpm_file_to_image(mat.mlxPtr, "./img/tree.xpm",
				&mat.img.size.x, &mat.img.size.y);
	else if (mat.map.matrix[row][col] == '0')
		mat.img.imgPtr = mlx_xpm_file_to_image(mat.mlxPtr, "./img/floor.xpm",
				&mat.img.size.x, &mat.img.size.y);
	else if (mat.map.matrix[row][col] == 'E')
		mat.img.imgPtr = mlx_xpm_file_to_image(mat.mlxPtr, "./img/exit.xpm",
				&mat.img.size.x, &mat.img.size.y);
	else if (mat.map.matrix[row][col] == 'C')
		mat.img.imgPtr = mlx_xpm_file_to_image(mat.mlxPtr, "./img/collec.xpm",
				&mat.img.size.x, &mat.img.size.y);
	else if (mat.map.matrix[row][col] == 'P')
		mat.img.imgPtr = mlx_xpm_file_to_image(mat.mlxPtr, mat.img.spritesPath,
				&mat.img.size.x, &mat.img.size.y);
	else if (mat.map.matrix[row][col] == 'Y' && mat.hasEnemy > 0)
		animationEnemy(&mat);
	mlx_put_image_to_window(mat.mlxPtr, mat.winPtr, mat.img.imgPtr, \
											SPRITE_W * col, SPRITE_H * row);
	mlx_destroy_image(mat.mlxPtr, mat.img.imgPtr);
	return (0);
}
