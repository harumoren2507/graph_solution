/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:50:49 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/20 17:48:53 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;
	t_list	*current;

	head = ft_lstnew(strdup("Hello!"));
	second = ft_lstnew(strdup("42Tokyo"));
	third = ft_lstnew(strdup("shinjuku campus"));
	head->next = second;
	second->next = third;
	third->next = NULL;
	printf("Before clearing the list:\n\n");
	current = head;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	printf("list count :%d\n", ft_lstsize(head));
	return (0);
}
*/