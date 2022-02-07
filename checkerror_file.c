/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:44:11 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/07 19:44:54 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "string.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_file_name(char *file_name)
{
	int	i;
	char	*str;
    int     count;

	i = 0;
	str = ".ber";
    count = 0;
	while (file_name[i])
	{
		if (file_name[i] == '.' && count == 0)
		{
            count = 1;
			if (ft_strcmp(file_name + i, str) == 0  && file_name[i + 4] == '\0')
				    return (write(1, "c bon\n", 6), 0);
		}
		i++;
	}
	return(write(1, "Error\nProblem with file name\n", 28), 1);
}

int	main()
{
	char	*file_name = ".ber"; //gérer cette erreur

	ft_check_file_name(file_name);
	return (0);
}