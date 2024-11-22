/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:43:25 by codespace         #+#    #+#             */
/*   Updated: 2024/06/06 13:11:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

// void	*garbage_collector(void *ptr, bool clean)
// {
// 	static t_list	*garbage_list;

// 	if (clean)
// 	{
// 		ft_lstclear(&garbage_list, delete);
// 		return (NULL);
// 	}
// 	else
// 	{
// 		ft_lstadd_back(&garbage_list, ft_lstnew(ptr));
// 		return (ptr);
// 	}
// }

// static void	delete(void *ptr)
// {
// 	free(ptr);
// 	ptr = NULL;
// }
