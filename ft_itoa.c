/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:18:36 by haitkadi          #+#    #+#             */
/*   Updated: 2021/11/12 15:18:42 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	char	*aloc_nd_fill(int counter, int num, int sign)
{
	char	*ptr_str;
	int		mod;

	ptr_str = (char *)ft_calloc(counter + 1, sizeof(char));
	if (!ptr_str)
		return (0);
	if (num == 0)
		ptr_str[0] = '0';
	while (num)
	{
		mod = num % 10;
		num = num / 10;
		ptr_str[--counter] = mod + '0';
	}
	if (sign < 0)
		ptr_str[0] = '-';
	return (ptr_str);
}

static	char	*part_tow(int n)
{
	size_t	counter;
	int		num;
	int		sign;
	char	*ptr_str;

	counter = 0;
	sign = 1;
	if (n == 0)
		counter++;
	else if (n < 0)
	{
		n *= -1;
		sign *= -1;
		counter++;
	}
	num = n;
	while (n)
	{
		n /= 10;
		counter++;
	}
	ptr_str = aloc_nd_fill(counter, num, sign);
	return (ptr_str);
}

char	*ft_itoa(int n)
{
	char	*final_result;

	if (n == -2147483648)
	{
		final_result = ft_strdup("-2147483648");
		if (!final_result)
			return (0);
		return (final_result);
	}
	final_result = part_tow(n);
	return (final_result);
}
