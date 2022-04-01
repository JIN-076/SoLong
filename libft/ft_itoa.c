/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 14:47:47 by jhong             #+#    #+#             */
/*   Updated: 2022/02/23 00:49:19 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len(int n)
{
	int			len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	get_sign(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	int			len;
	int			sign;
	char		*ret;
	long long	tmp;

	sign = get_sign(n);
	len = get_len(n);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	ret[len] = 0;
	len--;
	if (n < 0)
		tmp = -(long long)n;
	else
		tmp = (long long)n;
	while (len >= 0)
	{
		ret[len] = '0' + tmp % 10;
		tmp /= 10;
		len--;
	}
	if (sign == -1)
		ret[0] = '-';
	return (ret);
}
