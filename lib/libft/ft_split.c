/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:40:24 by junhyeop          #+#    #+#             */
/*   Updated: 2023/11/03 17:46:30 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**freeall(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

int	strcnt(char const *s, char c)
{
	int	n;

	n = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			n++;
		while (*s && *s != c)
			s++;
	}
	return (n);
}

char	*split_str(char const *s, char c)
{
	int		n;
	int		i;
	char	*str;

	n = 0;
	i = 0;
	while (s[n] && s[n] != c)
		n++;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		cnt;
	int		i;

	if (!s)
		return (NULL);
	cnt = strcnt(s, c);
	strs = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < cnt)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			strs[i] = split_str(s, c);
		if (strs[i++] == 0)
			return (freeall(strs));
		while (*s && *s != c)
			s++;
	}
	strs[i] = 0;
	return (strs);
}
