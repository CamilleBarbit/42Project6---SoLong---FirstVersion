#include "so_long.h"

int	ft_recup_map_size(char *file_name)
{
	char	*line;
	int		total_nb_line;
	int		fd;

	if (!file_name)
		exit (1);
	total_nb_line = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit (1);
	line = get_next_line(fd);
	while (line)
	{
		total_nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
	return (total_nb_line);
}

char	**ft_print_map(char *file_name)
{
	char	**str_map;
	int		fd;
	int		i;
	int		nb_line;

	if (!file_name)
		exit (1);
	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit (1);
	nb_line = ft_recup_map_size(file_name);
	str_map = malloc(sizeof(char *) * (nb_line + 1));
	if (!str_map)
		exit (1);
	while (nb_line > 0)
	{
		str_map[i] = get_next_line(fd);
		printf("%s", str_map[i]);
		i++;
		nb_line--;
	}
	str_map[i] = 0;
	close(fd);
	return (str_map);
}

int	ft_check_walls(char **tab, char *file_name,int size) //je lui envoie le nombre de lignes
{
	int	x;
	int	y;

	if (!tab)
		exit (1);
	x = 0;
	while (tab[0][x + 1]) //tant que le caractère à (x + 1) != 0 -> il n'ira pas sur le \n car après il y a un \0
	{
		if (tab[0][x] != '1')
		{
			printf("%c", tab[0][x]);
			printf("ici/error\n");
			exit(1);
		}
		x++;
	}
	x = 0;
	while (tab[size - 1][x + 1])
	{
		if (tab[size - 1][x] != '1')
		{
			printf("encore/error\n");
			exit(1);
		}	
		x++;
	}
	x = strlen(tab[y]); //strlen est la taille de la string en question - on ne veut pas la taille du tableau
	y = 1;
	while (y < size - 2)
	{
		if(tab[y][0] != '1' || tab[y][x - 1] != '1') //je mets x - 2 car avant le \0, il y a un \n
		{
			printf("là/error\n");
			exit(1);
		}
		else
			break;
		y++;
		x = strlen(tab[y]);
	}	
	printf("all is fine");
}

int	main()
{
	char	**tab;
	char	*file_name = "map/map.ber";
	int		size;
	//int		nb_line;

	size = ft_recup_map_size(file_name);
	tab = ft_print_map(file_name);
	//nb_line = ft_recup_map_size(file_name);
	ft_check_walls(tab, file_name, size);
	return (0);
}