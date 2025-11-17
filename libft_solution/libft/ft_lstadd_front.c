/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:33:09 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/20 17:47:41 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list	*new_node;
	t_list	*current;

	head = ft_lstnew(strdup("Hello!"));
	second = ft_lstnew(strdup("42Tokyo"));
	third = ft_lstnew(strdup("shinjuku campus"));
	head->next = second;
	second->next = third;
	third->next = NULL;
	new_node = ft_lstnew(strdup("Forever Roppongi campus"));
	new_node->next = NULL;
	printf("List before adding new node:\n");
	current = head;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstadd_front(&head, new_node);
	printf("List after adding new node:\n");
	current = head;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
}
*/