void		print_path_sp(t_lem lem, char **path, int size)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	ft_printf("\n   ");
	while (i < size)
	{
		if (i % 2 == 0)
			ft_printf("\e[33;m");
		else
			ft_printf("\e[32;m");
		ft_printf("%s", (lem.room)[i].name);
		ft_printf("\e[0;m");
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < size)
	{
		if (i % 2 == 0)
			ft_printf("\e[33;m");
		else
			ft_printf("\e[32;m");
		ft_printf("%s", lem.room[i].name);
		ft_printf("\e[0;m ");
		j = 0;
		while (j < size)
		{
			if (path[i][j] == 1)
				color = 31;
			else
				color = 37;
			ft_printf(" \e[%d;m%c\e[0;m", color, path[i][j] + '0');
			j++;
		}
		ft_printf("\n");
		i++;
	}
}//
