#include "libft.h"

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