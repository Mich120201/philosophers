/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:32:36 by mvolpi            #+#    #+#             */
/*   Updated: 2022/09/28 10:25:04 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_file/philo.h"

static void	isnumber(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == ' ')
				j++;
			else if (ft_isdigit(av[i][j]) == FALSE)
			{
				ft_printf("\033[0;31m" "Error: '%c' is not a number\n" \
						"\033[0m", av[i][j]);
				exit (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

static void	missing_argc(int ac)
{
	if (ac < 5)
	{
		if (ac < 2 || ac == 2 || ac == 3 || ac == 4)
		{
			if (ac < 2)
				ft_printf("\033[0;31m" "Error!!\n" \
				"number of philosophers: missing\n" \
				"time to die: missing\n" "time to eat: missing\n" \
				"time to sleep; missing\n" "\033[0m");
			if (ac == 2)
				ft_printf("\033[0;31m" "Error!!\n" "time_to_die: missing\n" \
					"time_to_eat: missing\n" "time_to_sleep; missing\n" "\033[0m");
			if (ac == 3)
				ft_printf("\033[0;31m" "Error!!\n" "time_to_eat: missing\n"\
					"time_to_sleep; missing\n" "\033[0m");
			if (ac == 4)
				ft_printf("\033[0;31m" "Error!!\n" "time_to_sleep; missing\n" \
					"\033[0m");
		}
	}
}

void	errors(int ac, char **av)
{
	int		i;
	char	**str;

	i = 0;
	missing_argc(ac);
	while (++i < ac)
	{
		str = ft_split(av[i], ' ');
		isnumber(str);
	}
	if (ac == 5)
		ft_printf("\033[0;32m" \
				"if you want, you can add one more parameter:" \
				" number of times each philosopher must eat\n"\
				"\033[0m");
}