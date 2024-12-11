/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconiat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:45:41 by sconiat           #+#    #+#             */
/*   Updated: 2024/05/29 12:13:38 by sconiat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write_words(char **res, const char *s, char c, int k)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		res[k][i] = s[i];
		i ++;
	}
	res[k][i] = '\0';
}

static char	**ft_free(char **res, int id)
{
	int	i;

	i = 0;
	while (id >= i)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static char	**ft_split_word(char **res, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i ++;
		else
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j ++;
			res[k] = malloc(sizeof(char) * (j + 1));
			if (!res[k])
				return (ft_free(res, k));
			ft_write_words(res, s + i, c, k);
			i = i + j;
			k ++;
		}
	}
	res[k] = NULL;
	return (res);
}

static size_t	get_len(char const *s, char c)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	if (c == '\0' && s[0])
		return (1);
	if (s[0] == '\0')
		return (len);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	len;

	if (!s)
	{
		res = malloc(sizeof(char *));
		if (!res)
			return (NULL);
		res[0] = NULL;
		return (res);
	}
	len = get_len(s, c);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	return (ft_split_word(res, s, c));
}
