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

int	main()
{
	char	*file_name = "";

	ft_check_file_name(file_name);
	return (0);
}