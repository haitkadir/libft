/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:11:17 by haitkadi          #+#    #+#             */
/*   Updated: 2021/11/05 21:11:32 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	void	delete_char(char *str, size_t i)
{
	size_t	len;

	len = ft_strlen(str);
	while (i < len - 1)
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = '\0';
}

static	void	trimer(char *s1, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s1[0] == set[i])
		{
			delete_char(s1, 0);
			i = 0;
			continue ;
		}
		if (s1[ft_strlen(s1) - 1] == set[i])
		{
			s1[ft_strlen(s1) - 1] = 0;
			i = 0;
			continue ;
		}
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr_s1;
	char	*ptr_set;
	char	*new_arr;

	if (!s1 || !set)
		return (0);
	ptr_s1 = ft_strdup(s1);
	if (!ptr_s1)
		return (0);
	ptr_set = (char *)set;
	trimer(ptr_s1, ptr_set);
	new_arr = ft_strdup(ptr_s1);
	if (!new_arr)
		return (0);
	free(ptr_s1);
	return (new_arr);
}
