/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:45:40 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/02/05 12:29:11 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstindex(t_list *lst, int index)
{
	int	i;

	i = 0;
	while (lst && i != index)
	{
		lst = lst->next;
		i++;
	}
	if (i == index && lst)
		return (lst->content);
	else
		return (NULL);
}
