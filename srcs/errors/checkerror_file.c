/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:44:11 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/24 17:32:47 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Function to check file (2nd argument)
*/

int	ft_check_file_name(char *file_name, int j, char *str, int count)
{
	if (--j < 4)
		return (printf("Error\nFile name is not long enough!\n"), 1);
	while (j >= 0 && file_name[j] != '/')
	{
		if (file_name[j] == '.')
			count++;
		j--;
	}
	if (count > 1)
		return (printf("Error\nFile name has too many points!\n"), 1);
	j++;
	if (file_name[j] == '.')
		return (printf("Error\nFile is not long enough!\n"), 1);
	while (file_name[j])
	{
		if (file_name[j] == '.')
		{
			if (ft_strcmp(file_name + j, str) == 0)
				return (0);
		}
		j++;
	}
	return (printf("Error\nFile extension is not <.ber>!\n"), 1);
}

/*
Function to check if my <.ber > exists
*/

int	ft_try_to_open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nCould not open file!\n"), 1);
	close (fd);
	return (0);
}

/*
Function to verify if the <.xpm > files exist
*/

int	ft_try_to_open_xpm(void)
{
	int	fd_1;
	int	fd_2;
	int	fd_3;
	int	fd_4;
	int	fd_5;

	fd_1 = open(ITEMS_IM, O_RDONLY);
	fd_2 = open(PLAYER_IM, O_RDONLY);
	fd_3 = open(EXIT_IM, O_RDONLY);
	fd_4 = open(EMPTY_IM, O_RDONLY);
	fd_5 = open(WALLS_IM, O_RDONLY);
	if (fd_1 < 0 || fd_2 < 0 || fd_3 < 0 || fd_4 < 0 || fd_5 < 0)
		return (printf("Error\nCould not open <xpm> file!\n"), 1);
	close (fd_1);
	close (fd_2);
	close (fd_3);
	close (fd_4);
	close (fd_5);
	return (0);
}

int	ft_check_all_errors_file_name(char *file_name)
{
	if (ft_check_file_name(file_name, ft_len(file_name), ".ber", 0) == 1)
		return (1);
	if (ft_try_to_open_file(file_name) == 1)
		return (1);
	if (ft_try_to_open_xpm() == 1)
		return (1);
	return (0);
}
