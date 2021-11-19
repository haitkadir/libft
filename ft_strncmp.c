/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:26:13 by haitkadi          #+#    #+#             */
/*   Updated: 2021/11/04 16:26:19 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_m;
	unsigned char	*s2_m;

	s1_m = (unsigned char *)s1;
	s2_m = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_m[i] != s2_m[i])
			return (s1_m[i] - s2_m[i]);
		else if (!s1_m[i] || !s2_m[i])
			break ;
		i++;
	}
	return (0);
}
