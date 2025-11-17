/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:32:35 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/20 17:48:02 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list	*current;
	t_list	*temp;

	head = ft_lstnew("hello!");
	second = ft_lstnew("42Tokyo");
	third = ft_lstnew("shinjuku campus");
	head->next = second;
	second->next = third;
	third->next = NULL;
	current = head;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
	while (head != NULL)
	{
		free(head);
		temp = head->next;
		head = temp;
	}
	return (0);
}
*/