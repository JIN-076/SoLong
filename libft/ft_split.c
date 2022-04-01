/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhong <jhong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 14:47:58 by jhong             #+#    #+#             */
/*   Updated: 2022/02/23 00:41:39 by jhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

unsigned int	ft_get_cnt(char const *s, char c)
{
	unsigned int	i;
	unsigned int	cnt;

	if (!s[0])
		return (0);
	i = 0;
	cnt = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			cnt++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		cnt++;
	return (cnt);
}

void	ft_get_next(char **next, unsigned int *next_len, char c)
{
	unsigned int	i;

	*next += *next_len;
	*next_len = 0;
	i = 0;
	while (**next && **next == c)
		(*next)++;
	while ((*next)[i])
	{
		if ((*next)[i] == c)
			return ;
		(*next_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	cnt;
	char			**tab;
	char			*next;

	i = -1;
	if (!s)
		return (NULL);
	cnt = ft_get_cnt(s, c);
	tab = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!tab)
		return (NULL);
	next = (char *)s;
	len = 0;
	while (++i < cnt)
	{
		ft_get_next(&next, &len, c);
		tab[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!tab[i])
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i], next, len + 1);
	}
	tab[i] = NULL;
	return (tab);
}
