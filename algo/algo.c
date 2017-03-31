#include "../includes/lem_in.h"

char		**ini_path(int size)
{
	char	**new;
	int		i;
	int		j;
	
	new = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		new[i] = (char *)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
			new[i][j++] = 0;
		i++;
	}
	return (new);
}

int			*ini_room(int size)
{
	int		i;
	int		*room;

	room = (int *)malloc(sizeof(int) * size);
	room[0] = 0;
	i = 1;
	while(i < size)
		room[i++] = -1;
	return (room);
}

void		free_path(char **path, int size)
{
	int		i;
	
	i = 0;
	while (i < size)
		free(path[i++]);
	free(path);
}

void		add_new_path(t_path *slt, char **new, int size)
{
	char	***tmp;
	int		i;

	tmp = slt->path;
	slt->path = (char ***)malloc(sizeof(char **) * (slt->size + 1));
	i = 0;
	while (i < slt->size)
	{
		(slt->path)[i] = ft_lemcpy(tmp[i], size);
		free_path(tmp[i], size);
		i++;
	}
	if (!tmp)
		free(tmp);
	(slt->path)[i] = new;
	slt->size += 1;
}

int			prune_room(char **lem, int j, int size)
{
	int 	i;
	int		toto;

	toto = 0;
	if (j == size - 1)
		return (0);
	i = 0;
	while (i < size)
		lem[i++][j] = 0;
	i = 0;
	while (i < size)
		lem[j][i++] = 0;
	return (1);
}

int			prune_lem(char **lem, char **path, int size)
{
	int		i;
	int		j;
	int		toto;

	i = 0;
	toto = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (path[i][j] == 1)
				toto += prune_room(lem, j, size);
			j++;
		}
		i++;
	}
	return (toto);
}

int			fill_path(char **lem, int *room, char **path, int	i, int j, int k)
{
	lem[k][k] = 1;
	room[k] = i + 1;
	path[j][k] = 1;
	return (1);
}

int			add_next_branches(char **lem, int size, char **path, int i, int *room)
{
	int		j;
	int		k;
	int		toto;

	j = 0;
	toto = 0;
	while (j < size)
	{
		if (room[j] == i)
		{
			k = 0;
			while (k < size)
			{
				while (lem[j][k] == 0)
					k++;
				if (k < size && lem[k][k] == 0)
						toto += fill_path(lem, room, path, i, j, k);
				k++;
			}
		}
		j++;
	}
	return (toto);
}

int			is_vertex(int *vertex, int size, int i, int j)
{
	int		k;

	k = 0;
	while (k < size)
	{
		if (vertex[2 * k] == i && vertex[2 * k + 1] == j)
			return (1);
		k++;
	}
	return (0);
}

int			*ini_vertex(char **path, int size, int len)
{
	int		*vertex;
	int		i;
	int		j;
	int		k;

	vertex = (int *)malloc(sizeof(int) * len);
	j = size - 1;
	k = 0;
	while (j > 0)
	{
		i = size - 1;
		while (i >= 0 && path[i][j] != 1)
			i--;
		vertex[k++] = i;
		vertex[k++] = j;
		j = i;
	}
	return (vertex);
}

char		**prune_path(char **path, int size, int *room)
{
	int		*vertex;
	int		i;
	int		j;
	char	**new;

	vertex = ini_vertex(path, size, 2 * room[size - 1]);
	new = ini_path(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (is_vertex(vertex, room[size - 1], i, j))
				new[i][j] = 1;
			j++;
		}
		i++;
	}
	free_path(path, size);
	return (new);
}

char		**find_shortest_path(char **lem, int size)
{
	char	**path;
	int		i;
	int		*room;
	int		toto;

	path = ini_path(size);
	room = ini_room(size);
	i = 0;
	toto = 1;
//	print_lem(path, size);    //
	while (toto)
	{
		toto = 0;
		toto += add_next_branches(lem, size, path, i, room);
		i++;
//		print_lem(path, size);    //
	}
	if (room[size - 1] == -1)
		return (NULL);
	path = prune_path(path, size, room);
	free(room);
	free_path(lem, size);
	return (path);
}

void		print_lem(char **lem, int size)
{
	int		i;
	int		j;

	if (lem != NULL)
	{
	i = 0;
	ft_putchar('\n');
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar('0' + lem[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	}
}

char		**ft_lemcpy(char **lem, int size)
{
	char	**new;
	int		i;
	int		j;
	
	new = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		new[i] = (char *)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
		{
			new[i][j] = lem[i][j];
			j++;
		}
		i++;
	}
	return (new);
}

t_path		algo(char **lem, int size)
{
	t_path	slt;
	char	**new_path;
	
	slt.path = NULL;
	slt.size = 0;
	print_lem(lem, size);
	while (size > 0)
	{
		new_path = find_shortest_path(ft_lemcpy(lem, size), size);
//		print_lem(new_path, size);
		if (new_path != NULL)
		{
//			print_lem(new_path, size);
			add_new_path(&slt, new_path, size);
			prune_lem(lem, new_path, size);
//			printf("\nlem after pruning is :\n\n");  //
//			print_lem(lem, size);     //
		}
		else
			size = 0;
	}
	return (slt);
}
