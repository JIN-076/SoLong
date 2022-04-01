/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 02:09:41 by jhong             #+#    #+#             */
/*   Updated: 2022/03/21 04:11:14 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	argumentCheck(int argc, char **argv)
{
	if (argc < 2)
		printErr("Invalid Arguments: Too little arguments!\n");
	if (argc > 2)
		printErr("Invalid Arguments: Too many arguments!\n");
	if (ft_strstr(argv[1], ".ber") == NULL)
		printErr("Invalid Arguments: Your program must receive the .ber extension \
				file as the first factor!\n");
	return (0);
}

int	exposeMat(t_material *mat)
{
	printMap(*mat);
	printSteps(mat);
	return (0);
}

int	main(int argc, char **argv)
{
	t_material	mat;

	argumentCheck(argc, argv);
	getMapSize(&mat, argv);
	init(&mat);
	getMap(&mat, argv);
	mat.mlxPtr = mlx_init();
	mat.winPtr = mlx_new_window(mat.mlxPtr, \
								mat.map.size.x * SPRITE_W, \
								mat.map.size.y * SPRITE_H, "SoLong");
	getInitPlayerPos(&mat);
	getInitEnemyCnt(&mat);
	getInitCollectionCnt(&mat);
	printMap(mat);
	mlx_hook(mat.winPtr, KEY_PRESS_EVENT, 0, pressKey, &mat);
	mlx_hook(mat.winPtr, KEY_DESTROY_NOTIFY, 0, exitMlx, &mat);
	mlx_expose_hook(mat.winPtr, exposeMat, &mat);
	if (mat.hasEnemy > 0)
		mlx_loop_hook(mat.mlxPtr, patrol, &mat);
	mlx_loop(mat.mlxPtr);
}
