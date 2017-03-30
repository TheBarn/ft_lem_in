#include "../includes/lem_in.h"

int		test_intmax(char *str)
{
	int		diff;

	diff = ft_strcmp(str, "2147483647");
	if (diff > 0)
		return (0);
	return (1);
}

void	is_positive_integer(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (len > 10)
		exit_lem_in("the number of ants cannot be contained in an integer type");
	while (i < len)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			exit_lem_in("the number of ants must be positive and without any other characters than numbers");
		i++;
	}
	if (len == 10)
		if(!test_intmax(str))
			exit_lem_in("the number of ants cannot be contained in an integer type");
}

int		parse_nb(int fd, char **line)
{
	int		nb;

	nb = -1;
	while (nb == -1 && get_next_line(fd, line) > 0)
	{
		if ((*line)[0] == '#' && read_command(*line) != 0)
			exit_lem_in("the number of ants is not at the beggining of the file");
		else
		{
			is_positive_integer(*line);
			nb = ft_atoi(*line);
		}
	}
	if (nb == -1)
		exit_lem_in("the number of ants has not been found");
	return (nb);
}
