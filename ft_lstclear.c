/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:48:58 by haitkadi          #+#    #+#             */
/*   Updated: 2021/11/15 16:49:02 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*current;

	if (!del)
		return ;
	next = *lst;
	*lst = NULL;
	while (next != NULL)
	{
		del(next->content);
		current = next;
		next = next->next;
		free(current);
	}
}
