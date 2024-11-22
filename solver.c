#include "cub3d.h"

static bool	ft_move(t_data *data, char **copy_map, int way, char c);
static bool	ft_move_backward(t_data *data, char **copy_map);
static bool	find_character(t_data *data, char **copy_map, char c);

// bool	resolve_map(t_data *data, char **copy_map)
// {
// 	data->map.row = data->map.start_row;
// 	data->map.col = data->map.start_col;
// 	while (1)
// 	{
// 		if (data->map.row <= 0 || data->map.col <= 0
// 			||!copy_map[data->map.row - 1][data->map.col]
// 			|| !copy_map[data->map.row][data->map.col + 1]
// 			|| !copy_map[data->map.row + 1]
// 			|| !copy_map[data->map.row][data->map.col - 1]
// 			|| find_character(data, copy_map, ' ')
// 			|| find_character(data, copy_map, '\n')
// 			|| find_character(data, copy_map, '	'))
// 			return (printf("1"), false);
// 		if (!ft_move(data, copy_map, 1, '0'))
// 		{
// 			if (!ft_move_backward(data, copy_map))
// 				break ;
// 		}
// 	}
// 	return (true);
// }

bool	resolve_map(t_data *data, char **copy_map)
{
	data->map.row = data->map.start_row;
	data->map.col = data->map.start_col;
	while (1)
	{
		// Check each condition separately and print debug output
		if (data->map.row <= 0)
		{
			printf("1: data->map.row <= 0\n");
			return (false);
		}
		if (data->map.col <= 0)
		{
			printf("2: data->map.col <= 0\n");
			return (false);
		}
		if (!copy_map[data->map.row - 1][data->map.col])
		{
			printf("3: !copy_map[data->map.row - 1][data->map.col]\n");
			return (false);
		}
		if (!copy_map[data->map.row][data->map.col + 1])
		{
			printf("4: !copy_map[data->map.row][data->map.col + 1]\n");
			return (false);
		}
		if (!copy_map[data->map.row + 1])
		{
			printf("5: !copy_map[data->map.row + 1]\n");
			return (false);
		}
		if (!copy_map[data->map.row][data->map.col - 1])
		{
			printf("6: !copy_map[data->map.row][data->map.col - 1]\n");
			return (false);
		}
		// if (find_character(data, copy_map, ' '))
		// {
		// 	printf("7: find_character(data, copy_map, ' ') found\n");
		// 	return (false);
		// }
		// if (find_character(data, copy_map, '\n'))
		// {
		// 	printf("8: find_character(data, copy_map, '\\n') found\n");
		// 	return (false);
		// }
		// if (find_character(data, copy_map, '	'))
		// {
		// 	printf("9: find_character(data, copy_map, '\\t') found\n");
		// 	return (false);
		// }

		// If none of the conditions are met, continue to try moving
		if (!ft_move(data, copy_map, 1, '0'))
		{
			if (!ft_move_backward(data, copy_map))
				break ;
		}
	}
	return (true);
}

static bool	ft_move(t_data *data, char **copy_map, int way, char c)
{
	if (way > 0)
		copy_map[data->map.row][data->map.col] = data->map.index;
	if (way < 0)
		copy_map[data->map.row][data->map.col] = '1';
	if (copy_map[data->map.row][data->map.col + 1] == c)
		data->map.col = data->map.col + 1;
	else if (copy_map[data->map.row + 1]
		&& copy_map[data->map.row + 1][data->map.col] == c)
		data->map.row = data->map.row + 1;
	else if (copy_map[data->map.row - 1]
		&& copy_map[data->map.row - 1][data->map.col] == c)
		data->map.row = data->map.row - 1;
	else if (copy_map[data->map.row][data->map.col - 1] == c)
		data->map.col = data->map.col - 1;
	else
		return (false);
	data->map.index += way;
	if (data->map.index == 'z')
		data->map.index = 'a';
	if (data->map.index == 'a' - 1)
		data->map.index = 'z';
	return (true);
}

static bool	ft_move_backward(t_data *data, char **copy_map)
{
	if (!ft_move(data, copy_map, 1, '0')
		&& data->map.col == data->map.start_col
		&& data->map.row == data->map.start_row)
		return (false);
	if (ft_move(data, copy_map, -1, data->map.index - 1) == 0)
	{
		if (data->map.index == 'a')
			data->map.index = 'z';
		else
			data->map.index -= 1;
		return (true);
	}
	else if ((data->map.index == 'a' && find_character(data, copy_map, 'z')))
	{
		ft_move(data, copy_map, -1, 'z');
		data->map.index = 'z';
	}
	return (true);
}

static bool	find_character(t_data *data, char **copy_map, char c)
{
	if (copy_map[data->map.row][data->map.col + 1]
		&& copy_map[data->map.row][data->map.col + 1] == c)
		return (true);
	else if (copy_map[data->map.row + 1]
		&& copy_map[data->map.row + 1][data->map.col] == c)
		return (true);
	else if (copy_map[data->map.row - 1]
		&& copy_map[data->map.row - 1][data->map.col] == c)
		return (true);
	else if (copy_map[data->map.row][data->map.col - 1]
		&& copy_map[data->map.row][data->map.col - 1] == c)
		return (true);
	else
		return (false);
}