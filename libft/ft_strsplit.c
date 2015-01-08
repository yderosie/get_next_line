/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 10:21:29 by yderosie          #+#    #+#             */
/*   Updated: 2014/11/19 09:55:11 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sizek(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char		**ft_strsplit_2(char const *s, char c)
{
	char	*s1;
	char	**s2;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	s1 = (char *)s;
	if (s[0] == c)
		return (ft_strsplit(s + 1, c));
	s2 = (char **)malloc(sizeof(char *) * (ft_strlen(s) + 1));
	while (s1[i] != '\0')
	{
		s2[k] = (char *)malloc(sizeof(char) * (1 + ft_sizek(s + i, c)));
		while (s1[i] != c && s1[i] != '\0')
			s2[k][j++] = s1[i++];
		while (s1[i] == c && s1[i + 1] == c)
			i++;
		if (s1[i++] == c && s1[i + 1] != c)
			k++;
		j = 0;
	}
	return (s2);
}

char			**ft_strsplit(char const *s, char c)
{
	char **s2;

	if (s == NULL)
		return (NULL);
	s2 = ft_strsplit_2(s, c);
	return (s2);
}
