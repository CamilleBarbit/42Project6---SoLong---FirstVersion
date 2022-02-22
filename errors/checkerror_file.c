/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:44:11 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/22 15:00:10 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Function to check file (2nd argument)
*/

int	ft_check_file_name(char *file_name)
{
	int		i;
	char	*str;
    int		count;

	i = 1;
	str = ".ber";
    count = 0;
	if (ft_len(file_name) < 4)
		return (printf("Error\nProblem with file name!\n"), 1);
	while (file_name[i])
	{
		if (file_name[i] == '.' && count == 0 && file_name[0])
		{
            count = 1;
			if (ft_strcmp(file_name + i, str) == 0  && file_name[i + 4] == '\0' && file_name[i - 1] != '/')
				return (0);
		}
		i++;
	}
	return(printf("Error\nProblem with file name!\n"), 1);
}

int	ft_try_to_open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nCould not open file!"), 1);
	return (0);
}

int ft_check_all_errors_file_name(char *file_name)
{
	if (ft_check_file_name(file_name) == 1)
		return (1);
	if (ft_try_to_open_file(file_name) == 1)
		return (1);
	return (0);
}