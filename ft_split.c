/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:04:25 by haitkadi          #+#    #+#             */
/*   Updated: 2021/11/09 11:04:29 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	size_t	words_counter(const char *s, char c)
{
	size_t	words;
	size_t	i;

	words = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			words += 1;
		i++;
	}
	return (words);
}

static	int	alloc_and_fill(char **arr, const char *s, size_t start, size_t len)
{
	char	*sub;
	int		i;

	sub = ft_substr(s, start, len);
	i = 0;
	if (!sub)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
		return (1);
	}
	*arr = sub;
	return (0);
}

static	char	**spliter(const char *s, char c, char **new_arr)
{
	size_t	start;
	size_t	i;
	size_t	j;
	size_t	len;
	int		err_alloc;

	i = 0;
	j = 0;
	len = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] != c)
			len++;
		if ((s[i] == c && s[i + 1] != c) || (s[i + 1] == 0))
		{
			err_alloc = alloc_and_fill(&new_arr[j++], s, start, len);
			if (err_alloc == 1)
				return (NULL);
			len = 0;
			start = (i) + 1;
		}
		i++;
	}
	return (new_arr);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**final_result;
	char	**new_arr;

	str = ft_strtrim(s, &c);
	if (str == NULL || !s || !*s || !str[0])
	{
		final_result = ft_calloc(1, sizeof(char *));
		free(str);
		return (final_result);
	}
	new_arr = (char **)ft_calloc((words_counter(str, c) + 1), sizeof(char *));
	if (new_arr == NULL)
		return (0);
	final_result = spliter(str, c, new_arr);
	if (!final_result)
		final_result = ft_calloc(1, sizeof(char *));
	free(str);
	return (final_result);
}
