/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:31:11 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/22 22:26:32 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (!lst || !del || !*lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		del(current->content);
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*lst = NULL;
}

void	delete_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list	*current;
	t_list	*temp;

	head = ft_lstnew(strdup("Hello!"));
	second = ft_lstnew(strdup("42Tokyo"));
	third = ft_lstnew(strdup("shinjuku campus"));
	head->next = second;
	second->next = third;
	third->next = NULL;
	printf("Before clearing the list:\n");
	current = head;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&head, delete_content);
	if (head == NULL)
		printf("After clearing the list, head is now NULL.\n");
	return (0);
}
