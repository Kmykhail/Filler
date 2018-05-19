/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:19:08 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/01 17:19:10 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		len_count(char *qw, char c)
{
	int		res;
	int		g;

	res = 0;
	g = 0;
	while (g < ft_strlen_my(qw))
	{
		if (qw[g] != c && (qw[g + 1] == c || qw[g + 1] == '\0'))
			res++;
		g++;
	}
	if (res == 0)
		return (0);
	return (res);
}

static	char	**main_path(char *s, char **buff, struct s_list	s1, char c)
{
	s1.index = 0;
	while (s1.l < ft_strlen_my(s) - 1)
	{
		s1.check = 0;
		while (s[s1.l] == c)
			s1.l++;
		s1.pov = s1.l;
		while (s[s1.l] != c && s[s1.l] != '\0')
		{
			s1.l++;
			s1.check++;
		}
		buff[s1.index] = (char*)malloc(sizeof(char) * (s1.check));
		s1.i = 0;
		while (s1.i < s1.check)
		{
			buff[s1.index][s1.i] = s[s1.pov];
			s1.i++;
			s1.pov++;
		}
		buff[s1.index][s1.i] = '\0';
		s1.index++;
	}
	buff[s1.index] = NULL;
	return (buff);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**buff;
	struct s_list	s1;

	s1.l = 0;
	s = ft_strtrim_my(s, c);
	if (!s)
		return (NULL);
	buff = (char**)malloc(sizeof(char*) * (len_count((char*)s, c)) + 1);
	if (!buff)
		return (NULL);
	if (main_path((char*)s, buff, s1, c) == NULL)
		return (NULL);
	return (buff);
}
