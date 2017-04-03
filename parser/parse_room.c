#include "../includes/lem_in.h"

int		count_words(char *s, char c)
{
	int		i;
	int		toto;
	int		count;
	char	c2;

	i = 0;
	count = 0;
	toto = 0;
	c2 = c;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			toto++;
			i++;
		}
		if (toto != 0)
			count++;
		toto = 0;
	}
	return (count);
}

int		is_integer(char	*str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	if (len > 10)
		return (0);
	i = 0;
	while(i < len)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	if (len == 10 && !test_intmax(str))
		return (0);
	return (1);
}

void	free_split(char **tab, int size)
{
	int		i;

	i = 0;
	while (i <= size)
		free(tab[i++]);
	free(tab);	
}

int		is_room(char *str)
{
	char	**tab;

	if (count_words(str, ' ') != 3)
		return (0);
	tab = ft_strsplit(str, ' ');
	if (!is_integer(tab[1]))
	{
		free_split(tab, 3);
		return (0);
	}
	if (!is_integer(tab[2]))
	{
		free_split(tab, 3);
		return (0);
	}
	free_split(tab, 3);
	return (1);
}

t_room	*add_room(t_room *room, t_lem *lem, t_room new)
{
	t_room	*updated;
	int		i;

	lem->size += 1;
	updated = (t_room *)malloc(sizeof(t_room) * lem->size);
	i = 0;
	while (i < lem->size - 1)
	{
		updated[i] = room[i];
		i++;
	}
	updated[i] = new;
	free(room);
	return (updated);
}

void	check_sp(t_room *room, t_lem *lem)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	while (i < lem->size)
	{
		if (room[i].sp == 1)
			start++;
		else if (room[i].sp == 2)
			end++;
		i++;
	}
	if (start != 1 || end != 1)
		exit_lem_in("no indications for either START or END or both of them");
}

void	organize_room(t_room *room, int size)
{
	int		start;
	t_room	tmp;
	int		end;

	start = 0;
	while (start < size && room[start].sp != 1)
		start++;
	tmp = room[0];
	room[0] = room[start];
	room[start] = tmp;
	end = 0;
	while (end < size && room[end].sp != 2)
		end++;
	tmp = room[size - 1];
	room[size - 1] = room[end];
	room[end] = tmp;
}

t_room	*parse_room(int fd, t_lem *lem, char **line)
{
	t_room	*room;
	t_room	new;
	char	**split;
	int		tmp;

	room = NULL;
	tmp = 0;
	while (get_next_line(fd, line) == 1 && (is_room(*line) || (*line)[0] == '#'))
	{
		printf("%s\n", *line);
		if ((*line)[0] != '#')
		{
		split = ft_strsplit(*line, ' ');
		new.name = ft_strdup(split[0]);
		new.x = ft_atoi(split[1]);
		new.y = ft_atoi(split[2]);
		new.sp = tmp;
		tmp = 0;
		free_split(split, 3);
		room = add_room(room, lem, new);
		}
		else
			tmp = read_command(*line);
	}
	check_sp(room, lem);
	organize_room(room, lem->size);
	return (room);
}
