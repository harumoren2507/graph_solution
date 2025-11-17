/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:53:22 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/20 17:47:47 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
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
	int		delete_count;
	t_list	*next;

	head = ft_lstnew(strdup("Hello!"));
	second = ft_lstnew(strdup("42Tokyo"));
	third = ft_lstnew(strdup("shinjuku campus"));
	head->next = second;
	second->next = third;
	third->next = NULL;
	printf("Before deleting the list\n\n");
	current = head;
	while (current != NULL)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
	delete_count = 0;
	current = head;
	while (current != NULL)
	{
		next = current->next;
		ft_lstdelone(current, delete_content);
		delete_count++;
		current = next;
	}
	printf("Total nodes deleted: %d\n", delete_count);
	return (0);
}
*/