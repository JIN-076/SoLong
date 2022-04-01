/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:39:29 by jhong             #+#    #+#             */
/*   Updated: 2022/03/21 03:31:57 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# include "mlx/mlx.h"
# include "libft/libft.h"

# define SPRITE_H				64
# define SPRITE_W				64

# define KEY_PRESS_EVENT		2
# define KEY_DESTROY_NOTIFY		17

# define LEFT_KEY				123
# define RIGHT_KEY				124
# define UP_KEY					126
# define DOWN_KEY				125
# define A_TYPE					0
# define S_TYPE					1
# define D_TYPE					2
# define W_TYPE					13
# define ESC 					53

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	char		**matrix;
	t_vector	size;
}	t_map;

typedef struct s_game
{
	int	cntCollection;
	int	cntSteps;
	int	cntEnemy;
}	t_game;

typedef struct s_img
{
	void		*imgPtr;
	t_vector	size;
	t_vector	position;
	char		*spritesPath;
}	t_img;

typedef struct s_material
{
	void	*mlxPtr;
	void	*winPtr;
	t_game	game;
	t_map	map;
	t_img	img;
	t_img	enemy;
	int		hasEnemy;
}	t_material;

int		argumentCheck(int argc, char **argv);
int		exposeMat(t_material *mat);

int		getMapSize(t_material *mat, char **argv);
int		getMap(t_material *mat, char **argv);
int		loadingMap(t_material mat, int row, int col);

int		pressKey(int type, t_material *mat);
int		exitMlx(t_material *mat);
int 	failExitGame(t_material *mat, char *msg);

int		moveLeft(t_material *mat);
int		moveRight(t_material *mat);
int		moveUp(t_material *mat);
int		moveDown(t_material *mat);
int		movement(t_material *mat, int type);

int		escapeCondition(t_material *mat);
int		movementToEnemy(t_material *mat, int type);
int		animationEnemy(t_material *mat);
int		freeMap(t_material *mat);
int 	failFreeMap(t_material *mat);

int		init(t_material *mat);
int		getInitCollectionCnt(t_material *mat);
int		getInitPlayerPos(t_material *mat);
int		getInitEnemyPos(t_material *mat);
int		getInitEnemyCnt(t_material *mat);

int		moveLeftEnemy(t_material *mat);
int		moveRightEnemy(t_material *mat);
int		moveUpEnemy(t_material *mat);
int		moveDownEnemy(t_material *mat);
int		patrol(t_material *mat);

int		wallCheck(t_material mat);
int		spritesCheck(t_material mat);
int		rectangleCheck(t_material mat);
int		stringCheck(t_material mat);
int		mapCheck(t_material mat);

int		printMap(t_material mat);
int		printSteps(t_material *mat);
int		printErr(char *msg);
void	printMsg(char *msg, int nbr, int mode);
int		exitGame(t_material *mat, char *msg);

#endif
