/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:06:31 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/20 17:47:53 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*
int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*last_node;
	t_list	*last;

	head = ft_lstnew(strdup("aaaaaaaa"));
	second = ft_lstnew(strdup("bbbbbbb"));
	last_node = ft_lstnew(strdup("cccccccc"));
	head->next = second;
	second->next = last_node;
	last_node->next = NULL;
	last = ft_lstlast(head);
	printf("%s\n", last->content);
	return (0);
}
*/