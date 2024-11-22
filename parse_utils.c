#include "cub3d.h"

static bool define_card(t_map *map, char card)
{
    if (card == 'N' || card == 'S' || card == 'W' || card == 'E')
    {
        if (card == 'N')
            map->start_dir = NORTH;
        else if (card == 'S')
            map->start_dir = SOUTH;
        else if (card == 'W')
            map->start_dir = WEST;
        else if (card == 'E')
            map->start_dir = EAST;
        return (true);
    }
    return (false);
}

static bool     verify_double_nl(t_map *map)
{
    int     i;
    char    *buffer;

    i = -1;
    buffer = ft_strtrim(map->string_map + map->str_index, "\n\t ");
    if (buffer == NULL)
        return (false);
    while (buffer[++i])
    {
        if (buffer[i] == '\n'
                && buffer[i+1]
                && buffer[i+1] == '\n'
                && (ft_strchr(buffer + i + 1, '1')
                    || ft_strchr(buffer + i + 1, '0')))
                return (free(buffer), false);
    }
    free(buffer);
    return (true);
}

char    **split_join_sep(const char *s, char sep)
{
    int     i;
    char    **res;
    char    *tmp;

    res = ft_split(s, sep);
    if (res == NULL)
        return (NULL);

    i = -1;
    while (res[++i])
    {
        tmp = res[i];
        res[i] = ft_strjoin(res[i], "\n");
        free(tmp);
        if (res[i] == NULL)
            return (free_array(res, i), NULL);
    }
    return (res);
}

bool    check_map(t_map *map, char **parsed_line)
{
    int     i;
    int     j;
    char    *valide_char;
    int     index;

    i = -1;
    index = 0;
    valide_char = "10NOWSE ";
    while (parsed_line && parsed_line[++i])
    {
        j = -1;
        while (parsed_line[i] && parsed_line[i][++j])
        {
            if (!ft_strchr(valide_char, parsed_line[i][j]))
                return (false);
            index += define_card(map, parsed_line[i][j]);
        }
    }
    if (index != 1 || !verify_double_nl(map))
        return (false);
    return (true);
}

int ft_read(char **line, int fd)
{
    char *buffer;
    char c;
    int     i;

    i = 0;
    if (fd < 0)
        return (-1);
    buffer = ft_calloc(sizeof(char), 100000);
    if (!buffer)
        return (-1);
    while (read(fd, &c, 1) > 0 && c && i < 100000 - 2)
        buffer[i++] = c;
    buffer[i] = '\n';
    buffer[i + 1] = '\0';
    *line = buffer;
    return (i + 1);
}