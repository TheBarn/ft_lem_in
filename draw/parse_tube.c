#include "../includes/lem_in.h"

char	**ini_map(t_lem *lem)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc(sizeof(char *) * lem->size);
	i = 0;
	while (i < lem->size)
		map[i++] = (char *)malloc(sizeof(char) * lem->size);
	i = 0;
	while (i < lem->size)
	{
		j = 0;
		while (j < lem->size)
			map[i][j++] = 0;
		i++;
	}
	return (map);
}

int		room_rank(t_lem *lem, char *str)
{
	int		i;
	
	i = 0;
	while (i < lem->size)
	{
		if (ft_strcmp(str, (lem->room)[i].name) == 0)
			break;
		i++;
	}
	if (i == lem->size)
		exit_lem_in("no room found for tube indication");
	return (i);
}

t_tube	read_tube(t_lem *lem, char *str)
{
	t_tube	tube;
	char	**split;

	if (count_words(str, ' ') != 1)
		exit_lem_in("space found in indication for a tube");
	if (count_words(str, '\t') != 1)
		exit_lem_in("tab found in indication for a tube");
	if (count_words(str, '-') != 2)
		exit_lem_in("two - in tube line");
	split = ft_strsplit(str, '-');
	tube.start = room_rank(lem, split[0]);
	tube.end = room_rank(lem, split[1]);
	free_split(split, 2);
	if (tube.start == tube.end)
		exit_lem_in("start and end of the tube are the same");
	return (tube);
}

//TODO check if there is a way from start to end
void	check_map(t_lem *lem, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < lem->size)
	{
		j = 0;
		while (j < lem->size)
		{
			if (map[i][j] > 1)
				map[i][j] = 1;
			j++;
		}
		i++;
	}
}

char	**parse_tubes(int fd, t_lem *lem, char **line)
{
	t_tube	tube;
	char	**map;

	map = ini_map(lem);
	if ((*line)[0] != '#')
	{
		tube = read_tube(lem, *line);
		map[ft_min(tube.start, tube.end)][ft_max(tube.start, tube.end)] += 1;
	}
	while (get_next_line(fd, line) == 1 && (*line)[0] != '\0')
	{
		if ((*line)[0] != '#')
		{
			tube = read_tube(lem, *line);
			map[tube.start][tube.end] += 1;
			map[tube.end][tube.start] += 1;
		}
	}
	check_map(lem, map);
	return (map);
} 
