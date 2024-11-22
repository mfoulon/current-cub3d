#include "cub3d.h"

bool    resize_map(t_map *map, bool with_err)
{
    int         i;
    int         j;
    char    **new_map;

    i = -1;
    new_map = ft_calloc(sizeof(char *), (map->height + 1));
    if (new_map == NULL)
        return (false);
    while (++i < map->height)
    {
        new_map[i] = ft_calloc(sizeof(char), (map->width + map->offset + 1));
        if (new_map[i] == NULL)
            return (free_array(new_map, i), false);
        ft_bzero(new_map[i], map->width + map->offset, '0');
        j = -1;
        while (++j < map->width + map->offset)
        {
            if (map->map[i] && (int)ft_strlen(map->map[i]) > j
                && (ft_strchr("10NOWSE", map->map[i][j]) || with_err))
                new_map[i][j] = map->map[i][j];
        }
    }
    free_array(map->map, map->height);
    map->map = new_map;
    return (true);
}

bool    define_offset_and_width(t_map *map, char **parsed_line)
{
    int i;

    i = -1;
    map->width = 0;
    map->height = 0;
    while (map->map[++i])
    {
        map->height++;
        parsed_line[i] = ft_strtrim(map->map[i], "\t \n");
        if (parsed_line == NULL)
            return (false);
        if (map->width < (int)ft_strlen(parsed_line[i]))
        {
            map->width = ft_strlen(parsed_line[i]);
            map->offset = (ft_strlen(map->map[i]) - 1)
                    - ft_strlen(parsed_line[i]);
        }
    }
    return (true);
}

bool    init_map(t_map *map)
{
    int     i;
    char    **parsed_line;

    i = -1;
    map->map = split_join_sep(map->string_map
                + map->str_index, '\n');
    if (map->map == NULL)
        return (false);
    i = 0;
    while (map->map[i])
        i++;
    parsed_line = ft_calloc(sizeof(char *), (i + 1));
    if (parsed_line == NULL)
        return (false);
    if (!define_offset_and_width(map, parsed_line))
        return (free_array(parsed_line, -1), false);
    if (!check_map(map, parsed_line))
        return (free_array(parsed_line, -1), false);
    if (!resize_map(map, true))
        return (free_array(parsed_line, -1), false);
    return (free_array(parsed_line, -1), true);
}