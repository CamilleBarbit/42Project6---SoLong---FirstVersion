/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:44:11 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/16 11:44:55 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_file_name(char *file_name)
{
	int		i;
	char	*str;
    int		count;

	i = 0;
	str = ".ber";
    count = 0;
	while (file_name[i])
	{
		if (file_name[i] == '.' && count == 0)
		{
            count = 1;
			if (ft_strcmp(file_name + i, str) == 0  && file_name[i + 4] == '\0' && ft_len(file_name) > 4)
				return (0);
		}
		i++;
	}
	return(printf("Error\nProblem with file name!\n"), 1);
}
