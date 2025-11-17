/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retoriya <retoriya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:03:14 by retoriya          #+#    #+#             */
/*   Updated: 2024/04/20 17:47:50 by retoriya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void	ft_toupper_content(void *content)
{
	char	*str;

	str = (char *)content;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

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
	printf("Before applying function:\n");
	current = head;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstiter(head, ft_toupper_content);
	current = head;
	printf("\nafter applying function: \n");
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}
*/