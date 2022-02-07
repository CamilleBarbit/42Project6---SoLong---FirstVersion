
#include "so_long.h"
#include "string.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			printf("je suis different");
			return (1);
		}
		i++;
	}
	printf("je suis le même");
	return (0);
}


int	ft_check_walls(char **tab, char *file_name, int size) //je lui envoie le nombre de lignes
{
	int	x;
	int	y;

	x = 0;
	while (tab[0][x + 1]) //tant que le caractère à (x + 1) != 0 -> il n'ira pas sur le \n car après il y a un \0
	{
		if (tab[0][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (tab[size - 1][x + 1])
	{
		if (tab[size - 1][x] != '1')
			return (1);
		x++;
	}
	y = 1;
	while (y <= size - 2)
	{
		x = strlen(tab[y]); //strlen est la taille de la string en question - on ne veut pas la taille du tableau
		if(tab[y][0] != '1' || tab[y][x - 2] != '1') //je mets x - 2 car avant le \0, il y a un \n
			return (1);
		y++;
	}
	return (0);
}

int	ft_check_map_form(char **tab, char *file_name, int size) //je lui envoie le nombre de lignes
{
	int		tempo;
	int		len;
	int		y;
	int		x;

	tempo = strlen(tab[0]);
	y = 1;
	x = 0;
	while (y <= size - 1)
	{
		len = strlen(tab[y]);
		if (len != tempo)
		{
			printf("Problème de taille");
			return (1);
		}
		y++;
	}
	printf("C'est la même taille");
	return (0);
}

int	ft_check_file_name(char *file_name)
{
	int	i;
	char	*str;

	i = 0;
	str = ".ber";
	while (file_name[i])
	{
		if (file_name[i] == '.')
		{
			if (ft_strcmp(file_name + i, str) == 0)
			{
				printf("Bon nom");
				return (0);
			}
		}
		i++;
	}
	printf("Mauvais nom");
	return (1);
}

// void	ft_handle_all_errors(char **tab, char *file_name, int size)
// {
// 	if (!tab)
// 		exit (1);
// 	if (!file_name)
// 		exit (1);
// 	if (size < 3)
// 		exit (1);
// 	if (!ft_check_walls)
// 	{

// 	}

// 	}
// }

int	main()
{
	char	*file_name = "";

	ft_check_file_name(file_name);
	return (0);
}