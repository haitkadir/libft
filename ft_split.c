/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:04:25 by haitkadi          #+#    #+#             */
/*   Updated: 2022/03/30 20:14:47 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	void	ft_split_util(t_list **head, char const *s, char c)
{
	int		i;
	int		start;
	int		len;
	char	flag;

	i = -1;
	flag = 0;
	while (s[++i])
	{
		if (flag == 0 && s[i] != c)
		{
			start = i;
			flag = 1;
		}
		if ((flag == 1) && (s[i + 1] == c || s[i + 1] == 0))
		{
			flag = 0;
			len = i - start;
			if (s[i + 1] == 0)
				len++;
			ft_lstadd_back(&*head, ft_lstnew(ft_substr(s, start, len)));
		}
	}
}

static	char	**ft_convert_array(t_list **head)
{
	char	**str;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = NULL;
	str = NULL;
	str = (char **)ft_calloc(ft_lstsize(*head) + 1, sizeof(char *));
	if (!str)
		exit(-1);
	while (*head != NULL)
	{
		str[i++] = (**head).content;
		tmp = *head;
		*head = (**head).next;
		if (tmp)
			free(tmp);
		tmp = NULL;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	t_list	*head;

	if (!s || !c)
		return (NULL);
	head = NULL;
	ft_split_util(&head, s, c);
	return (ft_convert_array(&head));
}
