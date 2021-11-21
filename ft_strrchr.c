/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:30:29 by haitkadi          #+#    #+#             */
/*   Updated: 2021/11/04 15:30:34 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		ch;
	char		*str;

	i = ft_strlen(s);
	ch = (char)c;
	str = (char *)s;
	while (i >= 0)
	{
		if (str[i] == ch)
			return (&str[i]);
		else if (i == 0)
			break ;
		i--;
	}
	return (0);
}
