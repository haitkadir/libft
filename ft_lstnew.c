/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:33:05 by haitkadi          #+#    #+#             */
/*   Updated: 2022/03/30 20:11:39 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*temp;

	if (!content)
		exit(-1);
	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		exit(-1);
	temp->content = content;
	temp->next = NULL;
	return (temp);
}
