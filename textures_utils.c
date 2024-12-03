/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafoulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:07:02 by mafoulon          #+#    #+#             */
/*   Updated: 2024/12/03 16:07:04 by mafoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strchr_array(char **sep, char *str)
{
	int	i;

	i = 0;
	if (!sep || !str)
		return (-1);
	while (sep[i])
	{
		if (ft_strschr(sep[i], str) != -1)
			return (ft_strschr(sep[i], str));
		i++;
	}
	return (-1);
}

int	ft_strschr(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s2[i])
	{
		j = 0;
		if (s2[i] == s1[j])
		{
			while (s2[i] && s1[j] && s1[j] && s2[i] == s1[j])
			{
				i++;
				j++;
			}
			if (j == (int)ft_strlen(s1))
				return (i - j);
		}
		i++;
	}
	return (-1);
}
