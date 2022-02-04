int	ft_check_walls(char **tab, size) //on lui envoie la map recomposée et sa taille (renvoyée par ft_recup_map_size)
{
	int	len;
	int	i;

	i = 0;
	while (tab)
	{
		while (tab[0])
		{
			if (tab[0][i] == '1')
				i++;
			else
				return ("there is a problem with your map");
		}
		i = 0;
		while (tab[len - 1])
		{
			if (tab[len][i] == '1')
				i++;
			else
				return ("there is a problem with your map");
		}
		i = 0;
		while (tab)
		{
			if (tab[0][i] == '1')
				tab++;
			else
				return ("there is a problem with your map");
			if (tab[0][len - 1] == 1)
				tab++;
			else
				return ("there is a problem with your map");
		}
	}
}