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
	t_list	*head;
	t_list	*prev;

	if (!del)
		return ;
	head = *lst;
	*lst = NULL;
	while (head != NULL)
	{
		del(head->content);
		prev = head;
		head = head->next;
		free(prev);
	}
}
