/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:19:23 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/30 16:38:34 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*init;
	t_list	*new;
	void	*content;

	init = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		new = ft_lstnew(content);
		if (!new)
			return (del(content), ft_lstclear(&init, del), NULL);
		ft_lstadd_back(&init, new);
		lst = lst->next;
	}
	return (init);
}
