/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 21:41:34 by haitkadi          #+#    #+#             */
/*   Updated: 2021/11/12 21:41:39 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	i;

	if (!s || !f)
		return (0);
	ptr = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	return (ptr);
}
